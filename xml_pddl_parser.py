from typing import TextIO

from sklearn.feature_selection import f_regression
from model import *

args_names = "xyzabcdefgh"

def set_actions_tension(actions: List[Action], tension: Dict) -> List[Action]:
    return [Action(a.name, a.params, a.preconditions, a.effects, tension[a.name]) for a in actions]

def parse_xml(filename):
    tree = ET.parse(filename)
    root = tree.getroot()

    objects = []
    facts = []
    actions = []
    predicates = []
    tension = {}

    for child in root:
        for elem in child:
            attrs = elem.attrib
            if child.tag == "objects":
                objects.append(Object(attrs['name'], attrs['type']))
            elif child.tag == "relations":
                name = attrs['name']
                object_names = []
                for param in elem:
                    object_names.append(param.attrib['value'])
                facts.append(Fact(name, object_names))
            elif child.tag == "operators":
                action_name = attrs['name']
                params = []
                conditions = []
                effects = []
                for property in elem: 
                    if property.tag == "parameters":
                        for parameter in property:
                            params.append(Object(parameter.attrib["name"], parameter.attrib["type"]))
                    elif property.tag == "preconditions":
                        for precondition in property:
                            name = precondition.attrib['predicate']
                            negated = True if 'negation' in precondition.attrib else False
                            object_names = []
                            for param in precondition:
                                object_names.append(param.attrib['name'])
                            conditions.append(Fact(name, object_names, negated))
                    elif property.tag == "effects":
                        for effect in property:
                            name = effect.attrib['predicate']
                            negated = True if 'negation' in effect.attrib else False
                            object_names = []
                            for param in effect:
                                object_names.append(param.attrib['name'])
                            effects.append(Fact(name, object_names, negated))
                actions.append(Action(action_name, params, conditions, effects, 0))
            elif child.tag == "eventeffects":
                tension[attrs['name']] = TS_VALUES[attrs['tension']]
            elif child.tag == "predicates":
                name = attrs['name']
                initialstate = True if attrs['initialstate'] == "true" else False
                goalstate = True if attrs['goalstate'] == "true" else False
                oposite = attrs['oposite'] if 'oposite' in attrs else None
                params = []
                for param in elem:
                    unique = True if 'unique' in param.attrib else False
                    params.append(Parameter(param.attrib['type'], unique))
                pred = Predicate(name, initialstate, goalstate, params)
                if oposite:
                    pred.oposite = oposite
                predicates.append(pred)
                
    actions = set_actions_tension(actions, tension)
    return World(objects, facts, actions, predicates)

def get_grouped_objects(objects: List[Object]):
    grouped = {}
    for o in objects:
        if o.type in grouped:
            grouped[o.type].append(o.name)
        else:
            grouped[o.type] = [o.name]
    return grouped

def write_facts(facts: List[Fact], f: TextIO):
    for i, fact in enumerate(facts):
        if fact.is_negated:
            f.write("(not ")
        f.write(f"({fact.name}")
        for arg in fact.arguments:
            f.write(f" ?{arg}")
        f.write(")")
        if fact.is_negated:
            f.write(")")
        if i != len(facts)-1:
            f.write("\n\t\t\t\t\t")
        else:
            f.write(")")

def write_state_facts(facts: List[Fact], f: TextIO):
    for i, fact in enumerate(facts):
        if fact.is_negated:
            f.write("(not ")
        f.write(f"({fact.name}")
        for arg in fact.arguments:
            f.write(f" {arg}")
        f.write(")")
        if fact.is_negated:
            f.write(")")
        if i != len(facts)-1:
            f.write("\n\t\t")
        else:
            f.write(")")

def write_object_grouped(grouped_objects: Dict[str, str], f: TextIO):
    for object_type in grouped_objects:
            for object in grouped_objects[object_type]:
                f.write(f"({object_type} {object})\n\t\t")

def generate_domain(world: World, name: str = "zombie"):
    with open(f"./{name}/{name}.pddl", "w") as file:
        file.write(f"(define (domain {name})\n\t(:requirements :strips)\n")
        file.write(f"\t(:predicates\n")

        types = set([o.type for o in world.objects])
        for type in types:
            file.write(f"\t\t({type} ?x)\n")
        
        unique_fact_names = []
        predicates_arity = []
        for p in world.predicates:
            if p.name not in unique_fact_names:
                predicates_arity.append((p.name, len(p.parameters)))
                unique_fact_names.append(p.name)
        for f in world.facts:
            if f.name not in unique_fact_names:
                predicates_arity.append((f.name, len(f.arguments)))
                unique_fact_names.append(f.name)
        predicates_arity += [("starving", 1), ("knowneed", 3)]
        print(predicates_arity)

        for pred, arity in predicates_arity:
            file.write(f"\n\t\t({pred}")
            for i in range(arity):
                file.write(f" ?{args_names[i]}")
            file.write(")")
        file.write(")")

        for action in world.actions:
            file.write(f"\n\t\t(:action {action.name}")
            file.write(f"\n\t\t:parameters (")
            for param in action.params:
                file.write(f" ?{param.name}")
            file.write(")")
            file.write(f"\n\t\t:precondition (and\t")
            for param in action.params:
                file.write(f"({param.type} ?{param.name})\n\t\t\t\t\t")
            write_facts(action.preconditions, file)
            file.write(f"\n\t\t:effect (and\t\t")
            write_facts(action.effects, file)
            file.write(")")
        file.write(")")

def generate_problem(individual: Individual, world: World, name: str = "zombie"):
    with open(f"./{name}/problem.pddl", "w") as file:
        file.write(f"(define (problem {name}_1)\n")
        file.write(f"\t(:domain {name})\n")
        file.write("\t(:objects")
        grouped_objects = get_grouped_objects(world.objects)
        for object_type in grouped_objects:
            for object in grouped_objects[object_type]:
                file.write(f" {object}")
            file.write("\n\t")
        file.write(")")
        file.write(f"\n\t(:init\t")
        write_object_grouped(grouped_objects, file) 
        write_state_facts(individual.initial_state, file)
        file.write(f"\n\n\t(:goal (and\t")
        write_state_facts(individual.goal_state, file)
        file.write("))")

world = parse_xml("quest_db.xml")
print(world.actions)
paths = [f for f in world.facts if f.name in ["path", "open"]]
types = [f for f in world.facts if f.name.startswith("is")]
test = [Fact("at", ["john", "forest"]), Fact("at", ["antidote2", "hospital"]), Fact("at", ["food3", "hospital"]), Fact("at", ["john", "island"]), Fact("healthy", ["john"]), Fact("infected", ['john'])]
# print(validate_facts(world, test, 2))
init = world.facts + [Fact("infected", ["anne"])]#paths + types + [Fact("at", ["john", "johnhouse"]), Fact("alive", ["john"]), Fact("infected", ["john"])]
goal = [Fact("at", ["john", "hospital"]), Fact("cured", ["anne"]), Fact("has", ["john", "food3"])]
generate_domain(world)
ind = Individual(len(init), init, 0, goal)
generate_problem(ind, world)
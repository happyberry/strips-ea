from dataclasses import dataclass
from typing import Dict, List, Optional
import xml.etree.ElementTree as ET

TS_VALUES = {
    "+": 1,
    "=": 0,
    "-": -1
}

@dataclass
class Object: # object in xml
    name: str
    type: str

@dataclass
class Parameter: # predicate's parameter
    type: str
    is_unique: bool

@dataclass
class Predicate: # object in xml
    name: str
    initialstate: bool
    goalstate: bool
    parameters: List[Parameter]
    oposite: Optional[str] = None

@dataclass
class Fact: # relations in xml
    name: str
    arguments: List[str]

@dataclass
class Action: # operators, eventeffects in xml
    name: str
    params: List[Object]
    preconditions: List[Fact]
    effects: List[Fact]
    tension: int

@dataclass
class World:
    objects: List[Object]
    facts: List[Fact]
    actions: List[Action]
    predicates: List[Predicate]

def get_type(objects: List[Object], name: str) -> str:
    for o in objects:
        if o.name == name:
            return o.type
    return "unknown"

def get_facts(fact_list: List[Fact], name: str, required_argument: str) -> List[Fact]:
    print(fact_list, name, required_argument)
    list = [f for f in fact_list if f.name == name and required_argument in f.arguments]
    print(list)
    return list

def get_related(preds: List[Predicate], name: str):
    return [pred for pred in preds if pred.name == name]

def types_equall(parameters_left, parameters_right):
    counter = 0
    for pred_param, fact_param in zip(parameters_left, parameters_right):
        if pred_param.type == get_type(world.objects, fact_param):
            counter+=1
        if counter == len(parameters_left):
            return True
    return False
        

def validate_facts(world: World, facts: List[Fact], init_length: int) -> List[Fact]:
    is_goal = init_length == -1
    end_index = len(facts)-1 if is_goal else len(facts) - init_length - 1
    print("end_ind", end_index)
    invalid_facts = []
    types_validated = False
    for index, fact in enumerate(facts[::-1]):
        related_predicates = get_related(world.predicates, fact.name)
        for pred in related_predicates:
            if len(pred.parameters) != len(fact.arguments):
                print("diff_lengths")
                invalid_facts.append(len(facts) - index - 1)
                break
            if types_equall(pred.parameters, fact.arguments):
                types_validated = True
            if not pred.initialstate and not is_goal:
                print("invalid as initstate")
                invalid_facts.append(len(facts) - index - 1)
                break
        if not types_validated:
            print("diff_param_type")
            invalid_facts.append(len(facts) - index - 1)
        if index >= end_index or len(facts) - index - 1 in invalid_facts:
            continue
        for pred in related_predicates:
            if not types_equall(pred.parameters, fact.arguments):
                continue
            if not pred.goalstate and is_goal:
                print("invalid as goalstate")
                invalid_facts.append(len(facts) - index - 1)
                break
            if len(fact.arguments) == 1:
                if pred.oposite and len(get_facts(facts[:len(facts)-index-1], pred.oposite, fact.arguments[0])) > 0:
                    print("oposite")
                    invalid_facts.append(len(facts) - index - 1)
                    break
            for pred_param, fact_param in zip(pred.parameters, fact.arguments):
                print(pred_param.is_unique)
                if pred_param.is_unique and len(get_facts(facts[:len(facts)-index-1], pred.name, fact_param)) > 0:
                    print("not unique")
                    invalid_facts.append(len(facts) - index - 1)
                    break
    print(invalid_facts)
    for i in invalid_facts:
        del facts[i]
    return facts

        

class Individual:
    init_length: int
    initial_state: List[Fact]
    goal: List[Fact]

    def repair(self):
        pass

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
                            object_names = []
                            for param in precondition:
                                object_names.append(param.attrib['name'])
                            conditions.append(Fact(name, object_names))
                    elif property.tag == "effects":
                        for effect in property:
                            name = effect.attrib['predicate']
                            object_names = []
                            for param in effect:
                                object_names.append(param.attrib['name'])
                            effects.append(Fact(name, object_names))
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
                
    print(facts)
    actions = set_actions_tension(actions, tension)
    return World(objects, facts, actions, predicates)

world = parse_xml("quest_db.xml")
test = [Fact("at", ["john", "forest"]), Fact("at", ["john", "island"]), Fact("healthy", ["john"]), Fact("infected", ['john'])]
print(validate_facts(world, test, 2))
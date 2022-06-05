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
class Predicate: # predicates in xml
    name: str
    initialstate: bool
    goalstate: bool
    parameters: List[Parameter]
    oposite: Optional[str] = None

@dataclass
class Fact: # relations in xml
    name: str
    arguments: List[str]
    is_negated: bool = False

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

def types_equall(objects: List[Object], parameters_left, parameters_right):
    counter = 0
    for pred_param, fact_param in zip(parameters_left, parameters_right):
        if pred_param.type == get_type(objects, fact_param):
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
            if types_equall(world.objects, pred.parameters, fact.arguments):
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
            if not types_equall(world.objects, pred.parameters, fact.arguments):
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
                if pred_param.is_unique and len(get_facts(facts[:len(facts)-index-1], pred.name, fact_param)) > 0:
                    print("not unique")
                    invalid_facts.append(len(facts) - index - 1)
                    break
    print(invalid_facts)
    for i in invalid_facts:
        del facts[i]
    return facts

        
@dataclass
class Individual:
    init_length: int
    initial_state: List[Fact]
    goal_init_length: int
    goal_state: List[Fact]
    tension: List[int] = None

    def repair(self):
        pass

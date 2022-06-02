

import random
from typing import List

from model import *
from xml_pddl_parser import get_grouped_objects, parse_xml

POPULATION_SIZE = 10
INIT_ADDITIONAL_FACTS_MAX_SIZE = 1
GOAL_ADDITIONAL_FACTS_MAX_SIZE = 5

def generate_random_individual(world: World, initial_state: List[Fact], expected_goal: List[Fact]) -> Individual:
    init_length = len(initial_state)
    goal_length = len(expected_goal)
    goal_predicates = [p for p in world.predicates if p.goalstate]
    grouped_objects = get_grouped_objects(world.objects)
    for _ in range(INIT_ADDITIONAL_FACTS_MAX_SIZE):
        pred = world.predicates[random.randint(0, len(world.predicates)-1)]
        new_fact = Fact(pred.name, [])
        for param in pred.parameters:
            params_of_type = grouped_objects[param.type]
            param_value = params_of_type[random.randint(0, len(params_of_type)-1)]
            new_fact.arguments.append(param_value)
        initial_state.append(new_fact)
    for _ in range(GOAL_ADDITIONAL_FACTS_MAX_SIZE):
        pred = goal_predicates[random.randint(0, len(goal_predicates)-1)]
        new_fact = Fact(pred.name, [])
        for param in pred.parameters:
            params_of_type = grouped_objects[param.type]
            param_value = params_of_type[random.randint(0, len(params_of_type)-1)]
            new_fact.arguments.append(param_value)
        expected_goal.append(new_fact)
    initial_state = validate_facts(world, initial_state, init_length)
    expected_goal = validate_facts(world, expected_goal, goal_length)
    return Individual(init_length, initial_state, goal_length, expected_goal)
        

def initialize_population(world: World, initial_state: List[Fact] = [], expected_goal: List[Fact] = []) -> List[Individual]:
    return [generate_random_individual(world, initial_state, expected_goal) for _ in POPULATION_SIZE]

def mutation(individual: Individual) -> Individual:
    pass

def crossover(individual_left: Individual, individual_right: Individual) -> Individual:
    pass

def selection(population: List[Individual]) -> List[Individual]:
    pass

def next_generation(population: List[Individual]) -> List[Individual]:
    pass

def get_fitness(individual: Individual, tension_pattern = List[int]) -> float:
    pass

world = parse_xml("quest_db.xml")
ind = generate_random_individual(world, world.facts, [])
print(ind)
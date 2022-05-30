

from typing import List

from model import *

POPULATION_SIZE = 10

def generate_random_individual(world: World, initial_state: List[Fact] = [], expected_goal: List[Fact] = []) -> Individual:
    pass

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
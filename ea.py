import itertools
import random
from typing import List, Tuple 

from model import *
from xml_pddl_parser import get_grouped_objects, parse_xml
from utils import scale_tension

POPULATION_SIZE = 50
ELITE_PART = 0.5
TENSION_PATTERN = [1,2,3,2]
INIT_ADDITIONAL_FACTS_MAX_SIZE = 2
GOAL_ADDITIONAL_FACTS_MAX_SIZE = 3
MUTATION_PROB = 0.2


def generate_random_individual(world: World, initial_state: List[Fact], expected_goal: List[Fact]) -> Individual:
    """
    Generates new individual based on given world definition and optional required facts 
    for init and goal state. Additional facts are generated randomly.
    Number of additional facts in init state is limited to INIT_ADDITIONAL_FACTS_MAX_SIZE,
    same goes for goal state and GOAL_ADDITIONAL_FACTS_MAX_SIZE const
    """
    init_length = len(initial_state)
    goal_length = len(expected_goal)
    goal_predicates = [p for p in world.predicates if p.goalstate]
    grouped_objects = get_grouped_objects(world.objects)
    
    generate_goal = True
    while generate_goal:
        _expected_goal = expected_goal[:]   
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
            _expected_goal.append(new_fact)
        generate_goal = False
        for goal in _expected_goal:
            for init_state in initial_state: # n^2 complexity :(
                if goal.name == init_state.name and set(goal.arguments) == set(init_state.arguments):
                    generate_goal = True
    initial_state = validate_facts(world, initial_state, init_length)
    expected_goal = validate_facts(world, expected_goal, goal_length)
    return Individual(init_length, initial_state, goal_length, _expected_goal)
        
def initialize_population(world: World, initial_state: List[Fact] = [], expected_goal: List[Fact] = []) -> List[Individual]:
    """
    Returns population (list of Individuals) of given POPULATION_SIZE
    """
    return [generate_random_individual(world, initial_state, expected_goal) for _ in range(POPULATION_SIZE)]

def mutation(world: World, individual: Individual) -> Individual:
    """
    Given probability MUTATION_PROB a random delete or add random
    fact in init and/or goal state is performed
    """
    do_mutatation = random.random() <= MUTATION_PROB
    if not do_mutatation:
        return individual
    
    mutation_target = random.choice(["init", "goal"])
    mutation_type = random.choice(["add", "remove"])
    if mutation_type == "add":
        goal_predicates = [p for p in world.predicates if p.goalstate]
        grouped_objects = get_grouped_objects(world.objects)
        
        if mutation_target == "init":
            pred = world.predicates[random.randint(0, len(world.predicates)-1)]
            new_fact = Fact(pred.name, [])
            for param in pred.parameters:
                params_of_type = grouped_objects[param.type]
                param_value = params_of_type[random.randint(0, len(params_of_type)-1)]
                new_fact.arguments.append(param_value)
            individual.initial_state.append(new_fact)
        else:
            pred = goal_predicates[random.randint(0, len(goal_predicates)-1)]
            new_fact = Fact(pred.name, [])
            for param in pred.parameters:
                params_of_type = grouped_objects[param.type]
                param_value = params_of_type[random.randint(0, len(params_of_type)-1)]
                new_fact.arguments.append(param_value)
            individual.goal_state.append(new_fact)
    
    else:
        if mutation_target == "init" and len(individual.initial_state) != 0:
            index = random.randint(0, len(individual.initial_state) - 1)
            del individual.initial_state[index]
        if mutation_target == "remove" and len(individual.goal_state != 0):
            index = random.randint(0, len(individual.goal_state) - 1)
            del individual.goal_state[index]
    return individual

def crossover(parents: Tuple[Individual, Individual]) -> Individual:
    """
    Returns child individual produced by crossing non-essential parts
    of init and goal state of parent individuals
    Order of parents is determined randomly
    """
    first, second = parents
    init_length = first.init_length
    goal_length = first.goal_init_length
    use_first_half_from_first = random.randrange(2) == 0
    num_bits_init = min(len(first.initial_state), len(second.initial_state))
    num_bits_goal = min(len(first.goal_state), len(second.goal_state))
    crossover_point_init = random.randint(init_length, num_bits_init - 1)
    crossover_point_goal = random.randint(goal_length, num_bits_goal - 1)
    if use_first_half_from_first:
        first, second = second, first
    child_genes_init = first.initial_state[:crossover_point_init] + second.initial_state[crossover_point_init:]
    child_genes_goal = first.goal_state[:crossover_point_goal] + second.goal_state[crossover_point_goal:]
        
    
    return Individual(init_length, child_genes_init, goal_length, child_genes_goal)

def selection(previous_population: List[Individual], roulette_probabilities: List[float]) -> List[Individual]:
    """
    Returns pair sampled from 'distribution' determined by roulette_probabilites 
    (disclaimer: roulette_probabilites holds accumulated probabilities)
    """
    pair = []
    for _ in range(2):
        probability = random.random()
        for i, cutoff in enumerate(roulette_probabilities):
            if probability < cutoff:
                pair.append(previous_population[i])
                break
    return tuple(pair)

def select_elite(previous_population, prev_pop_fitness):
    """"
    Returns ELITE_PART part of population sorted ascending by fitness
    """
    fitness = sorted(prev_pop_fitness)
    cutoff_value = fitness[round(len(fitness) * ELITE_PART)]
    best_parents = []

    for i in range(len(previous_population)):

        if prev_pop_fitness[i] < cutoff_value:
            best_parents.append(previous_population[i])

    return best_parents

def get_fitness(individual: Individual, tension_pattern = List[int]) -> float:
    """
    Warning!!! -- indv tension is scaled to length of tension_pattern
    """
    if not individual.actions_from_planner:
        return 1000 #NO SOLUTION
    tensions = individual.get_tensions()
    scaled_tensions = scale_tension(tensions, len(tension_pattern))

    mse = (sum([(scaled_tensions[i] - tension_pattern[i])**2
                for i in range(len(tension_pattern))])/len(tension_pattern))
    return len(individual.actions_from_planner)/mse

def calculate_fitness_stats(population, fitness_values):
    """
    Returns bunch of information based on fitness scores of population:
    - list of accumulated probabilities for roulette selection
    - best individual 
    - best individual fitness
    - average fitness of population
    """
    best_fitness = min(fitness_values)
    best_individual = population[fitness_values.index(best_fitness)]
    total_score = sum(fitness_values)
    average_fitness = total_score / len(fitness_values)

    fitness_ratios = []

    total_score = abs(sum(fitness_values) - 1000*len(fitness_values))
    for score in fitness_values:
        fixed_score = 1000 - score #minimization problem
        ratio = fixed_score / total_score
        fitness_ratios.append(ratio)

    roulette_probabilities = list(itertools.accumulate(fitness_ratios))
    return roulette_probabilities, best_individual, best_fitness, average_fitness

def next_generation(previous_population: List[Individual],
                    fitness_values: List[float],
                    world: World) -> List[Individual]:
    """
    Returns next generation based on previous generation fitness scores
    New population is constructed with elitism and roulette selection
    """
    roulette_probabilities, best_individual, best_fitness, average_fitness = calculate_fitness_stats(
        previous_population, fitness_values)

    child_population = []
    best_parents = select_elite(previous_population, fitness_values)

    # Create a child population the same size as the parent population
    for _ in range(POPULATION_SIZE - len(best_parents)):
        selected_pair = selection(previous_population, roulette_probabilities)
        child = crossover(selected_pair)
        child = mutation(world, child)
        child_population.append(child)

    child_population = child_population + best_parents
    return child_population, best_individual, best_fitness, average_fitness

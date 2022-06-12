from ea import get_fitness, initialize_population, next_generation
from utils import config_planner, read_actions_from_planner, run_hsp_planner
from xml_pddl_parser import generate_domain, generate_problem, parse_xml


POPULATION_SIZE = 20
GENERATIONS = 10
ELITE_PART = 0.5
TENSION_PATTERN = [1,2,3,2]
INIT_ADDITIONAL_FACTS_MAX_SIZE = 10
GOAL_ADDITIONAL_FACTS_MAX_SIZE = 10 

if __name__ == "__main__":
    world = parse_xml("quest_db.xml")
    initial_state = world.facts
    expected_goal = []
    print(*[f"Generation", "max (of generation)", "avg (of generation)"], sep='\t')
    population = initialize_population(world, initial_state, expected_goal)
    generate_domain(world)
    for i in range(GENERATIONS):
        for i,ind in enumerate(population):
            generate_problem(ind, world, i)
        config_planner(len(population))
        run_hsp_planner("./zombie")
        population = read_actions_from_planner("./zombie/solutions.all", world.actions, population)
        fitness_scores = [get_fitness(ind, TENSION_PATTERN) for ind in population]
        new_generation, best_individual, best_fitness, average_fitness = next_generation(population, fitness_scores)
        print(*[f"Generation: {i}", round(best_fitness, 2), round(average_fitness, 2)], sep='\t\t')
        with open("Generations.txt", "a+") as file:
            file.write(f"Generation {i}\n")
            file.write(f"Best Individual (init): {best_individual.initial_state}\n")
            file.write(f"Best Individual (goal): {best_individual.goal_state}\n")
            file.write(f"Best Individual (actions): {best_individual.actions_from_planner}\n")
            # TODO: get list of actions, return it with fitness and write it here
            file.write(f"Best Fitness: {best_fitness}\n")
            file.write(f"Average Fitness: {average_fitness}\n")
            file.write("\n")
        population = new_generation[:]
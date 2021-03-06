from ea import get_fitness, initialize_population, next_generation
from model import Fact
from utils import config_planner, read_actions_from_planner, run_hsp_planner, scale_tension
from xml_pddl_parser import generate_domain, generate_problem, parse_xml


GENERATIONS = 20
TENSION_PATTERN = scale_tension([1,2,3,2], 10)
 
if __name__ == "__main__":
    world = parse_xml("quest_db.xml")
    initial_state = world.facts
    expected_goal = []
    print(*[f"Generation", "max (of generation)", "avg (of generation)"], sep='\t')
    population = initialize_population(world, initial_state, expected_goal)
    generate_domain(world)
    for i in range(GENERATIONS):
        for j,ind in enumerate(population):
            generate_problem(ind, world, j)
        config_planner(len(population))
        run_hsp_planner("./zombie")
        population = read_actions_from_planner("./zombie/solutions.all", world.actions, population)
        fitness_scores = [get_fitness(ind, TENSION_PATTERN) for ind in population]
        new_generation, best_individual, best_fitness, average_fitness = next_generation(population, fitness_scores, world)
        print(*[f"Generation: {i}", round(best_fitness, 2), round(average_fitness, 2)], sep='\t\t')
        with open("Generations.txt", "a+") as file:
            file.write(f"Generation {i}\n")
            file.write(f"Best Individual (init): {best_individual.initial_state}\n\n")
            file.write(f"Best Individual (goal): {best_individual.goal_state}\n")
            #file.write(f"Best Individual (actions): {best_individual.actions_from_planner}\n")
            for action in best_individual.actions_from_planner:
                params = [param.name for param in action.params]
                text = (action.name + " " + " ".join(params)).upper()
                file.write(f"{text}\n")
            file.write(f"Best Fitness: {best_fitness}\n")
            file.write(f"Average Fitness: {average_fitness}\n")
            file.write("\n")
        population = new_generation[:]
    print(*[f"Generation: {i}", round(best_fitness, 2), round(average_fitness, 2)], sep='\t\t')
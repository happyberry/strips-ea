import re
from typing import List
from model import Individual, Action


def get_tensions(solutions_path: str,
                 actions: List[Action],
                 population: List[Individual]) -> List[Individual]:
    """
    Read planner output ("solutions.all") and get tensions for equivalent individual
    """
    actions_tension = {action.name: action.tension for action in actions}
    indv_idx = 0
    indv_tension = [0]
    with open(solutions_path) as solutions:
        for i, line in enumerate(solutions):
            process_line = re.sub("[()]","", line.lower()).split(" ")
            if i == 0:
                continue #read zombie1 and pass;
            if process_line[0] == f"zombie{indv_idx + 2}\n":
                population[indv_idx].tension = indv_tension[1:]
                indv_tension = [0]
                indv_idx += 1
            if process_line[0] in actions_tension.keys():
                readed_tension = actions_tension[process_line[0]]
                new_tension = indv_tension[-1] + readed_tension
                indv_tension.append(new_tension)
    population[indv_idx].tension = indv_tension[1:] #handle last pop

    return population


def scale_tension(tension: List[int], interval: int) -> List[int]:
    """
    Scaled tension to list of length interval
    """
    return [tension[int(round(
            (((i - 1)/interval)*(len(tension)-1))+1))]
            for i in range(interval)]

if __name__ == "__main__":
    from xml_pddl_parser import parse_xml, generate_domain
    from model import Fact
    world = parse_xml("quest_db.xml")
    init = world.facts + [Fact("infected", ["anne"])]#paths + types + [Fact("at", ["john", "johnhouse"]), Fact("alive", ["john"]), Fact("infected", ["john"])]
    goal = [Fact("at", ["john", "hospital"]), Fact("cured", ["anne"]), Fact("has", ["john", "food3"])]
    generate_domain(world)
    ind1 = Individual(len(init), init, 0, goal)
    ind2 = Individual(len(init), init, 0, goal)
    pop = [ind1, ind2]
    test = get_tensions("./hsp/pddl/ferry/solutions.all", world.actions, pop)
    print(test[0].tension)
    print(test[1].tension)
    from ea import get_fitness
    tension_pattern = scale_tension([1,2,3,2],10)
    print(get_fitness(test[0],tension_pattern))
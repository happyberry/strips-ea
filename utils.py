import re
import os
from typing import List
from model import Action, Individual 

HSPHOME = os.path.abspath("./hsp")

def run_hsp_planner(dir_path: str) -> None:
    """
    Run hsp planner, hsp saves result in solutions.all file 
    """
    dir_path = os.path.abspath(dir_path)
    os.system(f"export HSPHOME={HSPHOME}; cd $HSPHOME; make compile; cd {dir_path}; make compile; make solve")

def config_planner(pop_size:int,
                   problems_path: str = "zombie/PROBLEMS",
                   domain: str = "zombie") -> None:
    with open(problems_path, "w") as file:
        for i in range(pop_size):
            file.write(f"problem{i}.pddl {domain}.pddl \n")


def read_actions_from_planner(solutions_path: str,
                 actions: List[Action],
                 population: List[Individual]) -> List[Individual]:
    """
    Read planner solutions as list of actions
    """
    actions_dict = {action.name: action for action in actions}
    indv_idx = 0
    indv_actions = []
    with open(solutions_path) as solutions:
        for i, line in enumerate(solutions):
            process_line = re.sub("[()]","", line.lower()).strip("\n").split(" ")  
            if i!= 0 and re.match(r"^zombie_*", process_line[0]):
                population[indv_idx].actions_from_planner = indv_actions
                indv_idx = int(re.findall(r"\d+", process_line[0])[0])
                indv_actions = []
            # if i != 0 and process_line[0] == f"zombie{indv_idx + 1}\n":
            #     population[indv_idx].actions_from_planner = indv_actions
            #     indv_actions = []
            #     indv_idx += 1
            # if line == "NO SOLUTION\n" or line == "()":
            #     indv_actions = []
            #     indv_idx +=1
            if process_line[0] in actions_dict.keys():
                action = actions_dict[process_line[0]]
                for name, param in zip(process_line[1:], action.params):
                    param.name = name.strip("\n")
                indv_actions.append(action)
    if indv_actions:
        population[indv_idx].actions_from_planner = indv_actions #handle last pop

    return population

def scale_tension(tension: List[int], interval: int) -> List[int]:
    """
    Scaled tension to list of length interval
    """
    return [tension[int(round(
                (((i - 1)/interval)*(len(tension)-1))+1)) - 1]
                for i in range(interval)]
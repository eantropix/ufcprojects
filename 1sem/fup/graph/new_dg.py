# NEW DUMB GRAPH PATHFINDER - by Arthur Viana

# Basic idea of the pathfinder:
# 1. Receive info on nodes and distances between them.
# 2. Receive a specific path to be calculated
# 3. Go through the info received and link node to node, whilst adding their distances.
# 4. Print the best possible path, if there is one.


node_list = []
distance = 0


def receiver(node_list):
    current_info = input("Please type two nodes and the distance between them. (E.g: AB5)")
    while current_info != '0':
        reverse_info = current_info[1] + current_info[0] + current_info[2]  # Does the other way of current_info (BA5)
        node_list.append(current_info)
        node_list.append(reverse_info)

def pathfinder(node_list, path, distance):
    for info in node_list:
        if info[0] == path[0]:



receiver(node_list)

path = input("Please type the path you would like to find the distance for. (E.g: AF)")
pathfinder(node_list, path)


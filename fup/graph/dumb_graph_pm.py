info = []  # List where all graph pieces will be added
piece = 'x'  # Global variable. Starts is_valid for the first time


def formatter(string):  # Turns a string separated by whitespaces into a list
    string = string.split(sep=' ')
    return string


def is_valid(piece):
    piece = formatter(piece)
    letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    numbers = '0123456789'

    if piece[0] in letters and piece[1] in letters and piece[2] in numbers:  # If input is correct:
        '''home, target = piece[0], piece[1]  # Variables home and target will be used to see if there's redundancy
        for node in range(0, len(info), 3):
            if (info[node] == target) and (info[node+1] == home):  # If this happens, there is redundancy
                if info[node+2] == piece[2]:  # Then, determine whether distance between nodes is different.
                    print("Redundant piece. Similar has already been added.")
                else:  # In case the distances differ, there's a mistake. User must choose between pieces of graph.
                    print("Invalid piece. Distances between nodes differ from previously inputted information")
                    print("Piece stored in database: ", info[node], info[node+1], info[node+2])
                    print("Current input: ", piece[0], piece[1], piece[2])
                    option = input("Would you like to alter the piece stored in the database to the current one? (Y/N)")
                    if option.lower == 'y':  # If user wants to alter the information:
                        for x in range(3):
                            info[node+x] = piece[x]  # Redundant info gets overwritten by new one
                        print("Piece altered.")
                    else:  # If user doesn't want to alter information:
                        print("Piece kept unaltered. Current input discarded.")
            else:  # If there's no redundancy:'''
        for x in piece:
            info.append(x)
        print("Current piece: ", piece)
        print("Whole graph: ", info)
        return 'x'
    else:  # If input is not correct:
        if piece[0] == '0':
            print("0 detected. Stopping with piece input.")
            return '0'
        elif piece[0] != '0':
            print("Invalid piece. Please try again.")
            return 'x'


def router(route):
    route = formatter(route)
    start, end = route[0], route[1]
    distance = []
    for node in range(0, len(info), 3):
        if info[node] == start:
            distance.append(start)

print("Please type in all pieces of the graph, according to the following example: A B 5. Type 0 to stop inputting.\n")
while piece != '0':
    piece = is_valid(piece)
print(info, '\n')
print("Please type in the origin and destination nodes, according to the following example: D G")

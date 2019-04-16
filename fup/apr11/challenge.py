import random

n = int(input("How big should the vector be? "))
vector = []
positions = [0] * n
for o in range(0, n):
    x = random.randint(0, 10)
    vector += [x]
print("Original: ", vector)

shifts = [0] * n


def insertion_sort(a):
    for i in range(1, len(a)):  # Goes through the whole list
        current_number = a[i]  # current_number receives the number which will be compared to the rest
        k = 0  # Auxiliary variable k, is used for when the right spot is found for current_number
        for j in range(i-1, -2, -1):  # Loop goes from the previous index of current_number, all the way to the start
            k = j  # k must receive j so if the right spot in case j-loop finds the right spot for current_number
            if a[j] > current_number:  # If the number on the previous index is higher than the "current" one:
                a[j+1] = a[j]  # The "current" index receives the previous' index value, so the list is "shifted"
                shifts[j] += 1

            else:
                break  # If it isn't, current_number has found its right spot
        a[k+1] = current_number  # And then current_number is assigned to its position, with help from k


insertion_sort(vector)

print("Sorted: ", vector)
print(shifts)

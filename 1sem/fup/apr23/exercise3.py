# >>> a = [5, 6]
# >>> b = [1, 2]
# >>> c = b + a
# >>> c
# [1, 2, 5, 6]

L = [2, 9, 4, 8, 3, 7, 11, 10, 1, 13]
x = 1
y = 3
print("Item A: ", L[x+1])
print("Item B: ", L[x+2])
print("Item C: ", L[x+y])
print("Item D: ", L[L[x+y]])
print("Item E: ", L[L[0] + L[4]])
print("Item F: ", L[L[L[8]]])

import math

info = input().split(sep=' ')
length = int(info[0])
width = int(info[1])
square_side = int(info[2])
n_squares_length = math.ceil(length / square_side)
n_squares_width = math.ceil(width / square_side)
print(n_squares_length * n_squares_width)

v = [4, 6, -1]
w = [5, -4, -4]
if len(v) == len(w):
    p = 0
    for i in range(0, len(v)):
        p += v[i]*w[i]
    print(p)
else:
    print("Vectors do not have the same length")
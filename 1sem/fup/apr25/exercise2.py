lin = 2
col = 2
m1 = []
m2 = [] 
for i in range(lin):
    w = [0] * col
    x = [0] * col
    m1.append(w)
    m2.append(x)
print("Insira números na matriz")
n_max = 0
for i in range(lin):
    for j in range(col):
        n = int(input("Numero: "))
        if n_max < n:
            n_max = n
        m1[i][j] = n
for i in range(lin):
    for j in range(col):
        m2[i][j] = m1[i][j] * n_max
print(m1)
print(n_max)
print(m2)
print(m1 == m2)
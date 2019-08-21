lin = 2
col = 2
matriz = []
for i in range(lin):
    w = [0] * col
    matriz.append(w)
n_max = 0
print("Insira números na matriz: ")
for i in range(0, 2):
    for j in range(0, 2):
        n = int(input("Número: "))
        if n_max < n:
            n_max = n
        matriz[i][j] = n
print(matriz)
print(n_max)
# NOME: ARTHUR SANTOS VIANA DE OLIVEIRA
# MATRICULA: 470788
# =====================================
ordem = int(input("Digite a ordem da matriz: "))


def preenche_matriz(nome, ordem):
    matriz = []
    print("Matriz ", nome)
    for i in range(ordem):
        linha = []
        for j in range(ordem):
            valor = int(input("Insira o valor da posicao [%d, %d]: " % (i, j)))
            linha.append(valor)
        matriz.append(linha)
    return matriz


def mostra_matriz(matriz):
    for linha in matriz:
        print(linha)


def menor_matriz(a, b):
    matriz = []
    for i in range(ordem):
        linha = []
        for j in range(ordem):
            linha.append(min(a[i][j], b[i][j]))
        matriz.append(linha)
    return matriz


matriz_a = preenche_matriz('a', ordem)
matriz_b = preenche_matriz('b', ordem)
matriz_c = menor_matriz(matriz_a, matriz_b)
print("Matriz A: ")
mostra_matriz(matriz_a)
print('----------')
print("Matriz B: ")
mostra_matriz(matriz_b)
print('----------')
print("Matriz C")
mostra_matriz(matriz_c)

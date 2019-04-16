  # Nome: ARTHUR SANTOS VIANA DE OLIVEIRA - 470788

from math import *
s = [0] * 5
r = [0] * 5
c = [1.2, 0.8, 0.7, 1.1, 0.9]
e = [0] * 5
total_inicial = 0.0
novo_total = 0.0
treinos = ['LEG PRESS', 'ABDUÇÃO', 'ADUÇÃO', 'EXTENSÃO', 'FLEXÃO']

print("Digite abaixo as séries e repetições correspondentes: \n")
for i in range(0, 5):
    print("\n--", treinos[i], "--")
    s[i] = int(input("Séries: "))
    r[i] = int(input("Repetições: "))
    total_inicial += (s[i] * r[i] * c[i])
    e[i] = round((s[i] * r[i] * c[i]), 2)
    print("ESFORÇO DE ", treinos[i], ":", e[i])
total_inicial = round(total_inicial, 2)
print("\n\n-- TREINAMENTO ATUAL --")
print("ESFORÇO ATUAL: ", total_inicial)

opcao = input(("Você deseja (A)umentar ou (D)iminuir? "))
porc = int(input("Em quantos porcento? "))
if opcao == 'a' or opcao == 'A':
    n_porc = abs(porc+100)
elif opcao == 'd' or opcao == 'D':
    n_porc = abs(porc-100)

for i in range(0, 5):
    novo_total += (n_porc*(s[i]*r[i]*c[i])/100)
novo_total = round(novo_total, 2)
print("NOVO ESFORÇO: ", novo_total)

n_e = []
for i in range(0, 5):
    n_e.append((n_porc/100 * e[i]) + e[i])
    print(round(n_e[i], 2))
n_r = r
print(n_s)
for i in range(0, 5):
    n_r = (n_e[i]/c[i])/(s[i])
    print(s[i], "x", n_r[i], treinos[i])

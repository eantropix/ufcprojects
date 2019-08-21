  # Nome: ARTHUR SANTOS VIANA DE OLIVEIRA - 470788

import math
number = int(input("Insira o numero: "))
while number < 0:
    print("Número inválido. Apenas aceitamos números a partir de zero")
    number = int(input("Insira outro número: "))
a1 = number / 2
a1 = math.floor(a1)
a2 = a1 - 1
a3 = a2 - 1
flag = True
for i in range(a3, 1, -1):
    if a1 * a2 * a3 == number:
        print(number, "é um número triangular, composto por", a1, "x", a2, "x", a3)
        flag = False
        break
    else:
        a1 -= 1
        a2 -= 1
        a3 -= 1
if flag:
    print(number, " não é triangular.")
    
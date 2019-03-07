import math

n = float(input())

notas = [100.00, 50.00, 20.00, 10.00, 5.00, 2.00]
moedas = [100, 50, 25, 10, 5, 1]
numero_notas = [0, 0, 0, 0, 0, 0]
numero_moedas = [0.0, 0.0, 0.0, 0.0, 0.0 ,0.0]


def bills(n):
    i = 0
    for i in range(0, 6) :
        numero_notas[i] = n // notas[i]
        n -= numero_notas[i] * notas[i] 
        i += 1
    return(n)

def coins(n):
    n = round(n, 2);
    n *= 100

    for i in range(0, 6):
        if n >= moedas[i]:
            numero_moedas[i] = n // moedas[i]
            n -= numero_moedas[i] * moedas[i]
        i += 1
coins(bills(n))

print("NOTAS:")
for i in range(0, 6):
    print("{0} nota(s) de R$ {1:.2f}".format(int(numero_notas[i]), notas[i]))

print("MOEDAS:")
for i in range(0, 6):
    print("{0} moeda(s) de R$ {1:.2f}".format(int(numero_moedas[i]), (moedas[i] / 100)))
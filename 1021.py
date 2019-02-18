import math

n = 784.13

notas = [100.00, 50.00, 20.00, 10.00, 5.00, 2.00]
moedas = [1, 0.5, 0.25, 0.10, 0.05, 0.01]
numero_notas = [0, 0, 0, 0, 0, 0]
numero_moedas = [0, 0, 0, 0, 0 ,0]


def bills(n):
    i = 0
    for i in range(0, 6) :
        numero_notas[i] = n // notas[i]
        n -= numero_notas[i] * notas[i] 
        i += 1
    return(n)

def coins(n):
    i = 0
    for i in range(0, 6):
        if n > moedas[i]:
            numero_moedas[i] = n / moedas[i]
            numero_moedas[i] = int(numero_moedas[i]
            n -= numero_moedas[i] * moedas[i]
            print(numero_moedas[i])
        else:
            numero_moedas[i] = n // moedas[i]
            n -= numero_moedas[i] * moedas[i]
            print(numero_moedas[i])
        i += 1
coins(bills(n))

print("NOTAS:\n")
for i in range(0, 6):
    print("{} nota(s) de R$ {}\n".format(int(numero_notas[i]), notas[i]))

print("MOEDAS:\n")
for i in range(0, 6):
    print("{} moeda(s) de R$ {}\n".format(int(numero_moedas[i]), moedas[i]))
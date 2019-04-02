
soma_pares = 0
soma_primos = 0
print("Favor inserir dez numeros: ")
for i in range(0, 10):
    num = int(input())
    if num % 2 == 0:
        soma_pares += num

    if num == 2:
        soma_primos += num

    e_primo = True
    for j in range(2, num):
        while e_primo:
            if num == 2:
                soma_primos += num
            if not ((num % j) == 0):
                e_primo = False
            else:
                e_primo = True
    if not e_primo:
        soma_primos += num


print("Soma dos numeros pares: ", soma_pares)
print("Soma dos numeros primos: ", soma_primos)

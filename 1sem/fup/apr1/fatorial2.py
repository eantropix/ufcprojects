num = int(input("Digite um numero: "))

while num > 0:
    i = num - 1
    num2 = num

    while i >= 2:
            num2 *= i
            i -= 1
    print("O fatorial de {} é: {}".format(num, num2))
    num = int(input("Digite um numero: "))

print("Fim")

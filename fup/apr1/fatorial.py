num = int(input("Digite um numero: "))

while num <= 0:
    num = int(input("Esse numero e invalido. Digite outro: "))
i = num - 1
num2 = num
while i >= 2:
    num2 *= i
    i -= 1

print("O fatorial de {} é: {}".format(num, num2))

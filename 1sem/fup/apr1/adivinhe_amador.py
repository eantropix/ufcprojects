import random
n = random.randint(1, 10)

guess = int(input("Bem vindo ao adivinhe amador! Digite números de 1 a 10 para começar:  "))

while guess != n:
    if guess > n:
        guess = int(input("Menos!  "))
    else:
        guess = int(input("Mais!  "))
print("Parabéns, você acertou! O número era ", n)

import random
n = random.randint(1, 10)
hint = True
tries = 0

print("Bem vindo ao adivinhe profissional! Escolha sua dificuldade:  ")
option = int(input("""
1 - Beginner
2 - Hard
3 - Insane
"""))


if option == 1:
    tries = 99999
if option == 2:
    tries = 3
if option == 3:
    tries = 3
    hint = False

print(n)
guess = int(input("Opção escolhida! Tente adivinhar o número: "))

while guess != n and tries > 0:
    if guess < n:
        if hint:
            guess = int(input("Mais!  "))
            tries -= 1
        else:
            guess = int(input("Tente de novo!"))
            tries -= 1
    elif guess > n:
        if hint:
            guess = int(input("Menos!  "))
            tries -= 1
        else:
            guess = int(input("Tente de novo!"))
            tries -= 1
if tries == 0 and guess != n:
    print("Fim de jogo!")
else:
    print("Parabéns!!")

idade = int(input("Digite uma idade: "))
soma_idades = 0
num_idades = 0
while idade != 0:
    if idade < 0:
        idade = int(input("Idade inválida. Digite outra idade: "))
    else:
        soma_idades += idade
        num_idades += 1
        idade = int(input("Digite outra idade: "))
if num_idades > 0:
    media = soma_idades / num_idades
else:
    media = 0
print("Media das idades igual a: %.2f" % media)
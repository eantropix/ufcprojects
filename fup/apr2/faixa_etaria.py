faixa = [0, 0, 0, 0, 0]

soma_idades = 0
num_idades = 0

while num_idades < 8:
    idade = int(input("Digite uma idade: "))
    if idade < 0:
        idade = int(input("Idade inválida. Digite outra idade: "))
    else:
        if idade <= 15:
            faixa[0] += 1
        elif 15 < idade <= 30:
            faixa[1] += 1
        elif 30 < idade <= 45:
            faixa[2] += 1
        elif 45 < idade <= 60:
            faixa[3] += 1
        else:
            faixa[4] += 1
        num_idades += 1 

total = 0
for i in range(0, 5):
    total  += faixa[i]

print("-- Pessoas por faixa etária --")
for i in range(0, 5):
    print(i,"a faixa: ", faixa[i])

porc_primeira = faixa[0] / total * 100
porc_ultima = faixa[4] / total * 100

print("Porcentagem de pessoas da primeira faixa: %.2f %%" % porc_primeira)
print("Porcentagem de pessoas da ultima faixa: %.2f %%"  % porc_ultima)
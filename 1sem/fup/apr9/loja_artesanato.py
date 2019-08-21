salario = 545.00
preco = [0] * 10
qtd = [0] * 10
for i in range(0, 10):
    preco[i] = float(input())
    qtd[i] = int(input())
total_geral = 0
for i in range(0, 10):
    total_vendido = qtd[i] * preco[i]
    print("O item {} foi vendido {} vezes por {}, com total de {}".format(i+1, qtd[i], preco[i], total_vendido))
    total_geral += total_vendido
comissao = total_geral * 5/100
print("O vendedor vendeu {} e receberá {} em comissão.".format(total_geral, comissao))
maior = 0
imaior = 0
for i in range(0, 10):
    if maior < qtd[i]:
        maior = qtd[i]
        imaior = i
print(preco[imaior], maior)
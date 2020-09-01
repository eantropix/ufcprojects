dinheiro = int(input("Digite a quantia para o saque:  "))
print("Vou entregar seu dinheiro em:\n ")
cedulas = [100, 50, 20, 10, 5, 2, 1]
notas = [0, 0, 0, 0, 0, 0, 0]

i = 0
while dinheiro != 0:
	notas[i] = dinheiro // cedulas[i]
	dinheiro -= notas[i] * cedulas[i]
	print("{} notas de {} reais".format(notas[i], cedulas[i]))
	i += 1



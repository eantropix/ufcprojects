print("Digite os valores do triângulo (m): ")
lados = ['A', 'B', 'C']
valores = [0, 0, 0]
for i in range (0,3):
	valores[i] = int(input("Lado {}: ".format(lados[i])))
def heron(a, b, c):
	a = valores[0]
	b = valores[1]
	c = valores[2]
	p = (a + b + c) / 2
	a = (p * (p-a) * (p-b) * (p-c))**0.5
	print("Triângulo tem área de {} metros quadrados".format(a))

heron(valores[0], valores[1], valores[2])


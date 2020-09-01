a = 0
d = 0
x = 0

while a == 0:
	a = int(input("Digite o coeficiente A (diferente de 0): "))
b = int(input("Digite o coeficiente B: "))
c = int(input("Digite o coeficiente C: "))

print("{} menos {} é igual a {}".format(c, b, c-b))
c -= b
print("{} dividido por {} é igual a {}".format(c, a, c/a))
x = c / a
print(x)


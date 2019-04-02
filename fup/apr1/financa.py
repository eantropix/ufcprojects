v = float(input("Qual o custo da viagem? "))
i = float(input("Com quanto começará a investir? "))
m = float(input("Quanto irá depositar por mês? "))
t = 0  # Time in months

while i < v:
    i = i + (m + (i * 0.05))
    t = t + 1
    print("Mes {0} = {1:.2f}".format(t, i))
print("Você conseguiria fazer sua viagem em %d meses" % t)

[a, b, c] = [float(i) for i in input().split()]

delta = b**2 - 4*a*c
x1 = None
x2 = None
if delta < 0 or a == 0:
	print("Impossivel calcular")
else:
	x1 = ((-b) + delta**(1/2)) / (2*a)
	x2 = ((-b) - delta**(1/2)) / (2*a)

if x1 != None and x2 != None:
	print("R1 = %.5f" % x1)
	print("R2 = %.5f" % x2)

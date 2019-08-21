import random
m = []
total = 0
size = int(input("Size? "))
for i in range(size):
	r = random.randint(0, 10)
	n = [r] * size
	m.append(n)
	print(m[i])
	total += m[i][i]
print(total)

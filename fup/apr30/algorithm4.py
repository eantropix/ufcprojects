import random
vector = []
m = []
total = 0

lin = int(input("Number of lines: "))
col = int(input("Number of columns: "))

for i in range(lin):
	n = []

	for j in range(col):
		tmp = random.randint(1, 9)
		n.append(tmp)

	m.append(n)
	print(m[i])

for i in range(col):
	vector.append(random.randint(1, 9))
print(vector)

for i in range(lin):
	for j in range(col):
		total += m[i][j] * vector[i]

print("Total é: ", total)
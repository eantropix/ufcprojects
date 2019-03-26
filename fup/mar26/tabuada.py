num = int(input("Insert a number: "))

while not (1 <= num <= 10):
	num = int(input("Please insert a number between 1 and 10: "))

for i in range(1, 11):
	print(num, "x", i, "=", num*i)

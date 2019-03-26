print("Main Menu: ")
print("1 - Add two numbers")
print("2 - Divide two numbers")
print("3 - Square root of a number")
list_options = [1, 2, 3]
option = int(input())
while option not in list_options:
	print("Invalid option, please insert a valid option")
	option = int(input())
if option == 1:
	a = int(input("Insert the first number: "))
	b = int(input("Insert the second number: "))
	print(a, "+", b, "=", a+b)
if option == 2:
	a = int(input("Insert the first number: "))
	b = int(input("Insert the second number: "))
	print(a, "/", b, "=", a/b)
if option == 3:
	a = int(input("Insert the number: "))
	print("The root of ", a, "is equal to", a**(1/2))
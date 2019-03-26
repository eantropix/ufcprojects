print("Insert the measures of the sides of the triangle: ")
a = int(input())
b = int(input())
c = int(input())
if (a < b + c) and (b < a +c) and (c < a + b):
	print("This triangle is possible")
else:
	print("This triangle is not possible")
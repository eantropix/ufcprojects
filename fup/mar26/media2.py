n1 = float(input("First grade: "))
n2 = float(input("Second grade: "))

avg = (n1 + n2) / 2
if avg >= 7:
	print("You passed!")
elif 4 <= avg < 7:
	print("You must do the Final Exam")
	fe = float(input("Grade of Final Exam: "))
	if ((avg + fe) >= 10):
		print("You passed!")
	else:
		print("You failed...")
else:
	print("You failed...")
w = float(input("Insert your weight: "))
h = float(input("Insert your height: "))

bmi = w / (h * h)
situations = ['underweight', 'normal', 'overweight', 'obese']

condition = "none"

if bmi < 18.5:
	condition = situations[0]
elif bmi < 24.9:
	condition = situations[1]
elif bmi < 29.9:
	condition = situations[2]
else:
	condition = situations[3]
	 
print("Your BMI is {0:.1f} and you are considered {1}".format(bmi, condition))



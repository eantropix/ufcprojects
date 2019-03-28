num = float(input())
open_bracket = '('
close_bracket = ']'
open_number = 0
close_number = 100
if num < 0 or num > 100:
	print("Fora de intervalo")
else:
	if num >= 0 and num <= 25:
		print("Intervalo [0,25]")	
	elif num > 25 and num <= 50:
		print("Intervalo (25,50]")
	elif num > 50 and num <= 75:
		print("Intervalo (50,75]")
	else:
		print("Intervalo (75,100]")
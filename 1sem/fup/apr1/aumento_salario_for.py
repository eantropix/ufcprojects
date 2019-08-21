increase = 1.5/100
currentYear = int(input("Insira o ano em que estamos: "))
initSalary = 1000.00  # initSalary is reserved as a sole variable for easier change to different values
finalSalary = initSalary + increase

for i in range(2007, currentYear+1):
    increase *= 2  # increase doubles every year
    finalSalary += (increase * finalSalary)  # every year, finalSalary receives itself + the increase

print("%.2f" % finalSalary)

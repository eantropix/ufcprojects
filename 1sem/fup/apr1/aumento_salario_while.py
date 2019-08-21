increase = 1.5/100
currentYear = int(input("Insira o ano em que estamos: "))
initYear = 2007
initSalary = 1000.00  # initSalary is reserved as a sole variable for easier change to different values
finalSalary = initSalary + increase

while initYear <= currentYear:
    increase *= 2  # increase doubles every year
    finalSalary += (increase * finalSalary)  # every year, finalSalary receives itself + the increase
    initYear += 1

print("%.2f" % finalSalary)

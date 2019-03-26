initValue = float(input("Insert your salary: "))
perc = float(input("How much will your salary increase in? (%) "))
incValue = initValue * perc/100
print("Your salary will increase in %.2f, for a total of %.2f " % ((incValue), (initValue + incValue)))
# Nome: ARTHUR SANTOS VIANA DE OLIVEIRA - 470788

treinos = ['LEG PRESS', 'ABDUÇÃO', 'ADUÇÃO', 'EXTENSÃO', 'FLEXÃO']  # each type of exercise
s = [0] * 5  # Declaring all the lists of sets and repetitions
r = [0] * 5
c = [1.2, 0.8, 0.7, 1.1, 0.9]  # Effort coefficient of each exercise
e = [0] * 5  # Individual effort of each exercise
total_inicial = 0.0  # Total effort of initial exercise
new_total = 0.0  # New effort that'll be calculated later
n_perc = 0  # Actual percentage that we'll use to calculate the new efforts of each exercise
new_effort = [0.0] * 5  # New individual effort list
no_coef = [0.0] * 5
new_repeats = [0.0] * 5

print("Digite abaixo as séries e repetições correspondentes: \n")
for i in range(0, 5):
    print("\n--", treinos[i], "--")  # Shows each training, for readability
    s[i] = int(input("Séries: "))  # Receives sets from specific training
    r[i] = int(input("Repetições: "))  # Receives repetitions from specific training
    total_inicial += (s[i] * r[i] * c[i])  # Calculates the initial total effort
    e[i] = round((s[i] * r[i] * c[i]), 2)  # Calculates the individual effort of each exercise (and rounds it)
    print("ESFORÇO DE ", treinos[i], ":", e[i])  # Prints individual effort of each exercise
total_inicial = round(total_inicial, 2)  # Rounds initial total effort
print("\n\n-- TREINAMENTO ATUAL --")
print("ESFORÇO ATUAL: ", total_inicial)  # Prints it


opcao = input("Você deseja (A)umentar ou (D)iminuir? ")  # Gets option from user
perc = int(input("Em quantos porcento? "))  # Gets (in-de)crease percentage
if opcao == 'a' or opcao == 'A':  # If it's to increase:
    n_perc = abs(perc+100)  # Value of n_perc is higher than 100%
    for i in range(0, 5):
        new_effort[i] = (n_perc/100 * e[i])  # New effort = previous effort + added percentage
        new_total += new_effort[i]  # Calculates new total effort, from new individual effort of each exercise

if opcao == 'd' or opcao == 'D':  # If it's to decrease:
    n_perc = abs(perc-100)  # Value of n_perc is lower than 100%
    for i in range(0, 5):
        new_effort[i] = (n_perc/100 * e[i])  # New effort = previous effort - removed percentage
        new_total += new_effort[i]  # Calculates new total effort, from new individual effort of each exercise

new_total = round(new_total, 2)  # Rounds new total effort
print("NOVO ESFORÇO TOTAL: ", new_total)  # Prints it

comparison_value = []  # Declares list of efforts from outputted exercise

for i in range(0, 5):
    round(new_effort[i], 2)
    new_repeats[i] = round(((new_effort[i] / c[i]) / s[i]))  # Repeats = (effort / coef) / sets
    # no_coef[i] = new_effort[i] / c[i]  # Effort value without coefficient
    # new_repeats[i] = round(no_coef[i] / s[i])  # Effort value with only the repetitions
    print(s[i], "x", (new_repeats[i]), "de", treinos[i])  # Prints each exercise with altered repetitions
    comparison_value += []




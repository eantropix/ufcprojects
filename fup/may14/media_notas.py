notas = open('notas.txt', 'r')
total = 0
cont = 0
min_nota = 100
max_nota = 0
var = notas.readlines()
for linha in var:
    linha = linha.split()
    for nota in linha:
        nota = int(nota)
        total += nota
        cont += 1
        if nota > max_nota:
            max_nota = nota
        if nota < min_nota:
            min_nota = nota
print("A média é: ", total / cont)
notas.close()
notas = open('notas.txt', 'a')
notas.write("\n\nA maior nota é: {} ".format(max_nota))
notas.write("\nA menor nota é: {} ".format(min_nota))
notas.close()
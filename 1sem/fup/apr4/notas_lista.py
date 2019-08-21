notas = []
nota = 1
print("Insira a nota dos alunos, uma a uma. ")
i = 0
media = 0
n = 0
while nota > 0:
    i += 1
    nota = float(input("Nota do aluno {}: ".format(i))) 
    if nota >= 0:
        notas += [nota]
        media += nota
        n += 1
media = media / n
print("Media da turma: %.2f" % media)

count = 1
for i in notas:
    if 4 <= i < 7:
        print("Aluno {} ficou de AF com média {}".format(count, i))
    count += 1
    

# for i in range(0, 10):
#     notas[i] = float(input("Insira a %dª nota: " % (i+1)))
# print("\n\n")
# for i in range(0, 10):
#     print("Esta é a {}ª nota: {} ".format((i+1), notas[i]))
# for i in notas:
#     print(i, end='\t')
# print('\n')

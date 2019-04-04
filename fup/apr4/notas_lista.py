notas = []
nota = 1
print("Insira a nota dos alunos, uma a uma. ")
i = 0
media = 0
n = 0
while nota > 0:
    i += 1
    nota = int(input("Nota do aluno {}: ".format(i))) 
    if nota >= 0:
        notas += [nota]
        media += nota
        n += 1
media = media / n
print("Media da turma: %.2f" % media)
print(notas)

# for i in range(0, 10):
#     notas[i] = float(input("Insira a %dª nota: " % (i+1)))
# print("\n\n")
# for i in range(0, 10):
#     print("Esta é a {}ª nota: {} ".format((i+1), notas[i]))
# for i in notas:
#     print(i, end='\t')
# print('\n')

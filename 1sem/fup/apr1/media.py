numAlunos = int(input("Digite o numero de alunos da turma: "))
aprovados = 0
reprovados = 0
de_af = 0
mediaGeral = 0.0
for i in range(1, numAlunos+1):
    n1 = float(input("Aluno {} - Nota 1: ".format(i)))
    n2 = float(input("Aluno {} - Nota 2: ".format(i)))
    media = (n1 + 2*n2) / 3
    if media >= 7:
        aprovados += 1
    elif media < 4:
        reprovados += 1
    else:
        de_af += 1
    mediaGeral += media

mediaGeral /= numAlunos
print("Alunos aprovados: ", aprovados)
print("Alunos reprovados: ", reprovados)
print("Alunos de AF: ", de_af)
print("Media da turma: ", mediaGeral)

lin = 3
col = 2
m = []
for i in range(lin):
    w = [0] * col
    m.append(w)
worst_grade = [10.0] * lin
for i in range(lin):
    worst_grade = 11
    print("Insira as notas do Aluno {}".format(i+1))
    for j in range(col):
        m[i][j] = float(input("Nota {}: ".format(j+1)))
    for current_grade in m[i]:
        k = 0
        if worst_grade > current_grade:
            worst_grade = current_grade
    print("Pior nota do Aluno {} : {}".format(i+1, worst_grade))
    print("=================\n")



pessoas = {}
aprovados = {}
reprovados = {}
def get_grades(pessoas, aprovados, reprovados):
    notas = open('notas2.txt', 'r')
    for linha in notas:
        linha = linha.split(" ")
        nome = linha[0]
        nota = linha[1].strip()
        pessoas[nome] = nota
        if float(nota) >= 7.0:
            aprovados[nome] = nota
        else:
            reprovados[nome] = nota
get_grades(pessoas, aprovados, reprovados)

pessoas = sorted(pessoas)
aprovados = sorted(aprovados)
reprovados = sorted(reprovados)
print("Pessoas aprovadas: ")
for pessoa in aprovados:
    print(pessoa)

print("\n\nPessoas reprovadas: ")
for pessoa in reprovados:
    print(pessoa)



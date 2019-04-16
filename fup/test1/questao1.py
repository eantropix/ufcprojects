  # Nome: ARTHUR SANTOS VIANA DE OLIVEIRA - 470788

for i in range(2, 1001):
    cont = 0
    for j in range(1, i):
        if i % j == 0:
            cont += 1
    if cont == 1:
        i = str(i)
        if (i.endswith('3')) or (i.endswith('7')):
            print(i)

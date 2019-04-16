  # Nome: ARTHUR SANTOS VIANA DE OLIVEIRA - 470788

o1 = p1 = b1 = o2 = p2 = b2 = -1
while (o1 < 0 or p1 < 0 or b1 < 0 or o2 < 0 or p2 < 0 or b2 < 0):
    print("Insira as medalhas do países. Números negativos não são aceitos.")
    print("País 1:")
    o1 = int(input("Ouros: "))
    p1 = int(input("Pratas: "))
    b1 = int(input("Bronzes: "))
    print("País 2:")
    o2 = int(input("Ouros: "))
    p2 = int(input("Pratas: "))
    b2 = int(input("Bronzes: "))
    if o1 < 0 or p1 < 0 or b1 < 0 or o2 < 0 or p2 < 0 or b2 < 0:
        print("Uma das entradas foi inválida.")
    print("=============================")
quem_ganhou = True
if o1 == o2 and p1 == p2 and b1 == b2:
    print("Empate")
    quem_ganhou = False

if o1 > o2 and quem_ganhou:
    print("País um venceu")
    quem_ganhou = False
elif o2 > o1 and quem_ganhou:
    print("País dois venceu")
    quem_ganhou = False
elif quem_ganhou:
    if p1 > p2 and quem_ganhou:
        print("País um venceu")
        quem_ganhou = False
    elif p2 > p1 and quem_ganhou:
        print("País dois venceu")
        quem_ganhou = False
    elif quem_ganhou:
        if b1 > b2 and quem_ganhou:
            print("País um venceu")
            quem_ganhou = False
        elif b2 > b1 and quem_ganhou:
            print("País dois venceu")
            quem_ganhou = False
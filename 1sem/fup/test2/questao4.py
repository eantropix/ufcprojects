# NOME: ARTHUR SANTOS VIANA DE OLIVEIRA
# MATRICULA: 470788
# =====================================
frase = input("Digite a palavra/frase para checar: ")


def ajeita_frase(frase):
    frase_ajeitada = frase.replace(' ', '')
    return frase_ajeitada


def inverte_frase(frase_ajeitada):
    frase_invertida = ''
    for i in range(len(frase_ajeitada)-1, -1, -1):
        frase_invertida += frase_ajeitada[i]
    return frase_invertida


def checa_frase(frase, frase_invertida):
    if frase == frase_invertida:
        print("A palavra/frase e palindroma")
    else:
        print("A palavra/frase nao e palindroma")


frase_ajeitada = ajeita_frase(frase)

checa_frase(frase_ajeitada, inverte_frase(frase_ajeitada))
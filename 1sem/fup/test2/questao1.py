# NOME: ARTHUR SANTOS VIANA DE OLIVEIRA
# MATRICULA: 470788
# =====================================
import random

palavras = ['piton', 'jiboia', 'cascavel', 'coral']


def escolhe_palavra(palavras):  # Usa random para pegar palavra aleatoria
    palavra = random.choice(palavras)
    return palavra


def embaralha_palavra(palavra):
    palavra2 = []  # Onde fica a palavra
    for letra in palavra:
        palavra2.append(letra)  # Gerando lista de letras
    nova_palavra = []
    for letra in palavra:
        indice = random.randint(0, len(palavra2))  # Pega indice aleatorio
        nova_palavra.append(palavra2[indice - 1])  # Recebe letra aleatoria de palavra2
        palavra2.pop(indice - 1)  # Remove letra que foi selecionada
    return nova_palavra


def mostra_palavra(palavra_embaralhada):  # Palavra entra como lista de char, sai como string
    print("PALAVRA EMBARALHADA: ", end=' ')
    palavra_conjunta = ''
    for letra in palavra_embaralhada:
        palavra_conjunta += letra
    return palavra_conjunta


def jogo(quer_jogar):  # Funcao main
    while quer_jogar == 1:
        palavra_escolhida = escolhe_palavra(palavras)  # Escolhe palavra
        palavra_embaralhada = embaralha_palavra(palavra_escolhida)  # Embaralha palavra
        palavra_mostrada = mostra_palavra(palavra_embaralhada)  # Mostra palavra embaralhada em string
        print(palavra_mostrada)
        adivinha = input("Que palavra é essa?: ")
        tentativas = 5
        while tentativas >= 1:  # Enquanto chances nao acabam: 
            flag = False
            if adivinha == palavra_escolhida:  # Se tentativa for palavra escolhida: 
                flag = True  # Jogador ganha
            if flag:  # Se jogador tiver ganhado: 
                print("Voce conseguiu!")
                tentativas = 0  # Loop while é parado
            else:  # Se tentativa não for palavra escolhida: 
                tentativas -= 1  # Tira uma tentativa, mostra mensagem e pede nova tentativa
                print("Tente outra vez! Você tem mais %d chances\n\n" % (tentativas+1))
                print("-"*10)
                print("PALAVRA EMBARALHADA: ", palavra_mostrada, '\n')
                adivinha = input("Que palavra é essa?: ")
        
        if tentativas == 0 and flag == False:  # Verifica se jogador perdeu por tentativa
            print("Você perdeu!")

        quer_jogar = int(input("Quer jogar de novo? (0 para não, 1 para sim)"))  # Verifica se jogador quer jogar


quer_jogar = 1
jogo(quer_jogar)  # Execucao de main




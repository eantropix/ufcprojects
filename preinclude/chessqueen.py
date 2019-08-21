import random
board = []
for i in range(0, 8):
	board.append([0, 0, 0, 0, 0, 0, 0, 0])
	print(board[i])
def show_board():
	for i in range(0, 8):
		print(board[i])

def targets(a):
	i = 0
	while i < a:  # Loop para posicionar número de peças selecionadas
		row = random.randint(0, 7)  # Gera um numero aleatorio para linha
		column = random.randint(0, 7)  # e coluna
		if board[row][column] != 1 :  #Verifica se já existe peca no local
			board[row][column] = 1  # Passa coordenadas para o tabuleiro
			print(row, column)
			i += 1


def vertical(qrow, qcolumn): # Funcao que percorre a coluna da rainha
	count = 0

	for i in range(0, 8):  # Loop das linhas
		if i != qrow:  # Se i bate com coordenada da rainha, ignora rainha
			if board[i][qcolumn] == 1:  # Se tiver peca presente na coordenada:
				board[i][qcolumn] = 3
				count += 1  # Aumenta o contador
	return(count)


def horizontal(qrow, qcolumn):  # Funcao que percorre a linha da rainha
	count = 0

	for i in range(0, 8):  # Loop das colunas
		if i != qcolumn:  # Se i bate com coordenada da rainha, ignora rainha
			if board[qrow][i] == 1:  # Se tiver peca presente na coordenada:
				board[qrow][i] = 3
				count += 1  # Aumenta o contador
	return(count)

def fslash(qrow, qcolumn):
	count = 0
	flag  = True
	buffer_row = qrow; buffer_column = qcolumn;  # Passa coordenadas da rainha para buffers
	while flag:  # Loop que segue para a direita da rainha, subindo
		if (buffer_row == 0) or (buffer_column == 7):
			flag = False
		else:
			buffer_row -= 1; buffer_column += 1  # Muda as coordenadas para subir para direita
			if board[buffer_row][buffer_column] == 1:  # Se tiver peca na coordenada atual:
				board[buffer_row][buffer_column] = 3
				count += 1  # Aumenta o contador
	flag = True  # Reseta flag
	buffer_row = qrow; buffer_column = qcolumn;  # Repassa coordenadas, reseta buffers

	while flag:  # Loop que segue para a esquerda da rainha, descendo
		if (buffer_row == 7) or (buffer_column == 0):
			flag = False
		else:
			buffer_row += 1; buffer_column -= 1  # Muda as coordenadas para descer para esquerda
			if board[buffer_row][buffer_column] == 1:  # Se tiver peca na coordenada atual:
				board[buffer_row][buffer_column] = 3
				count += 1  #Aumenta o contador

	return(count)

def bslash(qrow, qcolumn):
	count = 0
	flag = True
	buffer_row = qrow; buffer_column = qcolumn

	while flag:  # Loop que segue para a esquerda da rainha, subindo 
		if (buffer_row == 0) or (buffer_column == 0):
			flag = False
		else:
			buffer_row -= 1; buffer_column -= 1  # Muda as coordenadas para subir para esquerda
			if board[buffer_row][buffer_column] == 1:  # Se tiver peca na coordenada atual:
				board[buffer_row][buffer_column] = 3				
				count += 1  # Aumenta o contador

	flag = True  # Reseta flag
	buffer_row = qrow; buffer_column = qcolumn  # Repassa coordenadas, reseta buffers


	while flag :  # Loop que segue para a direita da rainha, descendo
		if (buffer_row == 7) or (buffer_column == 7):
			flag = False
		else:
			buffer_row += 1; buffer_column += 1  # Muda as coordenadas para descer para direita
			if board[buffer_row][buffer_column] == 1:  # Se tiver peca na coordenada atual:
				board[buffer_row][buffer_column] = 3
				count += 1  # Aumenta o contador
		
	return(count)

def queen(qrow, qcolumn):
	master_count = vertical(qrow, qcolumn) + horizontal(qrow, qcolumn) + fslash(qrow, qcolumn) + bslash(qrow, qcolumn)

	print("Você assassinou {} pecas!!".format(master_count))


print("Bem vindo à Rainha Assassina!")
pecas = int(input("Digite o número de peças inimigas: "))
while pecas >=64:
	print("Você quer muitas peças!")
	pecas = int(input("Digite um número menor que 64: "))

targets(pecas)

print("Peças colocadas! Agora, tente matar o máximo possível colocando uma rainha no tabuleiro!")
show_board()

allowed_pos = 0
while allowed_pos == 0:
	qrow = int(input("Digite a linha desejada! (1 a 8)"))
	qrow -= 1
	qcolumn = int(input("Digite a coluna desejada! (1 a 8)"))
	qcolumn -= 1
	if board[qrow][qcolumn] == 1:
		print("Esta casa já está ocupada! Escolha outra!")
	else:
		print("Pois bem, vamos começar!")
		board[qrow][qcolumn] = 2
		allowed_pos = 1

show_board()
queen(qrow, qcolumn)


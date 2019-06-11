# NOME: ARTHUR SANTOS VIANA DE OLIVEIRA
# MATRICULA: 470788
# =====================================

banco = open('banco_horas.txt', 'r')
banco = banco.readlines()
new_banco = []
for i in range(len(banco)):
    banco[i] = banco[i].replace('\n', '')
    new_banco.append(banco[i].split(sep='\t'))

print(new_banco)


# ARQUIVO EXEMPLO: 
# Alexander   45
# Anderson    12
# Antonio 12
# Carlos  91
# Cesar   98
# Rosemary    78
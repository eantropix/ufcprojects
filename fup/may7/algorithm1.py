def add_produto(codigo, valor, quant):
    return {'codigo': codigo, 'valor': float(valor), 'quant': int(quant)}


def mostra_produto(codigo, estoque):
    for i in range(len(estoque)):
        if estoque[i]['codigo'] == codigo:
            return estoque[i]['quant'], estoque[i]['valor']


def total(estoque):
    total_quant, total_valor = 0, 0
    for i in range(len(estoque)):
        quant = estoque[i]['quant']
        total_quant += estoque[i]['quant']
        total_valor += estoque[i]['valor'] * quant
    return total_quant, total_valor


estoque = []
for i in range(2):
    produto = {}
    entrada = input("Digite o código, valor e quantidade: ")
    entrada = entrada.split(sep=' ')
    estoque.append(add_produto(entrada[0], entrada[1], entrada[2]))
print(estoque)
ent = input("Digite o código: ")


quantidade_item, valor_item = mostra_produto(ent, estoque)
print("Do código", ent, "existem: ")
print(quantidade_item, "produtos")
print("Custando", valor_item, "cada")


total_quant, total_valor = total(estoque)
print("Quantidade total de itens: ", total_quant)
print("Valor total de itens: ", total_valor)


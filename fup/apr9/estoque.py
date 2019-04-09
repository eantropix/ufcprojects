tam = 3
codigo = [0] * tam
em_estoque = [0] * tam
for i in range(0, tam):
    codigo[i] = int(input("Codigo do produto %d: " % i))
    em_estoque[i] = int(input("Quantidade da mercadoria %d: " % i))
inp_cliente = 1
inp_produto = 0
inp_quant = 0
while inp_cliente > 0:
    inp_cliente = int(input("Insira o seu código de cliente: "))

    if inp_cliente > 0:
        inp_produto = int(input("Insira o código do produto: "))
        inp_quant = int(input("Quantas unidades gostaria de comprar? "))
        aux = True
        for j in range(len(codigo)):
            if codigo[j] == inp_produto:
                aux = False
                if em_estoque[j] >= inp_quant:
                    em_estoque[j] -= inp_quant
                    print("Pedido atendido. Obrigado e volte sempre.\n ")
                else:
                    print("Não há estoque suficiente deste produto para atendê-lo.\n")
        if aux:
            print("Código inexistente.\n")
                
print("\n\nMERCADORIAS")
ind = 0
for k in codigo:
    print("Código: {} - Quantidade: {}".format(k, em_estoque[ind]))
    ind += 1

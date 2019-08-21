initValue = float(input("Digite o valor que deseja pegar emprestado: "))
juros_1 = 0.02  # inicializa os primeiros valores, já que são diferentes do resto
parc_1 = 1  # idem ^ 
parc_x = 3  # início da P.A que representa todos os valores a partir do segundo
juros_x = 0.10  # idem ^

vj_1 = (initValue * juros_1)  
tp_1 =  (initValue + vj_1)
vp_1 = (tp_1 / parc_1)


vj_x = (initValue * juros_x)  
tp_x =  (initValue + vj_x)
vp_x = (tp_x / parc_x)


print("TOTAL A PAGAR || VALOR DOS JUROS || QTD DE PARCELAS || VALOR DA PARCELA")
print("{:>3.2f}                 {:>3}                  {:>2}            {:>3.2f}".format(tp_1, vj_1, parc_1, vp_1))
for i in range(3, 61, 3):
    print("{:>3.2f}               {:>3.2f}                 {:>3}             {:>3.2f}".format(tp_x, vj_x, parc_x, vp_x))
    juros_x += 0.05
    parc_x += 3

    vj_x = (initValue * juros_x)  
    tp_x =  (initValue + vj_x)
    vp_x = (tp_x / parc_x)

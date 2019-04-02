initValue = float(input("Digite o valor que deseja pegar emprestado: "))
juros1, juros2, juros3, juros4, juros5 = 0.02, 0.1, 0.15, 0.20, 0.25
parc1, parc2, parc3, parc4, parc5 = 1, 3, 6, 9, 12
vj1, vj2, vj3, vj4, vj5 = (initValue * juros1), (initValue * juros2), (initValue * juros3), (initValue * juros4), (initValue * juros5)
tp1, tp2, tp3, tp4, tp5 =  (initValue + vj1), (initValue + vj2), (initValue + vj3), (initValue + vj4), (initValue + vj5)
vp1, vp2, vp3, vp4, vp5 = (tp1 / parc1), (tp2 / parc2), (tp3 / parc3), (tp4 / parc4), (tp5 / parc5)

print("    TOTAL A PAGAR || VALOR DOS JUROS || QTD DE PARCELAS || VALOR DA PARCELA")
print("    {0:.2f}               {1:.2f}                  {2}                  {3:.2f}".format(tp1, vj1, parc1, vp1))
for i in range(3, 13, 3):
    print("{0:.2f}               {1:.2f}                  {2}                  {3:.2f}".format(tp2, vj2, parc2, vp2))
# print("{0:.2f}               {1:.2f}                  {2}                  {3:.2f}".format(tp3, vj3, parc3, vp3))
# print("{0:.2f}               {1:.2f}                  {2}                  {3:.2f}".format(tp4, vj4, parc4, vp4))
# print("{0:.2f}               {1:.2f}                  {2}                  {3:.2f}".format(tp5, vj5, parc5, vp5))

arquivo1 = open('pares.txt', 'w')
arquivo2 = open('impares.txt', 'w')

for i in range(1, 1001):
    if i % 2 == 0:
        arquivo1.write("%d\t" % i)
    else:
        arquivo2.write("%d\t" % i)
arquivo1.close()
arquivo2.close()

par = open('pares.txt', 'r')
impar = open('impares.txt', 'r')
cont = 0
for num in par:
        print(num, end='\t')
        if cont%10 == 0:
            print('\n')
        cont += 1
cont = 0
for num in impar:
        print(num, end='\t')
        cont += 1
        if cont%10 == 0:
            print('\n')
par.close()
impar.close()
def mdc(a, b):
    if b == 0:
        return a
    else:
        return(mdc(b, a%b))
ent = input('Digite dois números para calcular o MDC: ')
ent = ent.split(sep=' ')
a = int(ent[0])
b = int(ent[1])
if a < b:  # a precisa ser maior:
    aux = b
    b = a
    a = aux
print(mdc(a, b))
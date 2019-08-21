"""

EQUIPE:

Amanda Kevillyn Bandeira Cavalcante - Matrícula 471538 - Turma 01A
Arthur Santos Viana de Oliveira - Matrícula 470788 - Turma 01A 
Rene Monteiro Carioca Freire - Matrícula 473951 - Turma 02A
Vinicius Bernardo Gabriel - Matrícula 475210 - Turma 02A

"""


menu = """
============================================
Digite um número no seguinte formato
Yxxxxxxxx. 
(Onde Y é a base do número:
[d] decimal
[h] hexadecimal
[o] octal
[b] binário
[g] gray
e xxxxxxxx é o número.

EXEMPLOS: d10, hF, o7, b111
============================================

NUMERO: """
#  receives number from user
original = input(menu).lower()


def binary_gray(start_n, command):  # Receives the binary/gray number and converts it depending on the command

    start_n = list(start_n)  # start_n becomes list, MSB passed to end_n, which becomes a list
    end_n = start_n[0]
    end_n = list(end_n)
    length = len(start_n) - 1  # Gets length of the start_n. Decreases 1 so it won't get out of index range.

    for i in range(0, length):  # Conversion is done using XOR. What changes is which numbers are used when comparing

        if command == 'g':  # Number is gray, which means comparison is done with current end_n and the next start_n
            if end_n[i] != start_n[i+1]:  # XOR gate: Different bits award 1, equal bits award 0
                end_n.extend('1')
            else:
                end_n.extend('0')

        elif command == 'b':  # number is binary, which means comparison is done with current and next start_n's
            if start_n[i] != start_n[i+1]:  # XOR gate: Different bits award 1, equal bits award 0
                end_n.extend('1')
            else:
                end_n.extend('0')
    new_n = ''
    for i in range(0, length+1):
        new_n = new_n + end_n[i]
    return new_n


def decimal_to_base_n(decimal, n):
    if n == 10:
        return decimal

    result = ""

    representations = {
        0: "0", 1: "1", 2: "2", 3: "3", 4: "4", 5: "5", 6: "6", 7: "7", 8: "8", 9: "9",
        10: "A", 11: "B", 12: "C", 13: "D", 14: "E", 15: "F"}

    while decimal > 0:
        result = representations[decimal % n] + result
        decimal = decimal // n
    return result


def base_n_to_decimal(number, n):
    if n == 10:
        return number

    dic = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9,
           'A': 10, 'a': 10, 'B': 11, 'b': 11, 'C': 12, 'c': 12, 'D': 13, 'd': 13, 'E': 14, 'e': 14, 'F': 15, 'f': 15}
    
    result = 0

    pot = len(number) - 1

    for i in range(0, len(number)):
        result = result + dic[number[i]] * (n ** pot)
        pot -= 1
    
    return result


possible_bases = {'d': 10, 'h': 16, 'b': 2, 'o': 8, 'g': 2}

base = original[0]

# Captures first digit to be used in Binary-Gray conversion, then removes it from original number

original = original[1:]

# Always convert to decimal before doing other conversions. However, if original is inputted with
# base gray, original_decimal needs to be retrieved through the original_binary counterpart. If that step is not taken,
# the other numbers will be calculated presuming gray is actually binary, as they have the same base.
# That leads to errors in the calculations and results in a conversion from gray's binary equivalent, not gray itself.
if base == 'g':
    original_binary = binary_gray(original, base)
    original_decimal = int(base_n_to_decimal(original_binary, possible_bases[base]))
else:
    original_decimal = int(base_n_to_decimal(original, possible_bases[base]))

# now, convert to binary, octal and hexadecimal.
# If number has base gray, original_binary has to be returned from binary_gray function, as decimal_to_base_n is not
# equipped to convert it.
if base == 'g':
    original_binary = binary_gray(original, base)
    original_gray = original
else:
    original_binary = decimal_to_base_n(original_decimal, 2)
    print(original_binary)

if base == 'b':
    original_gray = binary_gray(original, base)
    original_binary = original
else:
    original_gray = binary_gray(original_binary, 'b')


original_octa = decimal_to_base_n(original_decimal, 8)
original_hexa = decimal_to_base_n(original_decimal, 16)


print('''
{}
RESULTADOS
{}

DECIMAL: {}
BINARIO: {}
GRAY: {}
OCTAL: {}
HEXA: {}
'''.format('=' * 35, '=' * 35, original_decimal, original_binary, original_gray, original_octa, original_hexa))

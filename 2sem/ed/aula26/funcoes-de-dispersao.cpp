/*
1. Observações sobre o método da divisão
    a) Se m = 2^p, para algum 'p' (ou seja, 'm' é uma potência de 2), então nem todos 
    os 'w' bits da chave serão usados: Só o serão os 'p' bits menos significativos

        [ - IGNORADOS - ][ -  USADOS  - ]
        +---+---+---+---+---+---+---+---+
        | 0 | 1 | 0 | 1 | 1 | 0 | 0 | 0 |
        +---+---+---+---+---+---+---+---+
        [MÚLTIPLO DE 2^4][    RESTO     ]
        (p = 4; w = 8)

       Essa situação tende a ser ruim, pois os '(w - p)' bits mais à direita poderiam 
       ajudar a fornecer variação entre as chaves.
    

    b) Além disso, se as chaves e 'm' tiverem um fator comum k, então apenas as posições 
    da tabela que são múltiplas de k serão preenchidas!

    c) Para evitar a possibilidade de haver fatores comuns entre 'm' e as chaves, o 
    método da divisão é tipicamente acompanhado pela escolha de números PRIMOS para 'm', 
    os quais na prática são pré-computados e inseridos diretamente no código.

    d) Por fim, são escolhidos primos "longe" de potências de 2, ou seja, próximos de
        [2^i + 2^(i+1)] / 2


2. Método da multiplicação

    a) Definição matemática:  {Tendo |_x_| como "o piso de x"}
        h(c) = |_(c.A - |_(c.A)_|)*m_| , para algum 0 < A < 1
    
    b) Intuição:
        1. Multiplicar 'c' e 'A'
        2. Pegar a parte fracionária do resultado (descartar a parte inteira): 
            c*A - |_c*A_|
        3. Multiplicar por 'm'
        4. Obter o piso

        Podemos observar que, partindo de uma representação de A na base 2:
            -> Os dígitos 1 de 'A' correspondem a cópias de 'c' no algoritmo 
                "matemático" de multiplicação

            -> As posições desses 1's dirão os deslocamentos à esquerda das cópias de 'c' 

        De forma geral, a intenção com multiplicar por 'A' é somar 'c' consigo mesma 
        algumas vezes, de forma "imprevisível/desordenada", devido aos deslocamentos à 
        esquerda.

        Depois disso, "c.A - |_c.A_|" é um número de 0 a 1, e multiplicar por 'm' é uma 
        maneira de obter algo no intervalo das chaves ([0..m]). O piso final é apenas 
        uma maneira de garantir um número natural.
    
    c) Computação na prática:
        Passo 1, representação de 'A':
            A = s/2^w , onde 'w' é o número de bits da palavra e 's' pertence a {1,...,2^w - 1}
*/
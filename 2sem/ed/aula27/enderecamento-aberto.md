1. Introdução:
    O método de resolução de colisões por ENDEREÇAMENTO ABERTO leva a ideia de "calcular 
    a posição das chaves" um passo adiante: SE uma chave não estiver na posição 
    inicialmente esperada, então nós *calculamos* a próxima posição a consultar.

    Mais especificamente, o endereçamento aberto utiliza uma FUNÇÃO DE SONDAGEM tal que 
        'h(c, i)'
    dá a i-ésima posição onde a chave 'c' pode estar, com 'i' pertencendo à [0..m-1].
    
    Toda função de sondagem tem que ser tal que
        <h(c, 0) , h(c, 1) , h(c, 2) , h(c, 3) , ... , h(c, m-1)>
    
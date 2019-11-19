# REMOÇÃO AVL

1. Introdução

    a) Observe primeirarmente que a remoção em árvores binárias de busca gerais tem 3 casos: 
        - O nó é folha
        - O nó tem 1 filho
        - O nó tem 2 filhos

    b) Em seguida, observe, independentemente do caso, há um nó da árvore que é realmente 
    removido (no 3o caso, por exemplo, o nó do elemento que é removido _não é_ realmente 
    removido, pois o elemento é substituído pelo seu sucessor ou predecessor); são os 
    ancestrais desse nó que analisaremos e, se necessário, corrigiremos.

    c) Assim como na inserção, nós, por simetria, só analisaremos alteração de altura à 
    direita.

    d) Assim como na inserção, há casos triviais.


0. Revisão:
    a) Desejamos inserir um elemento numa árvore AVL A, gerando uma nova árvore AVL A*.
    O procedimento será recursivo.

    b) Se A = /0/, a inserção é trivial, gerando uma árvore AVL de 1 nó e altura 1
    (logo, h(A*) > h(A): É necessário checar se os ascendentes do nó inserido ficaram
    desbalanceados).

    c) Se A != /0/, então A = x
                             / \
                          |EX| |DX|  
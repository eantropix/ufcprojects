
1. Exercício: Expresse, em termos de "n", a complexidade assintótica
do tempo de execução da função abaixo


double soma (double *v, int n)
{
    double s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += v[i];
    }
    return s;

}


Solução: Podemos separar o tempo de execução da função em:

    [inicialização da função] 
    [double s = 0           ]  a  (tempo das 3 instruções)
    [i = 0                  ]

    [i < n    ]
    [s += v[i]]  b (tempo de 1 iteração) -> n vezes
    [++i      ]

    [i < n (última iteração)]
    [return s               ]  c (tempo das 3 instruções)
    [finalização da função  ]



2. Exercício: Qual é a complexidade o tempo de execução desta função:

int busca_linear (double *v, int n, double e)
{
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == e) return i;
    }
    return -1;
}

Solução: É fácil observar que o tempo de execução da função não depende só de "n", 
mas também de  "v" e "e". Porém, para expressar tempo de execução em termos da 
notação "O" aplicada à alguma função g(n), podemos considerar uma função f(n)
que dê o tempo de execução da função no PIOR CASO, e nesse caso encontrar g(n)
tal que f = O(g). Nesse caso, é evidente que, assim como no exercício anterior, 
existem constantes "a" e "b" tais que f(n) = a*n + b. Além disso, é o caso que 
f(n) = O(n). Logo, dizemos que o tempo de execução o algoritmo é O(n).



3. Exercício: Qual é o tempo de execução do algoritmo abaixo: 
(Pré-condição: Para todo i pertencente a [0..n-2], v[i+1] = v[i] + 1)


double soma (double *v, int n)
{
    return (v[0] + v[n-1])*n/2;
}


Resposta curta: A função executa em tempo constante (independente de "n"), e 
portanto executa em tempo O(1).

Resposta longa: É fácil ver que existe uma constante positiva "a" tal que o 
tempo de execução da função é f(n) = a. Como f(n) = O(1), então a função 
executa em tempo O(1).

Observação: Para todo "a" pertencente aos Naturais-não-nulos, a = O(1)

Prova: Sejam (m = 1), (c = a) e (n >= m). Temos: 0 <= a <= c.n
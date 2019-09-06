int soma_vint (int *v, int n)  
{
    int soma = 0, i;
    for (i = 0; i < n; ++i)
    {
        soma += v[i];
        return soma;
    }
}

/* É perigoso escrever a mesma função várias vezes
para fazer a mesma coisa, mudando apenas os tipos.
Dificulta manutenibilidade, principalmente em códigos
maiores. Observe que temos a mesma função para soma 
apenas mudando os tipos.*/

double soma_vdouble (double *v, int n)
{
    double soma = 0; int i;
    for (i = 0; i < n; ++i)
    {
        soma += v[i];
        return soma;
    }
}
/*Este problema pode ser resolvido com 
Polimorfismo Paramétrico.*/

template <typename T>
T soma_vet (T *v, int n)
{
    T soma = 0; int i;
    for (i = 0;i < n; ++i)
    {
        soma += v[i];
    }
    return soma;
}

int main1()
{
    int v[3] = {1, 2, 3};
    double w[3] = {1, 2, 3};
    int si = soma_vet<int>(v, 3);
    //Ou: si = soma_vet(v, 3);
    double sd = soma_vdouble(w, 3);
    //OU: sd = soma_vet(w, 3); Ambos são possíveis devido à conversão implícita
}

template <typename X, typename Y> //Usando templates é possível criar tipos parametrizados
struct par {X x; Y y;};

par<int, int> div_int (int a, int b)
{
    par<int, int> p;
    p.x = a / b;
    p.y = a % b;
    return p;
}

int main2()
{
    par<int, int> p = div_int(7, 3);
    int qq_coisa = p.x + p.y;
}

template <typename X, typename Y>
X primeiro (par<X,Y> p)
{
    return p.x;
}

template <typename X, typename Y>
Y segundo (par<X,Y> p)
{
    return p.y;
}
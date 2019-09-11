/*==== ITERADORES ====
1. O Ponteiro THIS: Dentro de uma função-membro, a expressão THIS
denota um poteiro para a estrutura a partir da qual a função foi chamada.
Exemplo:*/
#include <iostream>
using std::cout;

struct TipoQQ
{
    int campo_qq;
    //TipoQQ
    TipoQQ* meu_endereco() {return this;}
};

int main1()
{
    TipoQQ a, b;
    cout << "Endereço de a: " << a.meu_endereco() << '\n';
    if(&a != a.meu_endereco() || a.meu_endereco() == b.meu_endereco())
    {cout << "Absurdo!\n";}
}

/*
2. REFERÊNCIAS: Em C++, uma referência é outro nome para um objeto na memória.
Elas compartilham parte da utilidade dos ponteiros, por exemplo a possibilidade
de se acessar uma variável num contexto em que ela não pode ser referida pelo
nome, e com vantagens, como a não necessidade do uso do operador "*" para o
acesso. Por outro lado, referências são mais restritas que ponteiros, no sentido
de que, enquanto ponterios podem ser redirecionados, uma referência sempre 
aponta para o mesmo endereço, a saber, o endereço da inicialização.
Exemplo: */

void trocar(int &a, int &b)
{
    int copia_de_a = a;
    a = b;
    b = copia_de_a;
}

int main2()
{
    int x = 10; int &rx = x;
    rx = 5; //x == 5;
    int y = 0;
    trocar(x, y);
    //x == 0 && y == 5; 
}

/*
3. SOBRECARGA DE OPERADORES: Em C++ podemos dar "novos significados" aos
operadores.
Exemplo:*/

struct Vetor2D
{
    double x, y;
    Vetor2D operator+ (const Vetor2D &v)
    {
        Vetor2D novo;
        novo.x = x + v.x;
        novo.y = y + v.y;
        return novo;
    }
};

/*
4. ITERADORES: Dão uma maneira não-intrusiva de se percorrer coleções.
Exemplo: */
int main3()
{
    Conjunto<double> C;
    /*...Povoar C...*/
    auto fim = C.fim();
    for (auto i = C.inicio(); i != fim; ++i)
    {
        cout << ' ' << *i;
    }
    C.terminar();
}
/*Implementação: */

//Conjunto vem antes
struct Iterador
{
    T *p;
    bool operator!= (const Iterador &j)
    {
        return (p != j.p);
    }
    T& operator*() {return *p;}

    Iterador& operator++()
    {
        ++p;
        return this;
    }
};
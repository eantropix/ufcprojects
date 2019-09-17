#include <new>
using std::nothrow;

template <typename T>
struct pilha
{
    struct noh
    {T elem; noh *prox;};
    noh *topo;
    void inicializar() {topo = nullptr;}
    bool vazia() {return (topo == nullptr);}
    T consultar_topo() {return ((*topo).elem);} //topo->elem
    bool empilhar(T e)
    {
        noh *n = new(nothrow) noh;
        if (n == nullptr) {return true;}
        (*n).prox = topo; (*n).elem = e;
        topo = n;
        return false;
    }
    T desempilhar()  // Pre-condition: Stack isn't empty
    {
        T e = (*topo).elem;
        noh *n = topo;
        topo = (*topo).prox;
        delete n;
        return e;
    }
    void terminar()
    {
        while(topo != nullptr)
        {
            noh *n = topo;
            topo = (*topo).prox;
            delete n;
        }
    }
    void terminar2() // Versão utilizando desempilhar
    {
        while(!vazia()) {desempilhar();} // O retorno de desempilhar é descartado pelo g++
    }
};

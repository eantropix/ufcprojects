#include <new>

using std::nothrow;

struct simulAloc
{
    struct Noh {int ini, tam; Noh *prox;};
    Noh *prim;
    bool inicializar(int ini, int tam)
    {
        prim = nullptr;
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) {return true;}
        n->ini = ini; n->tam = tam; n->prox = nullptr;
        return false;
    }

};

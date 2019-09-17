#include <new>
using std::nothrow;

template <typename T>
struct fila
{

    struct noh{T elem; noh *prox;};
    noh *ini, *fim;
    void inicializar()
    {
        *ini = nullptr; //No need to set fim, as it has no use if/when it becomes null
    }
    bool vazia(){return (ini == nullptr);} // Returns true if empty
    bool enfilar(T e) // Returns true if allocation doesn't work
    {
        noh *n = new(nothrow) noh;
        if (n == nullptr) return true;
        if (vazia())
        {
            ini = n; fim = n;
            (*fim).elem = e; (*fim).prox = nullptr;
        }
        else
        {
            (*fim).prox = n;
            fim = n;
            (*fim).elem = e;
        }
        return false;
    }
    T desenfilar()  // Returns oldest element in queue
    {
        noh *n = ini;
        T e = (*n).elem;
        ini = (*ini).prox;
        delete n;
        return e;        
    }
    void terminar()
    {
        while (!vazia()){desenfilar();}
    }

};
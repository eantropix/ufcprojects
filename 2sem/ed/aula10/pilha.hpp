#include <new>
using std::nothrow;

template <typename T>
struct pilha
{
    T *v; int ult, tam_v;
    bool inicializar()
    {
        v = new(nothrow) T[1];
        if (v == nullptr) return true;
        ult = -1; tam_v = 1;
        return false;
    }
    void terminar()
    {
        delete[] v;
    }
    bool vazia()
    {
        return (ult == -1);
    }
    //Redimensionar fica aqui
    bool empilhar(T e)
    {
        if (ult == tam_v - 1)
        {
            if (redimensionar(tam_v*2))
            {return true;}
        }
        ++ult; v[ult] = e;
        return false;
    }
    T topo() {return v[ult];} // Pré-cond.: ñ vazia
    bool desempilhar() //Pré-cond.: ñ vazia
    {
        --ult;
        if(!vazia() && 4*(ult+1) <= tam_v)
        {
            if (redimensionar(tam_v/2))
            {return true;}
        }
        return false;
    }
    bool redimensionar(int tam_w)
    {
        t *w = new(nothrow) T[tam_w]
        if (w == nullptr) return true;
        for (int i = 0; i <= ult; ++i)
        {w[i] = v[i];}
        delete[] v; v = w;
        tam_v = tam_w;
        return false;
    }
};
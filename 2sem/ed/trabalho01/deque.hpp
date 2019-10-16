#include <new>
using std::nothrow;

template <typename T>
struct Deque
{
    T *D; int esq, dir, tam_d, n_itens;
    // bool inicializar(Deque<T> &D);
    // bool vazio(Deque<T> &D);
    // void terminar(Deque<T> &D);
    // bool aumentar(Deque<T> &D, int novo_tam);
    // bool inserir_esq(Deque<T> &D, T e);
    // bool inserir_dir(Deque<T> &D, T e);
    // T remover_esq(Deque<T> &D);
    // T remover_dir(Deque<T> &D);
    bool inicializar(Deque<T> &D)  // Returns true if allocation doesn't work
    {
        D = new(nothrow) T[1];  // Array of size 1;
        if (D == nullptr) {return true;}
        esq = 0; dir = 0; tam_d = 1; n_itens = 0;  // Empty deque, esq and dir point to the same place
        return false;
    }
    void terminar(Deque<T> &D){delete[] D;}
    bool vazio(Deque<T> &D) {return (!n_itens);} // Returns true if empty
    bool aumentar(Deque<T> &D, int novo_tam)
    {
        T *novo_d = new(nothrow) T[novo_tam];
        if (novo_d == nullptr) {return true;}
        int pos_inicial = tam_d / 2;
        for (int i = 0; i < tam_d; ++i)
        {
            novo_d[i+pos_inicial] = D[i];
        }
        delete[] D; D = novo_d;
        tam_d = novo_tam;
        return false;
    }
    bool inserir_esq(Deque<T> &D, T e)
    {
        if (!vazio(D)) // Checks if deque is empty
        {
            if (esq == 0)
            {
                if (aumentar(tam_d*2)) return true;
                int pos_esq = tam_d / 2; esq += pos_esq;
            }
            --esq; D[esq] = e; ++n_itens;
            return false;
        }
        else {D[esq] = e; ++n_itens; return false;}  // In case it is, all you need is to add the element
    }
    bool inserir_dir(Deque<T> &D, T e)
    {
        if (!vazio()) // Checks if deque is empty
        {
            if (dir == tam_d - 1)
            {
                if (aumentar(tam_d*2)) return true;
                int pos_dir = tam_d / 2; dir += pos_dir;
            }
            ++dir; D[dir] = e; ++n_itens;
            return false;
        }
        else {D[dir] = e; ++n_itens; return false;} // In case it is, all you need is to add the element
    }
    T remover_esq(Deque<T> &D)
    {
        if (!vazio){T e = D[esq]; ++esq; return e;}
    }
    T remover_dir(Deque<T> &D)
    {
        if (!vazio){T e = D[dir]; --dir; return e;}
    }
};
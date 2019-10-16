#include <new>
#include <iostream>
using std::nothrow;
using std::cin; using std::cout;
template <typename T>
struct Deque
{
    T *deq; int esq; int dir; int tam; int n_itens;
};
template <typename T>
bool inicializar(Deque <T> &D)  // Returns true if allocation doesn't work
{
    D.deq = new(nothrow) T[1];  // Array of size 1;
    if (D.deq == nullptr) {return true;}
    D.esq = 0; D.dir = 0; D.tam = 1; D.n_itens = 0;  // Empty deque, esq and dir point to the same place
    return false;
}
template <typename T>
void terminar(Deque <T> &D){delete[] D.deq;}
template <typename T>
bool vazio(Deque <T> &D) 
{
    if (D.n_itens == 0) return true; // Returns true if empty
    return false;
} 
template <typename T>
bool aumentar (Deque<T> &D)
{
    int novo_tam = (2*D.tam);
    T *novo_d = new(nothrow) T[novo_tam];
    if (novo_d == nullptr) {return true;}
    D.esq = D.tam / 2;
    D.dir = (D.esq + D.tam) - 1;
    for (int i = 0; i < D.tam; ++i)
    {
        novo_d[i+D.esq] = D.deq[i];
    }
    delete[] D.deq; D.deq = novo_d; D.tam = novo_tam;
    return false;
}
template <typename T>
bool inserir_esq(Deque <T> &D, T e)
{
    if (vazio(D)) // Checks if deque is empty
    {
        D.deq[D.esq] = e; ++D.n_itens;  // In case it is, all you need is to add the element
    }
    else{
         if (D.esq == 0)
            {
                if (aumentar(D)) {return true;}
            }
            --D.esq; D.deq[D.esq] = e; ++D.n_itens;
        }   
        return false; 
}
template <typename T>
bool inserir_dir(Deque <T> &D, T e)
{
    if (vazio(D)) // Checks if deque is empty
    {
        D.deq[D.dir] = e; ++D.n_itens;  // In case it is, all you need is to add the element
    }
    else{
         if (D.dir == D.tam - 1)
            {
                if (aumentar(D)) {return true;}
            }
            ++D.dir; D.deq[D.dir] = e; ++D.n_itens;
        }   
        return false; 
}
template <typename T>
T remover_esq(Deque <T> &D)
{
    T e = D.deq[D.esq]; ++D.esq; --D.n_itens;return e;
}
template <typename T>
T remover_dir(Deque <T> &D)
{
    T e = D.deq[D.dir]; --D.dir; --D.n_itens; return e;
}

template <typename T>
void print_deque(const Deque<T> &D){
    cout << "Deque: [";
    for(int i=0;i<D.tam;++i){
        cout << D.deq[i] << " ";
    }
    cout << "];\n";
    cout << "Esq está em: " << D.deq[D.esq] << '\n';
    cout << "Dir está em: " << D.deq[D.dir] << '\n';
}
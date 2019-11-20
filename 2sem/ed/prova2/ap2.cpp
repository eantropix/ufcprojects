// --- QUESTION 1 ---
#include <iostream>
#include <new>

using std::nothrow;

struct Node1 {double num; Node1 *prev, *next;};
struct Sequence {Node1 *first;};
void sort(Sequence &S)  // Utilizes insertion sort
{
    if (S.first == nullptr || S.first->next == nullptr) {return;}  // Checks whether list is empty or has only one Node1
    Node1 *n = S.first->next;  // The "current" Node1 being checked
    while (n != nullptr)
    {
        Node1 *cp = n->next;  
        //   ^^^ Checkpoint pointer, reference to the next 'n' pointer after current one is sorted
        if (n->prev->num > n->num)  // 'n->prev' is not null because 'n' comes after 'S.first'
        {
            n->prev->next = n->next;
            if (n->next != nullptr) {n->next->prev = n->prev;}
            Node1 *placefinder = n->prev->prev;  // Pointer to locate where 'n' fits in the sorted list
            while (placefinder != nullptr && placefinder->num > n->num)
            {
                placefinder = placefinder->prev;
            }
            if (placefinder == nullptr) // Then 'n' shall be the new 'S.first' (n < all)
            {
                S.first->prev = n;
                n->next = S.first;
                n->prev = nullptr;
                S.first = n;
            }
            else  // 'n' is "somewhere in the middle"
            {
                n->prev = placefinder;  // 'n' points to its new neighbors
                n->next = placefinder->next;
                placefinder->next = n;  // the new neighbors point to 'n'
                n->next->prev = n;
            }
        } //if
        n = cp;  // Current Node1 goes back to checkpoint, starts all over
    } //while
} //sort


// --- QUESTION 2 ---

struct Node2 {unsigned int chave; Node2 *prox;};
struct TabEncadExt {Node2 **v; unsigned int m, n;};
struct TabEndAberto {unsigned int *v, m, n; bool *vazio;};

unsigned int h(unsigned int chave, unsigned int m);

bool converter(TabEncadExt &A, TabEndAberto &B)
{
    B.m = 2 * A.m; 
    if (B.m < 2) {B.m = 2;}
    B.n = A.n;
    B.v = new(nothrow) unsigned int[B.m];
    B.vazio = new(nothrow) bool[B.m];
    if (B.v == nullptr || B.vazio == nullptr) {return true;} // Failed to allocate memory
    for (unsigned int i = 0; i < B.m; ++i) {B.vazio[i] = true;} // Before transfering, B is completely empty
    for (unsigned int i = 0; i < A.m; ++i)
    {
        Node2 *n = A.v[i];
        while (n != nullptr)
        {
            unsigned int j = h((*n).chave, B.m);
            while (B.vazio[j] == false) {j = (j+1) % B.m;}  // {++j; if(j == B.m) {j = 0;}}
            B.v[j] = n->chave;
            B.vazio[j] = true;
            n = n->prox;
        } // while
    } //for (i < A.m)
    return false;
} //converter
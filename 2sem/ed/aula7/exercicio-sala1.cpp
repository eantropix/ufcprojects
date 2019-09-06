#include <iostream>
#include <new>

using std::cin; using std::cout; using std::nothrow;
int discos;

int *cria_pilha(int discos)
{
    int pilha[discos] = new int[];
    return pilha;
}

int enche_pilha(int pilha[])
{
    for (int i = 0; i < sizeof(pilha); ++i)
    {
        pilha[i] = i;
    }
    return pilha;
}

int main()
{
    cout << "Digite o número de discos que você deseja: ";
    cin >> discos;
    int pilha1 = cria_pilha(discos);
    int pilha2 = cria_pilha(discos);
    int pilha3 = cria_pilha(discos);
    int *ponteiro1 = &pilha1;
    int *ponteiro2 = &pilha2;
    int *ponteiro3 = &pilha3;
    int pilha1 = enche_pilha(ponteiro1);
}
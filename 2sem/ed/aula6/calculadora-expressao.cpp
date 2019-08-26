#include <iostream>
#include <new>

using std::cin; using std::cout; using std::nothrow;

int main()
{
    int n; do {cout << "n: "; cin >> n;} while (n <= 0);
    char c; cin.get(c); cout << "Digite a expressão: "; //cin.get limpa o '\n' do buffer
    double *vnum = new(nothrow) double[n]; //Alocando dinamicamente vnum
    char *vop = new(nothrow) char[n]; //        ''          ''      vop
    if (vnum == nullptr) return 1;
    if (vop == nullptr) return 2;

    int ultnum = -1; int ultop = -1; //Posições atuais do último char
    for (;;)
    {
        cin.get(c); // 
        if (c == '\n') break;
        else if (c == '(' || c == ' ') continue;
        else if (c >= '0' && c <= '9') // Processamento dos dígitos
        {
            int num = 0;
            do
            {
                num = num * 10 + (c - '0');
                cin.get(c);
            } while (c >= '0' && c <= '9'); // std::isdigit

            cin.unget();
            ++ultnum; vnum[ultnum] = num; // Coloca o valor no vetor e incrementa posição
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            ++ultop; vop[ultop] = c;
        }
        else if (c == ')')
        {
            double esq, dir;
            dir = vnum[ultnum]; // Pega último número do vetor
            --ultnum; // Decrementa para pegar número anterior
            esq = vnum[ultnum]; // Pega penúltimo número
            switch(vop[ultop])
            {
                case '+': vnum[ultnum] = esq + dir; break;
                case '-': vnum[ultnum] = esq - dir; break;
                case '*': vnum[ultnum] = esq * dir; break;
                case '/': vnum[ultnum] = esq / dir; break;
            }
            --ultop; // Decrementa o operador, já que ele foi utilizado
        }
        else{cout << "Expressão Inválida! Corrija a expressão e insira novamente!";}
    }
    cout << "Resultado: " << vnum[ultnum];
    delete[] vnum;
    delete[] vop;
}
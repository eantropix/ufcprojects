#include "guabiru.h"

int main()
{
    // Declarando variáveis
    char* lista_desc[12] = {"Terra do Sol", "Acopizza", 
                            "Beach Park", "Bem friozinho", 
                            "Galinha choca", "Praias bonitas",
                            "Tem um festival bem famoso aqui", "Perto de Fortaleza", 
                            "Tem uma serra show", "Quente pra caramba", 
                            "Maior depósito de urânio", "Tem umas meninas pra dançar um forrózin top"};

    char* lista_nomes[12] = {"Fortaleza", "Acopiara", 
                             "Aquiraz", "Guaramiranga", 
                             "Quixada", "Jericoacoara", 
                             "Crato", "Pedras", 
                             "Itapipoca", "Sobral", 
                             "Quiteria", "Hidrolandia"};
    
    char *rota_arthus[5] = {"Fortaleza", "Acopiara", "Quixada", "Sobral", "Guaramiranga"};
    char *rota_arthur[5] = {"Fortaleza", "Aquiraz", "Sobral", "Pedras", "Guaramiranga"};
    char *rota_batista[5] = {"Fortaleza", "Aquiraz", "Jericoacoara", "Quiteria", "Crato"};
    char *rota_felipe[5] = {"Fortaleza", "Sobral", "Quixada", "Hidrolandia", "Pedras"};
    char *rota_cadeia[5] = {"Fortaleza", "Itapipoca", "Hidrolandia", "Quiteria", "Acopiara"};
    char *rota_leal[5] = {"Fortaleza", "Jericoacoara", "Quixada", "Sobral", "Pedras"};
    char *rota_tiago[5] = {"Fortaleza", "Acopiara", "Jericoacoara", "Hidrolandia", "Sobral"};
    char *rota_gabriel[5] = {"Fortaleza", "Guaramiranga", "Quiteria", "Pedras", "Sobral"};
    char *rota_daniel[5] = {"Fortaleza", "Hidrolandia", "Crato", "Sobral", "Quiteria"};
    char *rota_jooj[5] = {"Fortaleza", "Hidrolandia", "Quiteria", "Sobral", "Crato"};

    Mapa *ceara = criaMapa(lista_nomes, lista_desc, 12);

    Painel *guabi = criaPainel();
    guabi->rotas[0] = criaRota(ceara, 5, rota_arthus,  16, 20);
    guabi->rotas[1] = criaRota(ceara, 5, rota_arthur,  21, 50);
    guabi->rotas[2] = criaRota(ceara, 5, rota_felipe,  19, 10);
    guabi->rotas[3] = criaRota(ceara, 5, rota_batista, 18, 30);
    guabi->rotas[4] = criaRota(ceara, 5, rota_leal,     8, 00);
    guabi->rotas[5] = criaRota(ceara, 5, rota_cadeia,  13, 40);
    guabi->rotas[6] = criaRota(ceara, 5, rota_gabriel, 17, 10);
    guabi->rotas[7] = criaRota(ceara, 5, rota_tiago,   11, 30);
    guabi->rotas[8] = criaRota(ceara, 5, rota_jooj,    23, 50);
    guabi->rotas[9] = criaRota(ceara, 5, rota_daniel,  21, 40);
    guabi->n_rotas = 10;

    printf("-- GUABIRU VIAGENS --\n");
    printf("Destinos disponíveis: \n");
    // char** destinos = destinosUnicos(guabi, 10);  // Testando o main, retirando essas funções chatas por enquanto
    // mostraDestinos(destinos);
    // pegaUnicos(guabi, 10);  // Ainda é um saco pegar só os não repetidos. TODO: Procurar uma função em C que faça isso.
    mostraLocais(guabi);
    char* escolha_local = (char*) malloc (100*sizeof(char));
    int hr; int min;
    printf("Para onde quer ir? \n");
    scanf(" %s", escolha_local);
    printf("Que horas quer chegar? ");
    scanf("%d:%d", &hr, &min);
    printf("Local: %s\n", escolha_local);
    printf("Hora: %d:%d\n", hr, min);

    Painel* rotas_da_vez = criaPainel();
    adicionaDestinos(guabi, escolha_local, rotas_da_vez);
    // printf("Destino: %s", rota_top->fim->c->nome);
    // printf("Horário: %s", rota_top->hora_chegada);
    // mostraLocais(rotas_da_vez);
    Rota* rota_top = melhorRota(rotas_da_vez, hr, min);
    printf("A nossa melhor rota para você é: \n");
    printf("Destino: %s\n", rota_top->fim->c->nome);
    printf("Horario: %d:%d\n", rota_top->hora, rota_top->minuto);
    printf("Vamos embarcar? (s/n)\n");
    char partiu;
    scanf(" %c", &partiu);
    // if (partiu == 's') {viajando(rota_top);}
    // else {printf("Até logo!");}
}
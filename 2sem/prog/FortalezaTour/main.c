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
                             "Sta.Quiteria", "Hidrolandia"};
    
    char *rota_arthus[5] = {"Fortaleza", "Acopiara", "Quixada", "Sobral", "Guaramiranga"};
    char *rota_arthur[5] = {"Fortaleza", "Aquiraz", "Sobral", "Pedras", "Guaramiranga"};
    char *rota_batista[5] = {"Fortaleza", "Aquiraz", "Jericoacoara", "Sta.Quiteria", "Crato"};
    char *rota_felipe[5] = {"Fortaleza", "Sobral", "Quixada", "Hidrolandia", "Pedras"};
    char *rota_cadeia[5] = {"Fortaleza", "Itapipoca", "Hidrolandia", "Sta.Quiteria", "Acopiara"};
    char *rota_leal[5] = {"Fortaleza", "Jericoacoara", "Quixada", "Sobral", "Pedras"};
    char *rota_tiago[5] = {"Fortaleza", "Acopiara", "Jericoacoara", "Hidrolandia", "Sobral"};
    char *rota_gabriel[5] = {"Fortaleza", "Guaramiranga", "Sta.Quiteria", "Pedras", "Sobral"};
    char *rota_daniel[5] = {"Fortaleza", "Hidrolandia", "Crato", "Sobral", "Sta.Quiteria"};
    char *rota_jooj[5] = {"Fortaleza", "Hidrolandia", "Sta.Quiteria", "Sobral", "Crato"};

    Mapa *ceara = criaMapa(lista_nomes, lista_desc, 12);

    Painel *guabi = criaPainel();

    // Rota *arthur =  criaRota(ceara, 4, rota_arthur, "21:50");
    // Rota *arthus =  criaRota(ceara, 4, rota_arthus, "16:20");
    // Rota *batista = criaRota(ceara, 5, rota_batista, "18:30");
    // Rota *felipe =  criaRota(ceara, 5, rota_felipe, "19:10");
    // Rota *cadeia =  criaRota(ceara, 5, rota_cadeia, "13:40");
    // Rota *leal =    criaRota(ceara, 5, rota_leal, "08:00");
    // Rota *tiago =   criaRota(ceara, 5, rota_tiago, "11:30");
    // Rota *gabriel = criaRota(ceara, 5, rota_gabriel, "17:10");
    // Rota *daniel =  criaRota(ceara, 5, rota_daniel, "21:40");
    // Rota *jooj =    criaRota(ceara, 5, rota_jooj, "23:50");

    guabi->rotas[0] = criaRota(ceara, 5, rota_arthus, "16:20");
    guabi->rotas[1] = criaRota(ceara, 5, rota_arthur, "21:50");
    guabi->rotas[2] = criaRota(ceara, 5, rota_felipe, "19:10");
    guabi->rotas[3] = criaRota(ceara, 5, rota_batista, "18:30");
    guabi->rotas[4] = criaRota(ceara, 5, rota_leal, "08:00");
    guabi->rotas[5] = criaRota(ceara, 5, rota_cadeia, "13:40");
    guabi->rotas[6] = criaRota(ceara, 5, rota_gabriel, "17:10");
    guabi->rotas[7] = criaRota(ceara, 5, rota_tiago, "11:30");
    guabi->rotas[8] = criaRota(ceara, 5, rota_jooj, "23:50");
    guabi->rotas[9] = criaRota(ceara, 5, rota_daniel, "21:40");

    printf("-- GUABIRU VIAGENS --");
    printf("Destinos disponíveis: ");
    char** destinos = destinosUnicos(guabi, 10);
    mostraDestinos(destinos);

}
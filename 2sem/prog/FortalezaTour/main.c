#include "guabiru.h"
//#include "ceara.h"
int main()
{
    // rotas_guabiru();
    // Criando cidades
    // Ponteiros para cidade começam com minúsculo
    Cidade* fortaleza =    criaCidade("Fortaleza", "Terra do Sol");
    Cidade* 
    Cidade* aquiraz =      criaCidade("Aquiraz", "Beach park top");
    Cidade* guaramiranga = criaCidade("Guaramiranga", "Serras top");
    Cidade* jericoacoara = criaCidade("Jericoacoara", "Praias lindas");
    Cidade* quixada =      criaCidade("Quixadá", "Galinha choca");

    //Criando paradas
    // Ponteiros para parada começam com maiúsculo
    // Rota: FORTALEZA - AQUIRAZ - QUIXADA - GUARAMIRANGA - JERICOACOARA
    Parada* Fortaleza0 =  criaParada(NULL, fortaleza, aquiraz); // Fortaleza é o início
    Parada* Fortaleza1 =  criaParada(NULL, fortaleza, );
    Parada* Fortaleza2 =  criaParada(NULL, fortaleza, );
    Parada* Fortaleza3 =  criaParada(NULL, fortaleza, );
    Parada* Fortaleza4 =  criaParada(NULL, fortaleza, );
    Parada* Fortaleza5 =  criaParada(NULL, fortaleza, );
    Parada* Fortaleza6 =  criaParada(NULL, fortaleza, );
    Parada* Fortaleza7 =  criaParada(NULL, fortaleza, );
    Parada* Fortaleza8 =  criaParada(NULL, fortaleza, );
    Parada* Fortaleza9 =  criaParada(NULL, fortaleza, );

    Parada* Aquiraz =      criaParada(fortaleza, aquiraz, quixada);
    Parada* Quixada =      criaParada(aquiraz, quixada, guaramiranga);
    Parada* Guaramiranga = criaParada(quixada, guaramiranga, jericoacoara);
    Parada* Jericoacoara = criaParada(guaramiranga, jericoacoara, NULL); // Jeri é o fim

    Rota* For_Jeri = criaRota(Fortaleza1, Jericoacoara, "01:59");
}
#include "guabiru.h"

Cidade* criaCidade(char *nome, char *desc)
{
    Cidade* c = (Cidade*) malloc (sizeof(Cidade));
    strcpy(c->nome, nome);
    strcpy(c->desc, desc);
    return c;
}

void mostraCidade(Cidade* c)
{
    printf("%s\n", c->nome);
    printf("%s\n", c->desc);
}

Cidade* buscaCidade(Mapa* m, char* c)
{
    for (int i = 0; i < m->tam; ++i)
    {
        if (strcmp(m->lista[i]->nome, c) == 0)
        {
            return m->lista[i];
        }
    }
    return NULL;
}

Parada* criaParada(Parada *ant, Cidade *atual, Parada *prox)
{
    Parada *p = (Parada*) malloc (sizeof(Parada));
    p->c = atual;
    p->ant_p = ant;
    p->prox_p = prox;
    return p;
}

void mostraParada(Parada *p)
{
    printf("PARADA: ");
    mostraCidade(p->c);
    if (p->ant_p != NULL)  {printf("PARADA ANTERIOR: %s\n", p->ant_p->c->nome);}
    if (p->prox_p != NULL) {printf("PROXIMA PARADA: %s\n", p->prox_p->c->nome);}
}

Mapa* criaMapa(char** lista_nomes, char** lista_descricoes, int n_cidades)
{
    Mapa* m = (Mapa*) malloc (sizeof(Mapa));
    for (int i = 0; i < n_cidades; ++i)
    {
        m->lista[i] = criaCidade(lista_nomes[i], lista_descricoes[i]);  // Adiciona cidade à lista do mapa
    }
    m->tam = n_cidades; // Tamanho do mapa é igual ao número de cidades presentes
    return m;
}

Rota* criaRota(Mapa* mapa, int tam_rota, char** cidades_rota, char horario[5]) 
{  //Pré-condição: Todas as cidades de 'cidades_rota' existem dentro de 'mapa'
    Rota* r = (Rota*) malloc(sizeof(Rota));
    strcpy(r->hora_chegada, horario);  // Passa 
    r->tam_rota = tam_rota;
    Parada *primeiro = criaParada(NULL,buscaCidade(mapa, cidades_rota[0]),NULL);
    Parada *atual, *ant; 
    r->inicio = primeiro; // O início da rota é a primeira cidade da lista 'cidades_rota'
    ant = primeiro;
    for (int i = 1; i < tam_rota; ++i)
    {
        Cidade* temp = buscaCidade(mapa, cidades_rota[i]);  // Busca cidade no mapa
        atual = criaParada(ant,temp,NULL);  // Cria uma parada temporária
        ant->prox_p = atual; // Ponteiro próximo recebe a cidade atual
        ant = atual; // A nova cidade anterior é a que criamos.
    }
    r->fim = atual;  // Última cidade é adicionada à rota
    return r;
}

void mostraRota(Rota *r)
{
    Parada* temp;
    temp = r->inicio;
    for (int i = 0; i < r->tam_rota; ++i)
    {
        printf("%s - ", temp->c->nome);
        temp = temp->prox_p;
    }
}

Painel* criaPainel()
{
    Painel* p = (Painel*) malloc (sizeof(Painel));

    return p;
}

void atualizaPainel(Painel* p, Rota** rotas, int n_rotas)  // TO DO
{
    for (int i = 0; i < n_rotas; ++i)
    {
        p->rotas[i] = rotas[i]
    }
}
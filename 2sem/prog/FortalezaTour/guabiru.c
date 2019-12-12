#include "guabiru.h"

Cidade* criaCidade(char* nome, char* desc)
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

Rota* criaRota(Mapa* mapa, int tam_rota, char** cidades_rota, int hora_chegada, int minuto_chegada) 
{  //Pré-condição: Todas as cidades de 'cidades_rota' existem dentro de 'mapa'
    Rota* r = (Rota*) malloc(sizeof(Rota));
    r->hora = hora_chegada;
    r->minuto =  minuto_chegada;
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
    p->n_rotas = 0;
    return p;
}

void mostraLista(char** lista, int n_elementos)
{
    for (int i = 1; i < n_elementos; ++i)
    {
        printf("%s - ", lista[i]);
    }
    
}

void mostraLocais(Painel* p)
{
    int n = p->n_rotas;
    printf("%d rotas\n", n);
    for (int i = 0; i < n; ++i)
    {
        printf("%s - ", p->rotas[i]->fim->c->nome);
    }
    printf("\n");
}


// Tendo a cidade e horário do usuário, verifica se os campos estão válidos (destino existe, hora correta, etc.)
void testeInvalidez(Painel* p, int n_rotas, char* local, char* hora);


// Cria um painel secundário a partir do primeiro, somente com as rotas desejadas pelo usuário
void adicionaDestinos(Painel* p, char* local, Painel* novo)
{
    //Painel* novo = (Painel*) malloc (sizeof(Painel));
    // novo->n_rotas = 0;
    int n_rotas = p->n_rotas;
    for (int i = 0; i < n_rotas; ++i)
    {
        char cidade_p[100];
        strcpy(cidade_p, p->rotas[i]->fim->c->nome);
        if (strcmp(cidade_p, local) == 0)  //Se a cidade do painel é a que o usuário quer:
        {
            novo->rotas[novo->n_rotas++] = p->rotas[i];
        }
    }
    if (novo->rotas[n_rotas - 1] == NULL) {printf("perdemo");}
}

// Escolhe a melhor rota para o usuário (com horário mais próximo àquele que o usuário quer)
Rota* melhorRota(Painel* p, int hr, int min)
{
    int husuario = (60*hr + min);  // Horario do usuario convertido em minutos
    int distancia_atual = 0;  // Distancia em minutos entre o usuario e a rota
    int distancia_melhor = 32767;  // Melhor distancia, inicializada com valor absurdo
    Rota* topissima = (Rota*) malloc (sizeof(Rota)); // Inicialmente, a melhor rota é a prieira
    for (int i = 0; i < (p->n_rotas); ++i)
    {
        distancia_atual = (60*p->rotas[i]->hora) + (p->rotas[i]->minuto);
        if ((distancia_atual - husuario) < 0)  // Se hora da rota for antes da hora do usuario
        {
            distancia_atual = ((1440 - (husuario - distancia_atual)));  // Rota só está disponível no próximo dia
        }
        if (distancia_atual < distancia_melhor)  // Se rota atual é mais perto que a "melhor" rota
        {
            topissima = p->rotas[i];  // Atual vira nova melhor
        }
    }
    return topissima;
}
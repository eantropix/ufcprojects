#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
//#include "circulo.h"
//#include "triangulo.h"

int testeSuitePonto() {
  
  Ponto *p = criaP(1, 1);
  if(p == NULL){
    printf("Teste Ponto - Falhou em criaP()");
    return -1;
  }
  
  float auxX, auxY;
  acessaP(p, &auxX, &auxY);
  if(auxX != 1 || auxY != 1){
    printf("Teste Ponto - Falhou em acessaP()");
    return -1;
  }
  
  atribuiP(p, -1, -1);
  acessaP(p, &auxX, &auxY);
  if(auxX != -1 || auxY != -1){
    printf("Teste Ponto - Falhou em atribuiP()");
    return -1;
  }
  
  Ponto *p1 = criaP(1, 1);
  Ponto *p2 = criaP(1, 1);
  
  if(distanciaP(p1, p2) != 0.0) {
    printf("Teste Ponto - Falhou em distanciaP()");
    return -1;    
  }
  
  liberaP(&p);
  if(p == NULL){
    printf("Teste Ponto - Falhou em liberaP()");
    return -1;
  }
  
  return 0;
}

/*
int testeSuiteCirculo() {
  Ponto *p = criaP(1.0, 1.0);
  Circulo *c = criaC(p, 1.0);
  if(c == NULL){
    printf("Teste Circulo - Falhou em criaC()");
    return -1;
  }
  float x, y, r;
  acessaC(c, &x, &y, &r);
  if(x != 1.0 || y != 1.0 || r != 1.0) {
    printf("Teste Circulo - Falhou em acessaC()");
    return -1;    
  }
  
  atribuiC(c, 2.0, 2.0, 2.0);
  acessaC(c, &x, &y, &r);
  if(x != 2.0 || y != 2.0 || r != 2.0) {
    printf("Teste Circulo - Falhou em atribuiC()");
    return -1;    
  }
  
  if(pertenceC(c, p) != 1) {
    printf("Teste Circulo - Falhou em pertenceC()");
    return -1;
  }
  
  float area = areaC(c);
  if(area < 12.56 || area > 12.57) {
    printf("Teste Circulo - Falhou em areaC()");
    return -1;  
  }

  liberaC(&c);
  if(c != NULL){
    printf("Teste Circulo - Falhou em liberaC()");
    return -1;
  }
  return 0;
}
/*
int testeSuiteTriangulo() {
  Ponto *p1 = criaP(0.0, 0.0);
  Ponto *p2 = criaP(1.0, 1.0);
  Ponto *p3 = criaP(2.0, 0.0);
  
  Triangulo *t = criaT(p1, p2, p3);
  
  if(t == NULL) {
    printf("Teste Triangulo - Falhou em criaT()");
    return -1;    
  }
  
  Ponto *auxP1, *auxP2, *auxP3;
  acessaT(t,auxP1, auxP2, auxP3);
  float distanciaP1 = distanciaP(p1, auxP1);
  float distanciaP2 = distanciaP(p2, auxP2);
  float distanciaP3 = distanciaP(p3, auxP3);
  
  if(distanciaP1 != 0.0 || distanciaP2 != 0.0 || distanciaP3 != 0.0) {
    printf("Teste Triangulo - Falhou em acessaT()");
    return -1;
  }
  
  Ponto *auxP1N, *auxP2N, *auxP3N;
  auxP1N = criaP(-1.0, 0.0);
  auxP2N = criaP(0.0, 1.0);
  auxP3N = criaP(1.0, 0.0);
  atribuiT(t, auxP1N, auxP2N, auxP3N);
  
  acessaT(t,auxP1, auxP2, auxP2);
  distanciaP1 = distanciaP(auxP1, auxP1N);
  distanciaP2 = distanciaP(auxP2, auxP2N);
  distanciaP3 = distanciaP(auxP3, auxP3N);  
  if(distanciaP1 != 0.0 || distanciaP2 != 0.0 || distanciaP3 != 0.0) {
    printf("Teste Triangulo - Falhou em atribuiT()");
    return -1;
  }  
  
  if(verificaT(t) != 1) {
    printf("Teste Triangulo - Falhou em verificaT()");
    return -1;    
  } 

  Ponto *p = criaP(0.5, 0.5);
  if(pertenceT(t, p) != 1) {
    printf("Teste Circulo - Falhou em pertenceT()");
    return -1;   
  }

  liberaT(&t);
  if(t != NULL){
    printf("Teste Circulo - Falhou em liberaT()");
    return -1;
  }
  
  return 0;
}
*/
int main(void) {
  int n;
  printf("Executando Bateria de Testes");
  if(testeSuitePonto() == 0) {
    printf("Teste Ponto - Sucesso!");
  } else {
    printf("Teste Ponto - Fallou!");
    return 0;
  }
  
  /*if(testeSuiteCirculo() == 0) {
    printf("Teste Circulo - Sucesso!");
  } else {
    printf("Teste Circulo - Fallou!");
    return 0;
  }
  
  if(testeSuiteTriangulo() == 0) {
    printf("Teste Circulo - Sucesso!");
  } else {
    printf("Teste Circulo - Fallou!");
    return 0;
  }*/
}
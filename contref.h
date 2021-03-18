#ifndef CONTREF_H_INCLUDED
#define CONTREF_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct contareferencias{
    struct contareferencias *prox;
    void *endereco;
    int cont;
}contareferencias;

void arrumacontador(void *end1, int m);

contareferencias *removelixo(contareferencias *l);

void dump();

void atrib2(void **end1, void *end2);

void *atrib3(void *end1, void *end2);

void *malloc2(int tam);

void *malloc3(void *end1, int tam);

void encerra();

#endif // CONTREF_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct contareferencias{
    struct contareferencias *prox;
    void *endereco;
    int cont;
}contareferencias;
contareferencias *listareferencias = NULL;

void arrumacontador(void *end1, int m){
    contareferencias *aux = listareferencias;
    while(aux != NULL){
        if(aux->endereco == end1){
            aux->cont = aux->cont + m;
            break;
        }
        aux = aux->prox;
    }
}

contareferencias *removelixo(contareferencias *l){
    if(l != NULL){
        if(l->cont == 0){
            l->prox = removelixo(l->prox);
            contareferencias *aux = l->prox;
            free(l);
            return aux;
        }
        else{
            l->prox = removelixo(l->prox);
            return l;
        }
    }
    return NULL;
}

void dump(){
    contareferencias *aux = listareferencias;
    printf("----- dump -----\n");
    while(aux != NULL){
        printf("[Endereco: %p, Referencias: %d]\n", aux->endereco, aux->cont);
        aux = aux->prox;
    }
    printf("----------------\n\n");
}

void atrib2(void **end1, void *end2){
    arrumacontador(*end1, -1);
    arrumacontador(end2, 1);
    listareferencias = removelixo(listareferencias);
    *end1 = end2;
}

void *atrib3(void *end1, void *end2){
    arrumacontador(end1, -1);
    arrumacontador(end2, 1);
    listareferencias = removelixo(listareferencias);
    return end2;
}

void *malloc2(int tam){
    contareferencias *aux = listareferencias;
    listareferencias = malloc(sizeof(contareferencias));
    listareferencias->prox = aux;
    listareferencias->endereco = malloc(tam);
    listareferencias->cont = 1;
    return listareferencias->endereco;
}

void *malloc3(void *end1, int tam){
    arrumacontador(end1, -1);
    listareferencias = removelixo(listareferencias);
    contareferencias *aux = listareferencias;
    listareferencias = malloc(sizeof(contareferencias));
    listareferencias->prox = aux;
    listareferencias->endereco = malloc(tam);
    listareferencias->cont = 1;
    return listareferencias->endereco;
}

void encerra(){
    while(listareferencias != NULL){
        contareferencias *aux = listareferencias->prox;
        free(listareferencias->endereco);
        free(listareferencias);
        listareferencias = aux;
    }
}

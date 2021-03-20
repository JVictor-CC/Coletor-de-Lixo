#include <stdlib.h>
#include <stdio.h>
#include "countref.h"

memoria *listaRef = NULL;

void *malloc2(int size_){
    void *novaAlloc = (void *)malloc(size_);
    memoria *novaRef = (memoria *)malloc(sizeof(memoria));
    novaRef->endereco = novaAlloc;
    novaRef->contaR = 1;
    novaRef->prox = NULL;
    if (listaRef == NULL){
        listaRef= novaRef;
    }
    else{
        memoria *aux = listaRef;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novaRef;
    }
    return novaAlloc;
}

void atrib2(void **receptor, void *transmissor){
    if ((*receptor) != NULL){
        memoria *leLista = listaRef;
        while (leLista->endereco != (*receptor)){
            leLista = leLista->prox;
        }
        at_ListaRef(leLista, -1);
        if (transmissor != NULL){
            (*receptor) = transmissor;
            leLista = listaRef;
            while (leLista->endereco !=transmissor){
                leLista = leLista->prox;
            }
            at_ListaRef(leLista, 1);
        }
        else{
            (*receptor)=NULL;
        }
    }
}

void at_ListaRef(memoria *componente, int contaR){

    componente->contaR += contaR;
    if (componente->contaR == 0){
        if (listaRef->prox != NULL){
            memoria *pass = listaRef;
            if (pass !=componente){
                while (pass->prox != componente){
                    pass = pass->prox;
                }
                pass->prox = componente->prox;
            }
            else{
                listaRef = componente->prox;
            }
        }
        free(componente->endereco);
        free(componente);
    }
}

void limpaLixo(){

    memoria *aux=listaRef;
    while (aux!=NULL){
        free(aux->endereco);
        free(aux);
        aux=aux->prox;
    }
}

void printaReferencia(){

    memoria *aux=listaRef;
    while (aux!=NULL){
        printf("Endereço:%d\t",aux->endereco);
        printf("ref:%d\n",aux->contaR);
        aux=aux->prox;
    }
}


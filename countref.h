#ifndef COUNTREF_H
#define COUNTREF_H

typedef struct memoria{
    void *endereco;
    int contaR;
    struct memoria *prox;
}memoria;

void *malloc2(int size_);
void atrib2(void **receptor,void *transmissor);
void limpaLixo();
void printaReferencia();
void at_ListaRef(memoria *componente,int contaR);


#endif // COUNTREF_H

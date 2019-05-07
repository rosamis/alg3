#ifndef ARVORE_A_H
#define ARVORE_A_H

#include "arvoreB.h"

typedef struct arvoreA_s arvoreA_t;

struct arvoreA_s{
    int index;
    arvoreB_t *chave;
    arvoreA_t *dir, *esq, *pai;
};

arvoreA_t* criaNoA(arvoreB_t* arvB);
arvoreA_t* inclusaoA(arvoreA_t* atual, arvoreB_t* arvB, int index, arvoreA_t* pai);
int vaziaA(arvoreA_t* no);
void imprimeA(arvoreA_t* no);
int calculaIndex(arvoreB_t *elem);
arvoreA_t* busca(arvoreA_t *no, int indexB);
arvoreA_t* minimo (arvoreA_t* no);
arvoreA_t* sucessor(arvoreA_t* no);
void remocao(arvoreA_t* no);


#endif
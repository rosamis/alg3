#include <stdio.h>
#include <stdlib.h>
#include "arvoreA.h"
#include "arvoreB.h"
#include "busca.h"

arvoreB_t* criaNoB(int chave){
    arvoreB_t* arvore = (arvoreB_t*)malloc(sizeof(arvoreB_t)); 

    arvore->esq = NULL; 
    arvore->dir = NULL;
    arvore->pai = NULL;
    arvore->chave = chave;

    return arvore;
}

//INCLUSÃO

arvoreB_t* inclusaoB(arvoreB_t* no, int chave){
    if (no == NULL){
        no = (arvoreB_t*)malloc(sizeof(arvoreB_t)); 
    
        if (no == NULL) {
            printf("NULL");
            return NULL;
        }

        return no = criaNoB(chave);
    }

    if (chave < no->chave)
        no->esq = inclusaoB(no->esq,chave);

    if (chave > no->chave)
        no->dir = inclusaoB(no->dir,chave);

    return no;
}

int vaziaB(arvoreB_t* no){

  return no == NULL;
}

//IMPRESSÃO

void imprimeB(arvoreB_t* no){
    printf("(");
    if(!vaziaB(no)){
        printf("%d", no->chave);
        if(no->dir != NULL || no->esq != NULL){
            imprimeB(no->esq);
            imprimeB(no->dir);
        }
    }
    printf(")");
}
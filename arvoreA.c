#include <stdio.h>
#include <stdlib.h>
#include "arvoreA.h"
#include "arvoreB.h"
#include "busca.h"

arvoreA_t* criaNoA(arvoreB_t* arvB){
    arvoreA_t* arvore = (arvoreA_t*)malloc(sizeof(arvoreA_t));

    arvore->esq = NULL;
    arvore->dir = NULL;
    arvore->pai = NULL;
    arvore->index = calculaIndex(arvB);
    arvore->chave = arvB;

    return arvore;
}

//INCLUSÃO

arvoreA_t* inclusaoA(arvoreA_t* atual, arvoreB_t* arvB, int index, arvoreA_t* pai){    
    if (atual == NULL){
        atual = (arvoreA_t*)malloc(sizeof(arvoreA_t));

        if (atual == NULL) {
            printf("NULL");
            return NULL;
        }
        
        atual = criaNoA(arvB);
        if (atual != pai)
            atual->pai = pai;
    }
    
    if (index < atual->index)
        atual->esq = inclusaoA(atual->esq,arvB,index,atual);

    if (index > atual->index)
        atual->dir = inclusaoA(atual->dir,arvB,index,atual);

    return atual;

}

int vaziaA(arvoreA_t* no){

    return no == NULL;
}

// IMPRESSÃO
void imprimeA(arvoreA_t* no){
    printf("\n[");
    if(!vaziaA(no)){
        if(no->chave)
            imprimeB(no->chave);
        printf(":%d", no->index);
        if(no->dir != NULL || no->esq != NULL){
            imprimeA(no->esq);
            imprimeA(no->dir);
        }
    
    }

    printf("\n]");
}

int calculaIndex(arvoreB_t *elem){
    if (elem == NULL)
        return 0;
    else{
        int soma = 0;
        soma += calculaIndex(elem->esq);
        soma += calculaIndex(elem->dir);
        soma += elem->chave;
        return soma;
    }
}

//BUSCA
arvoreA_t* busca(arvoreA_t *no, int indexB){
    if (no == NULL){
        printf("\n Elemento não existente na árvore A. \n");
        return  NULL;
    }
    if (no->index == indexB){
        imprimeB(no->chave);
        printf(":%d", no->index);
        return no;
    }
    if (indexB < no->index){
        imprimeB(no->chave);
        printf(":%d", no->index);
        printf("\n");
        return busca(no->esq, indexB);
    }else{
        imprimeB(no->chave);
        printf(":%d", no->index);
        printf("\n");
        return busca(no->dir, indexB);
    }
}

arvoreA_t* minimo (arvoreA_t* no){
    if(no->esq == NULL)
        return no;
    
    else
        return minimo(no->esq);
}

arvoreA_t* sucessor(arvoreA_t* no){
    if(no->dir != NULL)
        return minimo(no->dir);
    
    else{
        arvoreA_t* s = no->pai;
        while(s != NULL && no == s->dir){
            no = s;
            s = s->pai;
        }
        return s;
    }
}

//REMOÇÃO

void remocao(arvoreA_t* no){
    arvoreA_t* Aux = no;    

    if (no->esq == NULL && no->dir == NULL){         
        if(no->pai != NULL){
            if (no->pai->esq == no)
                no->pai->esq = NULL;
            else 
                no->pai->dir = NULL;
        }
        free(Aux);
    }else{    
        if (no->esq == NULL){
            if(no->pai != NULL){
                if (no->pai->esq == no)
                    no->pai->esq = no->dir;
                else 
                    no->pai->dir = no->dir;
                
            }
            no->dir->pai = no->pai;
            free(Aux);
        }else{        
            if (no->dir == NULL){
                if(no->pai != NULL){
                    if (no->pai->esq == no)
                        no->pai->esq = no->esq;
                    else 
                        no->pai->dir = no->esq;
                    
                }
                no->esq->pai = no->pai;
                free(Aux);
            }else{      
                Aux = sucessor(no); 
                Aux->esq = no->esq;   
                no->esq->pai = Aux;
                if(no->pai != NULL){
                    if (no->pai->esq == no)
                        no->pai->esq = Aux;
                    else 
                        no->pai->dir = Aux;
                }
                Aux->pai = no->pai;
                free(no);
            }
        }
    }
}
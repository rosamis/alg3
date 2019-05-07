#ifndef ARVORE_B_H
#define ARVORE_B_H

typedef struct arvoreB_s arvoreB_t;

struct arvoreB_s {
    int chave;
    arvoreB_t *dir, *esq, *pai;
};

arvoreB_t* criaNoB(int chave);
arvoreB_t* inclusaoB(arvoreB_t* no, int chave);
int vaziaB(arvoreB_t* no);
void imprimeB(arvoreB_t* no);

#endif
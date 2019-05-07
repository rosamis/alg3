#ifndef BUSCA_H
#define BUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include "arvoreA.h"
#include "arvoreB.h"

void zeraVetor(char numero[50]);
arvoreB_t* percorreVetor(char vet [100]);
arvoreA_t* trataVetor(char vet[100], arvoreA_t* arvA);
arvoreA_t* leArquivo(FILE* fp);

#endif 

#include <stdio.h>
#include <stdlib.h>
#include "busca.h"
#include "arvoreA.h"
#include "arvoreB.h"


//FUNÇÕES DE LER ARQUIVO

void zeraVetor(char numero[50]){
    int j;
    for(j = 0; j<50; j++)
        numero[j] = '\0';
}

arvoreB_t* percorreVetor(char vet [100]){
    int i = 1, j = 0;
    char numero[50], *ptr;
    arvoreB_t* arvB = NULL;
    zeraVetor(numero);
    while(vet[i] != '\0'){
        if (vet[i] == 32){}
        else if (vet[i] == 40){}
        else if (vet[i] == 41){}
        else if (vet[i] > 47 && vet [i] < 58){
            while (vet[i] != 32 && vet[i] != 40 && vet[i] != 41){
                numero[j] = vet[i];
                i++;
                j++;
            }

            int val = strtol(numero,&ptr ,10);
            arvB = inclusaoB(arvB,val);
            zeraVetor(numero);
            j = 0;

        }
        i++;
    }
    return arvB;

}

arvoreA_t* trataVetor(char vet[100], arvoreA_t* arvA){
    arvoreB_t* arvB = NULL;
    arvoreA_t* arvAuxA = NULL;
    int i = 0, index =0;
    if (vet [i] == 'i'){
        printf("\n");
        arvB = percorreVetor(vet);
        index = calculaIndex(arvB);
        arvA = inclusaoA(arvA,arvB,index,arvA);
        
    }
    else if (vet [i] == 'b'){
        printf("\n");
        arvB = percorreVetor(vet);
        index = calculaIndex(arvB);
        printf("\n");
        arvAuxA = busca(arvA,index);
        

    }else if (vet [i] == 'r'){
        printf("\n");
        arvB = percorreVetor(vet);
        index = calculaIndex(arvB);
        printf("\n");
        arvAuxA = busca(arvA,index);
        printf("\n");
        remocao(arvAuxA);  

    }

    imprimeA(arvA);
    
    return arvA;
    
}

arvoreA_t* leArquivo(FILE* fp){
    arvoreA_t* arvA = NULL;
    if (fp == NULL)
        printf("Erro na abertura do arquivo!\n");
    char c;
    char num[100];
    char *resultado;
    while(!feof(fp)){
        resultado = fgets(num, 100, fp); 

        if (resultado)
            arvA = trataVetor(num,arvA);
        
    }
    
    fclose(fp);

    return arvA;
}

int main (int argc, char *argv[]){
    arvoreA_t* node2 = NULL;

    FILE* fp = fopen(argv[1], "r");
 
    node2 = leArquivo(fp);
 
    return 0;
}
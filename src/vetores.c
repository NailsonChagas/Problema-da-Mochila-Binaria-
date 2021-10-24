#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"

int* alocar_vetor_int(int n){
    int *v = NULL;

    if(n > 0){
        v = (int*)malloc(sizeof(int) * n);
    }

    return v;
}

int** alocar_matriz_int(int l, int c){
    int **m = NULL;

    if(l>0 && c>0){
        int i;

        m = (int**)malloc(sizeof(int*) * l);
        
        for(i=0; i<l; i++){
            m[i] = (int*)malloc(sizeof(int) * c);
        }
    }

    return m;
}

void imprimir_vetor_int(int *v, int n){
    if(v != NULL){
        int i;

        printf("Vetor[%d]:", n);
        for(i=0; i<n; i++){
            printf(" %d", v[i]);
        }
        printf("\n");
    }
    else{
        printf("\nVETOR INVALIDO\n");
    }
}

void imprimir_matriz_int(int **m, int l, int c){
    if(m != NULL){
        int i, j;

        printf("Matriz[%d][%d]:\n", l, c);
        for(i=0; i<l; i++){
            for(j=0; j<c; j++){
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("\nMATRIZ INVALIDA\n");
    }
}

void desalocar_vetor_int(int *v){
    if(v != NULL){
        free(v);
    }
}

void desalocar_matriz_int(int **m, int l){
    if(m != NULL){
        int i;

        for(i=0; i<l; i++){
            free(m[i]);
        }

        free(m);
    }
}

int soma_recursiva_dos_elementos_positivos_de_um_vetor(int *v, int tamanho){
    if(tamanho==1){
        if(v[tamanho-1] >= 0){
            return v[tamanho-1];
        }
        else{
            return 0;
        }
    }
    else{
        if(v[tamanho-1] >= 0){
            return v[tamanho-1] + soma_recursiva_dos_elementos_positivos_de_um_vetor(v, tamanho-1);
        }
        else{
            return soma_recursiva_dos_elementos_positivos_de_um_vetor(v, tamanho-1);
        }
    }
}

int divisao_conquista_soma_elementos_positivos_vetor(int *v, int inicio, int fim){ //inspirado no quick sort
    int meio;

    meio = (inicio + fim)/2;

    if(inicio >= fim){//caso o tamanho do vetor seja minimimo(tamanho 1) resolva
        if(v[inicio] > 0){
            return v[inicio];
        }
        else{
            return 0;
        }
    }
    else{//não é minimo: dividir o vetor
        return divisao_conquista_soma_elementos_positivos_vetor(v, inicio, meio) + divisao_conquista_soma_elementos_positivos_vetor(v, meio + 1, fim);
    }
}

//objetivo é carregar o máximo de peso na mochila maximisando o valor
//a matriz que guarda os valores seta de tamanho (numeroObjetos + 1) x (capacidadeMochila + 1)
//cada coluna "sera uma mochila com peso correspondente a seu indice"
//alocar mochila -> zerar a mochila(para n haver erro nas somas) -> verificar se pode inserir -> somar com o valor que já está na mochila
int mochila_binaria(int **objetos, int numeroObjetos, int capacidadeMochila){
    int resultado = -1;

    if(objetos != NULL){
        int **mochila, i, j;

        //alocando a mochila
        mochila = alocar_matriz_int(numeroObjetos + 1, capacidadeMochila + 1);

        //zerando a mochila
        for(i=0; i<(numeroObjetos+1); i++){
            for(j=0; j<(capacidadeMochila+1); j++){
                mochila[i][j] = 0;
            }
        }

        //o algoritmos
        for(i=1; i<(numeroObjetos+1); i++){
            for(j=1; j<(capacidadeMochila+1); j++){
                if(objetos[i-1][0] <= j){ //se o peso do objeto for menor ou igual ao peso da "coluna mochila" é possivel inserir
                    mochila[i][j] = mochila[i-1][j - objetos[i-1][0]] + objetos[i-1][1]; //soma com o que já esta na mochila
                }
                else{
                    mochila[i][j] = mochila[i-1][j]; //mochila cheia: repetir o valor anterior
                }
                //imprimir_matriz_int(mochila, numeroObjetos+1, capacidadeMochila+1);
            }
        }

        resultado = mochila[numeroObjetos][capacidadeMochila]; //esse elemento vai ser a soma total de todos valores de elementos na mochila

        desalocar_matriz_int(mochila, numeroObjetos + 1);
    }
    return resultado;
}
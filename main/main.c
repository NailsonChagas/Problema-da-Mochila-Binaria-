//objetivo é carregar o máximo de peso na mochila maximisando o lucro

//a matriz que guarda os valores seta de tamanho (numeroObjetos + 1) x (capacidadeMochila + 1)
//cada coluna "sera uma mochila com peso correspondente a seu indice"

#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"


int main(void){
    int nObjetos, **objetos, i, capacidadeMochila;

    scanf("%d", &capacidadeMochila);

    scanf("%d", &nObjetos);
    objetos = alocar_matriz_int(nObjetos, 2);

    for(i=0; i<nObjetos; i++){
        scanf("%d %d", &objetos[i][0], &objetos[i][1]);//peso / valor
    }

    //imprimir_matriz_int(objetos, nObjetos, 2);
    i = mochila_binaria(objetos, nObjetos, capacidadeMochila);

    printf("\n%d", i);

    desalocar_matriz_int(objetos, nObjetos);

    return 0;
}
/*Alocando*/
int* alocar_vetor_int(int n);
int** alocar_matriz_int(int l, int c);

/*Imprimindo*/
void imprimir_vetor_int(int *v, int n);
void imprimir_matriz_int(int **m, int l, int c);

/*Desalocando*/
void desalocar_vetor_int(int *v);
void desalocar_matriz_int(int **m, int l);

/*Operações*/
int soma_recursiva_dos_elementos_positivos_de_um_vetor(int *v, int tamanho);
int divisao_conquista_soma_elementos_positivos_vetor(int *v, int inicio, int fim);
int mochila_binaria(int **objetos, int numeroObjetos, int capacidadeMochila);
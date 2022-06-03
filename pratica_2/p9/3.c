//Milena Santana de Almeida, 21.1.4175

//Bibliotecas 
#include <stdio.h>
#include <stdlib.h>


// Aloca espaço para uma matriz m x n. Se não for possı́vel criar a matriz, retorna NULL
int** cria_matriz(int m, int n);

// Multiplica 2 matrizes.
int multiplica_matrizes(int ***R, int **A, int n, int m, int **B, int p, int q);

// Libera o espaço utilizado por uma matriz.
void desaloca_matriz(int** A, int m);

//Funções

// Aloca espaço para uma matriz m x n. Se não for possı́vel criar a matriz, retorna NULL
int** cria_matriz(int m, int n){
    //Caso não seja uma matriz
    if((m == 0) || (n == 0)){ return NULL; }

    //matriz temporaria
    int **temp = malloc(m * sizeof(int*));
    
    //Entrada do vetor temporario
    for(int i = 0; i < m; i++){
        temp[i] = malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            scanf("%d", &temp[i][j]);
        }
    }
    return temp;
}

// Multiplica 2 matrizes.
int multiplica_matrizes(int ***R, int **A, int n, int m, int **B, int p, int q){
    //Caso seja impossivel  multiplicar
    if(m != p){ return 0; }

    //Variaveis da função
    int temp;

    //Dimensionando a matriz resultante
    *R = malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        (*R)[i] = malloc(q * sizeof(int));
        for (int j = 0; j < q; j++){
            temp = 0;
            for(int k = 0; k < m; k++){
                temp += A[i][k] * B[k][j];
            }
            (*R)[i][j] = temp;
        }
    }

    return 1;
}

// Libera o espaço utilizado por uma matriz.
void desaloca_matriz(int** A, int m){
    for(int i = 0; i < m; i++){
        free(A[i]);
    }

    free(A);
}

int main(){
    //Variaveis
    int n, m, p, q;

    //Define a dimensão da matriz A
    printf("Digite os tamanhos da matriz A (n x m): "); scanf("%d %d", &n, &m);

    printf("Digite os dados da matriz A: \n");
    int **A = cria_matriz(n, m);
    
    //ERRO
    while(A == NULL){
        printf("ERRO!!!! (n || m) == 0 : Digite os tamanhos da matriz A (n x m): "); scanf("%d %d", &n, &m);
        
        printf("Digite os dados da matriz A: \n");
        A = cria_matriz(n, m);
    }

    //Define a dimensão da matriz B
    printf("Digite os tamanhos da matriz B (p x q): "); scanf("%d %d", &p, &q);
    
    printf("Digite os dados da matriz B: \n");
    int **B = cria_matriz(p, q);
    
    //ERRO
    while(B == NULL){
        printf("ERRO!!!! (p || q) == 0 : Digite os tamanhos da matriz B (p x q): "); scanf("%d %d", &p, &q);
        
        printf("Digite os dados da matriz B: \n");
        B = cria_matriz(p, q);
    }

    //Matriz resultado
    int **R;

    switch( multiplica_matrizes(&R, A, n, m, B, p, q)){
        case 0:
            printf("Não é possı́vel multiplicar as matrizes A e B. \n");
            break;
        
        case 1:
            //Saida
            printf("Resultado de A x B:\n");
            for(int i = 0; i < n; i++){
                for(int j = 0; j < q; j++){
                    printf("%d ", R[i][j]);
                }
                printf("\n");
            }
            desaloca_matriz(R, n);
            break;
    }
    
    //Libera as matrizes
    desaloca_matriz(A, n);
    desaloca_matriz(B, p);

    return 0;
}
//Milena Santana de Almeida, 21.1.4175

//Bibliotecas 
#include <stdio.h>
#include <stdlib.h>

//Prototipo das funções

// Recebe uma matriz e seus ı́ndices e retorna a matriz transposta
double** cria_transposta(double **A, int m, int n);

// Aloca espaço para uma matriz m x n. Se não for possı́vel criar a matriz, retorna NULL
double** cria_matriz(int m, int n);

// Libera o espaço utilizado por uma matriz.
void desaloca_matriz(double** A, int m);

//Funções

// Recebe uma matriz e seus ı́ndices e retorna a matriz transposta
double** cria_transposta(double **A, int m, int n){
    //matriz temporaria
    double **temp = malloc(n * sizeof(int*));
  
    //Entrada do vetor temporario, com o inverso do vetor parametro
    for(int i = 0; i < n; i++){
        temp[i] = malloc(m * sizeof(int));
        for(int j = 0; j < m; j++){
            temp[i][j] = A[j][i];
        }
    }
    return temp;
}

// Aloca espaço para uma matriz m x n. Se não for possı́vel criar a matriz, retorna NULL
double** cria_matriz(int m, int n){
    //Caso não seja uma matriz
    if((m == 0) || (n == 0)){ return NULL; }

    //matriz temporaria
    double **temp = malloc(m * sizeof(double*));
    
    //Entrada do vetor temporario
    for(int i = 0; i < m; i++){
        temp[i] = malloc(n * sizeof(double));
        for(int j = 0; j < n; j++){
            scanf("%lf", &temp[i][j]);
        }
    }

    return temp;
}

// Libera o espaço utilizado por uma matriz.
void desaloca_matriz(double** A, int m){
    for(int i = 0; i < m; i++){
        free(A[i]);
    }

    free(A);
}

int main(){
    //Variaveis
    int m, n;

    //Define a dimensão da matriz
    printf("Digite os tamanhos da matriz A (m x n): "); scanf("%d %d", &m, &n);
    printf("Digite os dados da matriz: \n");
    double **v = cria_matriz(m, n);
    
    //ERRO
    while(v == NULL){
        printf("ERRO!!!! (m || n) == 0 : Digite o tamanho da matriz (m x n): "); scanf("%d %d", &m, &n);
        v = cria_matriz(m, n);
    }

    //Processamento
    double **a = cria_transposta(v, m, n);

    //Saida
    printf("\nVetor original:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%.2lf ", v[i][j]);
        }
        printf("\n");
    }

    //Saida
    printf("\nVetor trasposto:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
    
    desaloca_matriz(v, m);
    desaloca_matriz(a, n);

    return 0;
}
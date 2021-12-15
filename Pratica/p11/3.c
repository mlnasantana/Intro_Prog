//Milena Santana, 21.1.4175

#include <stdio.h>
#include <stdlib.h>

int** le_matriz(char c, int *m, int *n){
    //criando a matriz
    printf("Digite os tamanhos da matriz %c: ", c);
    scanf("%d %d", m, n);
    int **matriz = malloc(*m * sizeof(int*));
    for (int i = 0; i < *m; i++)
        matriz[i] = malloc(*n * sizeof(int));

    //lendo os valores da matriz
    printf("Digite os dados da matriz %c: \n", c);
    for (int i = 0; i < *m; i++){
        for (int  j = 0; j < *n; j++)
            scanf("%d", &matriz[i][j]);
    }
     return matriz;  
}

int multiplica_matrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q){
    if(n == q){
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < q; j++) {
                    (*R)[i][j] = 0;
                    for(int x = 0; x < m; x++)
                        (*R)[i][j] +=  A[i][x] * B[x][j];
                }
            }
        return 1;
    }
    return 0;
}

void desaloca_matriz(int** A, int m){
    for (int i = 0; i < m; i++)
        free(A[i]);
    free(A);
}


int main(){
    int m, n, p, q, result;
   
    int **a = le_matriz('A', &n, &m);
    int **b = le_matriz('B', &p, &q);
    int **r = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        r[i] = malloc(q * sizeof(int));
    
    result = multiplica_matrizes(&r, a, n, m, b, p, q);
    if(result == 1){
        printf("Resultade de A x B:\n");
        for (int i = 0; i < n; i++){
            for (int j = 0; j < q; j++)
                j > 0 ? printf(" %d\n", r[i][j]) : printf(" %d", r[i][j]);
        }
    }else
        printf("Nao eh possivel multiplicar as matrizes A e B.");
    
    desaloca_matriz(a, m);
    desaloca_matriz(b, p);
    desaloca_matriz(r, n);
    
    return 0;
}
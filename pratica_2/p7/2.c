//Milena Santana, 21.1.4175, turma 33

//Bibliotecas 
#include <stdio.h>

//dimensão matriz
#define t_max 10

//prototipo das funções
void ler(int a[][t_max], int x, int y);
void imprimir(int a[][t_max], int x, int y);

//Funções
void ler(int a[][t_max], int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("[%d][%d]: ", i, j); scanf("%d", &a[i][j]);
        }
    }
}

void imprimir(int a[][t_max], int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}


int main(){
    //Variaveis
    int m, p, q, n, soma = 0;

    //Dimensões da primeira matriz
    printf("Qual o numero de linhas e colunas da matriz A: "); scanf("%d %d", &m, &p);

    //Dimensões da segunda matriz
    printf("Qual o numero de linhas e colunas da matriz B: "); scanf("%d %d", &q, &n);

    //Erro
    while ((p != q) || (p > 10) || (m > 10) || (n > 10)){
        printf("ERRO: o numro de colunas da matriz A deve ser igual ao numero de linhas da matriz B e as dimensões não podem ser maior que 10\n");
        //Dimensões da primeira matriz
        printf("Qual o numero de linhas e colunas da matriz A: "); scanf("%d %d", &m, &p);
        //Dimensões da segunda matriz
        printf("Qual o numero de linhas e colunas da matriz B: "); scanf("%d %d", &q, &n);
    }
    
    //Matrizes
    int a[m][t_max], b[q][t_max], c[m][t_max];

    //Entradas das Matrizes A e B 
    printf("Digite os valores da matriz A\n");
    ler(a, m, p);

    printf("Digite os valores da matriz B\n");
    ler(b, p, n);
    
    //Matriz produto
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < p; k++){
                soma += a[i][k] * b[k][j];
            }
            c[i][j] = soma;
            soma = 0;
        }
    }
    
    printf("\n");
    //Imprimir matriz do produto
    imprimir(c, m, n);
    
    return 0;
}
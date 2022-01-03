//Milena Santana, 21.1.4175

#include <stdio.h>

//Tamanho do vetor
#define t_vetor 15

int main(){
    //Variaveis
    int n = 0, vetor[t_vetor];

    //Entrada
    for(int i = 0; i < t_vetor; i++){
        printf("Qual o valor da posição %d no vetor: ", i + 1); scanf("%d", &vetor[i]);
    }
    printf("Quantas posições serão rotacionadas: "); scanf("%d", &n);

    //Vetor copia com os n valores do vetor
    int copia[n];
    for(int i = 0; i < n; i ++){copia[i] = vetor[i];}

    //Movimenta os valores para esquerda
    for(int i = 0; i < t_vetor - n; i++){
        vetor[i] = vetor [i + n];
    }

    //Adicona o vetor copia a direita dos valores do vetor
    for(int i = 0; i < n; i++){
        vetor[(t_vetor - n) + i] = copia[i];
    }

    //Imprime o vetor
    for (int i = 0; i < t_vetor; i ++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
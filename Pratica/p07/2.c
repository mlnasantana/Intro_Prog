// Milena Santana, 21.1.4175
 
#include <stdio.h>

//Tamanho do vetor
#define t_vetor 30

int main(){
    //Variaveis
    double temp[t_vetor];
    double media = 0;
    int menor = 0, maior = 0;

    //Entrada
    for (int i = 0; i < t_vetor; i++){
        printf("Digite a temperatura do dia %d: ", i+1); scanf("%lf", &temp[i]);
    }

    //Calcula a media
    for (int i = 0; i < t_vetor; i++){media += temp[i];}
    media /= t_vetor;

    //Quantos estão a baixo ou acima da media
    for (int i = 0; i < t_vetor; i++){
        //Se for acima da media
        if(temp[i] > media){maior++;}
        //Se for abaixo da media
        if(temp[i] < media){menor++;}
    }

    //Saida
    printf("%d estão acima da media e %d estão abaixo da media\n", maior, menor);

    return 0;
}
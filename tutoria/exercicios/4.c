/*um comerciante comprou um produto e quer vende-lo com 
um lucro de 45% se o seu valor for menor que R$20,00.
caso contrario, o lucro sera de 30%
crie um programa para ler o valor de um unico produto
e imprimir o valor de venda, ja com o lucro embutido*/


#include<stdio.h>
#include <math.h>

int main(){ 
    double produto;

    printf("informe o valor do produto:");
    scanf("%lf", &produto);

    if(produto < 20){
        printf("o produto podera ser vendido com o lucro de 45%% = %2.lf", produto * 1.45);
    }else{
        printf("o produto podera ser vendido com o lucro de 30%% = %2.lf", produto * 1.30);
    }

    return 0;
}
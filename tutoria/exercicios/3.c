/*crie um programa que leia dois numeros, imprima o quadrado
do menor e a raiz quadrada do maior. 
o programa deve tambem detectar se os numeros são iguais
neste caso, as operaçoes nao devem ser realizadas.*/

#include <stdio.h>
#include<math.h>

int main(){
    double n1, n2, menor = 0;

    printf("digite um numero:");
    scanf("%lf", &n1);
    printf("digite outro numero:");
    scanf("%lf", &n2);

    if(n1 > n2){
        menor = n2 * n2;
        printf("quadrado do menor =%2.f\n", menor);
        printf("raiz quadrada do maior =%f", sqrt(n1));
    }
    if(n2 > n1){
        menor = n1 * n1;
        printf("quadrado do menor =%2.f\n", menor);
        printf("raiz quadrada do maior = %f", sqrt(n2));
    }

 return 0;
}
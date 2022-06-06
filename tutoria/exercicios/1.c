/*crie um programa que leia 5 numeros inteiros
e determine qual deles é o menor. imprima o resultado na tela.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
   int num, menor = 0, y = 0;

       printf("Informe um numero: ");
       scanf("%d", &num);
    menor = num;

    for (y = 1; y < 5; y++){
        printf("digite mais um numero:");
        scanf("%d", &num);

         if(num < menor) menor = num;
    }
   printf("Menor valor: %d", menor);

   return 0;
}
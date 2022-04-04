//Milena Santana de Almeida, 21.1.4175 turma 33

/*Escreva um programa que leia de 3 números inteiros. Em seguida, o programa deve verificar qual dos
valores é o menor, o intermediário e o maior.
Supondo as entradas 23, 11, 31, a saı́da do programa seria:
Menor: 11
Intermediario: 23
Maior: 31
*/

//Biblioteca
#include <stdio.h>


int main(){  
  
   //Variaveis
  int numero_1, numero_2, numero_3;
    
    printf("Digite um numero: ");
    scanf("%d", &numero_1);
    printf("Digite outro numero: ");
    scanf("%d", &numero_2);
    printf("Digite mais outro numero: ");
    scanf("%d", &numero_3);

    if((numero_1 > numero_2) && (numero_1 > numero_3) && (numero_2 > numero_3)){
        printf("Menor: %d\nIntermediario:  %d\nMaior: %d\n", numero_3, numero_2, numero_1);
    }
    
    //Probabilidade 2
    if((numero_1 > numero_2) && (numero_1 > numero_3) && (numero_2 < numero_3)){
        printf("Menor: %d\nIntermediario: %d\nMaior: %d\n", numero_2, numero_3, numero_1);
    }
    
    if((numero_1 > numero_2) && (numero_1 < numero_3)){
        printf("Menor: %d\nIntermediario: %d\nMaior: %d\n", numero_2, numero_1, numero_3);
    }
    
    if((numero_1 < numero_2) && (numero_1 > numero_3)){
        printf("Menor: %d\nIntermediario: %d\nMaior: %d\n", numero_3, numero_1, numero_2);
    }
    
    if((numero_1 < numero_2) && (numero_1 < numero_3) && (numero_2 > numero_3)){
        printf("Menor: %d\nIntermediario: %d\nMaior: %d\n", numero_1, numero_3, numero_2);
    }

    if((numero_1 < numero_2) && (numero_1 < numero_3) && (numero_2 < numero_3)){
        printf("Menor: %d\nIntermediario: %d\nMaior: %d\n", numero_1, numero_2, numero_3);
    }
    
    if(numero_1 == numero_2){
        if(numero_1 > numero_3){
            printf("Menor: %d\nMaior: %d\n", numero_3, numero_1);
        }
        else{
             printf("Menor: %d\nMaior: %d\n", numero_1, numero_3); 
        }
    }
  
    if(numero_1 == numero_3){
        if(numero_1 > numero_2){
            printf("Menor: %d\nMaior: %d\n", numero_2, numero_1);
        }
        else{
             printf("Menor: %d Maior: %d\n", numero_1, numero_2); 
        }
    }

    if(numero_2 == numero_3){
        if(numero_1 > numero_3){
            printf("Menor: %d \nMaior: %d\n", numero_3, numero_1);
        }
        else{
             printf("Menor: %d\nMaior: %d\n", numero_1, numero_3); 
        }
    }

    return 0;
}
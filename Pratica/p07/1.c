//Milena Santana, 21.1.4175, BCC201 - Turma 41

#include <stdio.h>

int main(){
    int numero[10];
    numero[0] = 1;
    numero[1] = 1;
    for (int i = 2; i <= 10; i++){
        numero[i] = numero[i-1] + numero[i-2];
    }

    printf("Os dez primeiros numeros sao:");
    for (int i = 0; i < 10; i++){
        printf(", %d", numero[i]);
    }
    printf(".");
    return 0;
}
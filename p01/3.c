//Milena Santana, 21.1.4175, BCC201 - Turma 41

#include <stdio.h>

int main(){
    int a,b, c;

    printf("Informe o primeiro numero:\n");
    scanf("%d", &a);
    printf("Informe o segundo numero:\n");
    scanf("%d", &b);
    printf("Informe o terceiro numero:\n");
    scanf("%d", &c);

    int maior = a, medio = a, menor = a;

    if(a >= maior && a >b && a > c){
        maior = a;
    }
    if(b >= maior &&b > a &&b > c){
        maior =b;
    }   
    if(c >= maior && c > a && c >b){
        maior = c;
    }

    if(a <= menor && a <b && a < c){
        menor = a;
    }
    if(b <= menor &&b < a &&b < c){
        menor =b;
    }
    if(c <= menor && c < a && c <b){
        menor = c;
    }
        
    if(a != maior && a != menor){
        medio = a;
    }
    if(b != maior &&b != menor){
        medio =b;
    }
    if(c != maior && c != menor){
        medio = c;
    }

    printf("Menor: %d\n", menor);
    printf("Intermediario: %d\n", medio);
    printf("Maior: %d\n", maior);
    return 0;
}
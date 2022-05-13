//Milena Santana de Almeida, 21.1.4175, turma 33

/*Faça um programa que imprima um losango usando ‘*”, ele deve receber como entrada
o tamanho da diagonal horizontal.*/     


//Bibliotecas 
#include <stdio.h>

void losango(int *nro);

void losango(int *nro){ 
    int i = 1;
    int p = 0;
    int c = 0;
    int espacos = (*nro - 1) / 2;

    while(i <= *nro){
        if ((i % 2 != 0) || (i == 1)){
            while(c < espacos){
                printf("   ");
                c++;
            }
            c = 0;
            while(p < i){
                printf(" * ");
                p++;
            }
            p = 0;
            espacos--;
            printf("\n");  
        }
        i++;
    }
    i -= 2;
    espacos += 2;
    while(i > 0){
        if ((i % 2 != 0) || (i == 1)){
            while(c < espacos){
                printf("   ");
                c++;
            }
            c = 0;
            while(p < i){
                printf(" * ");
                p++;
            }
            p = 0;
            espacos++;
            printf("\n");  
        }
        i--;
    }
}

int main(){
    int nro;

    printf("Digite um numero: "); 
    scanf("%d", &nro); 

    while (nro % 2 == 0 ){ 
        printf("ERRO: nro deve ser impar\n");
        printf("Digite um numero: "); 
        scanf("%d", &nro);
    }

    losango(&nro);

    return 0;
}
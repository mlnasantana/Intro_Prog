//Milena Santana, 21.1.4175, BCC201 - Turma 41

#include <stdio.h>

int main(){
    int ano;
    printf("Caro usuario, informe um ano para saber se ele eh bissexto:\n");
    scanf("%d", &ano);

   if((ano % 4 == 0) && ( ano % 100 != 0 )) || ((ano % 4 == 0) && (ano % 100 == 0) && (ano % 400 == 0)) ){
        printf("O ano \"%d\" é bissexto\n", ano); 
    }else{
        printf("Esse ano nao eh bissexto!" );
    } 
    return 0;
}
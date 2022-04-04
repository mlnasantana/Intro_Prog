//Milena Santana de Almeida, 21.1.4175

/*Crie um programa que leia uma variável do tipo char. Crie uma fuņcão que
receba essa variável e determine se ela é uma consoante ou não.*/


//biblioteca

#include <stdio.h>

int main() {

    //variavel
    char letra; 

    printf("Caro usuario, informe uma letra para saber se ela e uma consoante: \n");
    scanf("%c", &letra);


    switch (letra)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U': 
        printf("Nao\n");
        break;
    
    default:
    printf("Sim\n");
        break;
    }
}
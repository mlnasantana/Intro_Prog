//Milena Santana de Almeida, 21.1.4175, turma 33

/*Crie um programa em C que lê um ano e calcula e imprime se o ano digitado é bissexto. Para saber
se um ano é bissexto  utilizar como seguintes regras:
• O ano tem que ser divisı́vel por 4, mas não pode ser divisı́vel por 100;
• Porém, se para divisı́vel por 100, tem que ser divisı́vel também por 400.
*/

//Biblioteca
#include <stdio.h>

int main()
{
  //variavel
    int ano;
    
    printf("Digite um ano: ");
    scanf("%d", &ano);

    
    if( ((ano % 4 == 0) && ( ano % 100 != 0 )) || ((ano % 4 == 0) && (ano % 100 == 0) && (ano % 400 == 0)) ){

        printf("O ano %d é bissexto\n", ano);
    }

    else{
        printf("O ano %d não é bissexto\n", ano);
    }

    return 0;
}
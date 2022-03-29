//Milena Santana de Almeida, 21.1.4175, turma 33

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
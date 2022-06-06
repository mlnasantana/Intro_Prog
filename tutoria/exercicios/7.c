/*crie um programa que leia a idade de uma pessoa e informe
a sua classe eleitoral, de acordo com a tabela abaixo



clase                       idade
nao-leitor                  abaixo de 16 anos
eleitor facultativo         entre 16 e 18 e maior de 65 anos
eleitor obrigatorio         entre 18 e 65 anos
*/

#include <stdio.h>
#include <math.h>

int main(){
    int idade;

    printf("informe sua idade;\n");
    scanf("%d", &idade);

    if(idade <= 16){
        printf("Voce ainda nao e leitor\n");
    }
        if(idade > 16) && (idade < 18){
            printf("Voce e um eleitor facultativo\n");
        }
            if(idade > 18) && (idade < 65){
                printf("Voce e um eleitor obrigatorio\n");
            }
 return 0;
}

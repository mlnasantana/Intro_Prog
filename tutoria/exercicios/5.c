/*crie um programa que leia o peso de uma pessoa no planeta terra.
alem disso, o usuario deve selecionar um dos planetas da lista abaixo, 
para que seu peso naquele planeta seja calculado.
a formula do peso é pesonaterra/10 *gravidaderelativa.
calcule o peso e imprima uma mensagem dizendo qual é o planeta selecionado
e qual o peso calculado.
caso seja escolhido uma planeta que não consta na lista uma mensagem de 
erro deve ser apresentada. use a instrucao switch*/


/*pesos de 1kg em planetas
double jupiter = (2,64);
double mercurio = (3,7);
double marte =( 0,38);
double venus = (0,88);
double saturno = (1,15);
double urano = (1,17);
double netuno = (1,18);
double plutao = (0,11);
 */

#include<stdio.h>
#include<math.h>


int main(){
    int peso, op, resultado;

    printf("Caro usuario, informe seu peso:");
    scanf("%d", &peso);
    printf("Escolha uma opcao para saber seu peso no planeta escolhido:\n");
    printf("1-jupiter\n 2-mercurio\n 3-marte\n 4-venus\n 5-saturno\n 6-urano\n 7-netuno\n 8-plutao\n");
    scanf("%d", &op);

    switch (op)
    {
    case '1':
     resultado = peso * 2,64;
     printf("seu peso em jupiter %d eh:", resultado);
        break;
        
    case '2':
    resultado = peso * 3,7;
     printf("seu peso em mercurio %d eh:", resultado);
        break;
        
    case '3':
     resultado = peso * 0,38;
     printf("seu peso em marte %d eh:", resultado);
        break;

    case '4':
     resultado = peso * 0,88;
     printf("seu peso em venus %d eh:", resultado);
        break;

    case '5':
      resultado = peso * 1,15;
     printf("seu peso em saturno %d eh:", resultado);
        break;

    case '6':
     resultado = peso * 1,17;
     printf("seu peso em urano %d eh:", resultado);
        break;  
         
     case '7':
     resultado = peso * 1,18;
     printf("seu peso em netuno %d eh:", resultado);
        break;   
     case '8':
     resultado = peso * 0,11;
     printf("seu peso em plutao %d eh:", resultado);
        break;

     default:
    printf("Erro, escolha uma opcao valida\n");
    break;
   }
}
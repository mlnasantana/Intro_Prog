//Milena Santana de Almeida, 21.1.4175 

/*Faça um programa que simule uma calculadora que faça soma, subtração,
multiplicação e divisão. Você deve usar o switch e usar uma função para
cada operação. UTILIZE UMA FUNÇÃO E O SWITCH CASE*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>

void opcao_invalida();

int main() {
    //variaveis
    int opcao, num1, num2, resultado;

      printf("Escolha um operador:\n");
        printf("\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n\n");
        scanf("%d", &opcao);

        if(opcao > 0 && opcao < 5){
            printf("Digite dois valores: ");
            scanf("%d%d",&num1, &num2);
        }

        switch(opcao) {
      
        case 1:
            resultado = num1 + num2;
            printf("Soma: %d + %d = %d\n", num1, num2, resultado);
            break;
        case 2:
          resultado = num1 - num2;
            printf("Subtracao: %d - %d = %d\n", num1, num2, resultado);
            break;
        case 3:
          resultado = num1 * num2;
            printf("Multiplicacao: %d * %d = %d\n", num1, num2, resultado);
            break;
          case 4:
          resultado = num1 / num2;
            printf("Divisao: %d / %d = %d\n", num1, num2, resultado);
            break;
        default:
          opcao_invalida();
        }
}

void opcao_invalida(){
    printf("Essa opcao e invalida, tente novamente\n");
  }
//Milena Santana de Almeida, 21.1.4175 turma 33

/*Crie um programa que le o peso e a altura de um adulto e mostra sua condicao de acordo com a tabela
de IMC abaixo. O calculo do IMC e dado por peso/altura^2*/

//biblioteca
#include <stdio.h>

int main() {

//variaveis
  int peso;
  float altura, imc;


  printf("Caro usuario\n");
  printf("Informe o peso (em kg):\n");
  scanf("%d", &peso);

  printf("\nInforme a altura (em metros):\n");
  scanf("%f", &altura);

//funcao
  imc = peso / (altura * altura);

  printf("\n\nIMC em adultos   Condicao fisica");
  printf("\n------------------------------");
  printf("\nAbaixo de 18.5     Abaixo do peso");
  printf("\nEntre 18.5 e 25    Peso Normal");
  printf("\nEntre 25 e 30      Acima do peso");
  printf("\nAcima de 30        Obeso");
  printf("\n------------------------------");
  printf("\nIMC = %.2f", imc);
  
  //condicoes
  if (imc < 18.5)
     printf(" (abaixo do peso).");
  else if ((imc >= 18.5) && (imc < 25))
          printf(" (peso normal).");
       else if ((imc >= 25) && (imc < 30))
               printf(" (acima do peso).");
            else if  ((imc >= 30) && (imc < 34))
                    printf(" (obeso).");
  }
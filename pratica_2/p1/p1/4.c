//Milena Santana de Almeida, 21.1.4175 turma 33

/*Uma empresa concedera um aumento de salario aos seus funcionarios, conforme a tabela abaixo. Faca
um programa que leia o salario e o codigo do cargo de um funcionario e calcule o seu novo salario. Se
o cargo do funcionario nao estiver na tabela, ele devera, entao, receber 15% de aumento. Mostre o
salario antigo, o novo salario e a diferenca entre ambos. Utilizar o comando switch.*/

//biblioteca
#include <stdio.h>

int main() {
  
  //variaveis
  int cargo;
  float salario,fator;
  
  printf("Digite o salário:\n");
  scanf("%f",&salario);
  
  printf("Digite o código do cargo:\n");  
  scanf("%d",&cargo);
  
  switch( cargo) {
    case 100:
        fator = 0.3;
        break;
    case 101:
        fator = 0.5;
        break;
    case 102:
        fator = 0.7,5;
        break;
    case 201:
        fator  = 0.10;
        break;
    default:
        fator = 0.15;
  }
  printf("O salario antigo era de: %.3f \n",salario);
  printf("O salario novo e de: %.3f \n",salario * (1+fator));
  printf("A diferenca entre eles e de: %.3f \n", salario*fator );
  return 0;
}
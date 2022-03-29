//Milena Santana de Almeida, 21.14175,, turma 33

//biblioteca

#include <stdio.h>

int main()
{

  //variaveis 
  int a, b, c, d;

  printf("Caro Usuario, informe 4 valores inteiros:\n");
  scanf("%d %d %d %d", &a, &b, &c, &d);

  if(b > c && d > a && c + d > a + b && c > 0 && d > 0 && a %2 ==0) {
    printf("\n Valores aceitos\n");
  } else {
    printf("\nValores nao aceitos");
  }
  
  return 0;
  
}
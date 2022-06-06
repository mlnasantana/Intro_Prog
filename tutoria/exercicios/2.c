/*crie um programa que leia 3 numeros reais e imprima em ordem crescente. Suponha que os numeros 
iguais não serão digitados*/

#include <stdio.h> 
#include <stdlib.h>

int main(){

    double n1, n2, n3;

    printf("informe o primeiro numero:");
    scanf("%lf", &n1);
    printf("informe o segundo numero:");
    scanf("%lf", &n2);
    printf("informe o terceiro numero:");
    scanf("%lf", &n3);

      if ((n1 <= n2) && (n2 <= n3))
  {
    printf ("%2.lf %2.lf %2.lf\n", n1, n2, n3);
    return 0;
  }
  if ((n2 <= n1) && (n1 <= n3))
  {
    printf ("%2.lf %2.lf %2.lf\n", n2, n1, n3);
    return 0;
  }
}
    
// Milena Santana, 21.1.4175, turma 33

/*Crie um aplicativo que calcula as ra´ızes de uma equa¸c˜ao do 2o grau:
ax2 + bx + c = 0*/

//bibliotecas
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//variaveis
float a;
float b;
float c;
float delta;

//prototipo da funcao
float calculaRaizes(float *delta, float a, float b, float c);
int main() {
      printf("De os valores de a, b e c, para a funcao: \n");
      scanf("%f  %f   %f", &a, &b, &c);
      calculaRaizes(&delta, a , b, c);
      return 0;
} 

//funcao
float calculaRaizes(float *delta, float a, float b, float c) {
       *delta = (pow(b, 2) - (4 * a * c));
      float x1;
      float x2;

      if (*delta >= 0) {
             x1 = ((( - b) + sqrt(*delta)) / (2 * a));
            x2 = ((( - b) - sqrt(*delta)) / (2 * a)); 
            printf("Os valores das raizes sao: %f, %f\n", x1, x2);
            return 1;
      }
      else {
            printf("Nao possui raizes");
            return 0;
      }
}
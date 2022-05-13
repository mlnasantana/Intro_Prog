// Milena Santana, 21.1.4175, turma 33

/*Faca uma unica funcao que converte um valor em graus Celsius para Fahrenheit e Kelvin. Crie tambem
uma funcao main() para ler o valor em Celsius digitado pelo usuario e imprimir este valor convertido
em Fahrenheit e Kelvin.*/

//bilioteca
#include <stdio.h>

//prototipo da funcao
void converterCelsius(float celsius, float *fahrenheit, float *kelvin);

int main()
{
  //variaveis
    float celsius, fahrenheit, kelvin;
    printf("Digite o valor em celsius\n");
    scanf("%f", &celsius);
    converterCelsius(celsius, &fahrenheit, &kelvin);

  printf("%f celsius = %f farehnheit\n", celsius, fahrenheit);
  printf("%f celsius = %f kelvin\n", celsius, kelvin);

  return 0;
}

//funcao
void converterCelsius(float celsius, float *fahrenheit, float *kelvin) {
    *fahrenheit = (celsius *9/5) + 32.00;
    *kelvin = celsius + 273,15;
}

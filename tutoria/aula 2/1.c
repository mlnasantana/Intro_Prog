//Milena Santana de Almeida, 21.1.4175


/*Faça um programa em que receba como entrada uma temperatura em graus
Celsius, e calcule a temperatura em kelvin e fahrenheit, usando uma função
do tipo float para cada conversão. UTILIZE UMA FUNÇÃO*/

//bibliotecas
#include <stdio.h>
//funcao que converte 
void converte_Celsius(float celsius, float * fahrenheit, float * kelvin);

int main()
{
    //variaveis
    float celsius, fahrenheit, kelvin;
    printf("Informe o valor em celsius:\n");
    scanf("%f", &celsius);
    converte_Celsius(celsius, &fahrenheit, &kelvin);

  printf("%.2f celsius = %.2f farehnheit\n", celsius, fahrenheit);
  printf("%.2f celsius = %.2f kelvin\n", celsius, kelvin);

  return 0;
}
void converte_Celsius(float celsius, float *fahrenheit, float *kelvin) {
    *fahrenheit = (celsius *9/5) + 32.00;
    *kelvin = celsius + 273;
}
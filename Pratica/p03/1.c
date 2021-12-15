// Milena Santana, 21.1.4175 BCC201 T41

#include <stdio.h>

void converterCelsius(float celsius, float * fahrenheit, float * kelvin);

void converterCelsius(float celsius, float *fahrenheit, float *kelvin) {
    *fahrenheit = (celsius *9/5) + 32.00;
    *kelvin = celsius + 273,15;
}

int main()
{
    float celsius, fahrenheit, kelvin;
    printf("Digite o valor em celsius\n");
    scanf("%f", &celsius);
    converterCelsius(celsius, &fahrenheit, &kelvin);

  printf("%f celsius = %f farehnheit\n", celsius, fahrenheit);
  printf("%f celsius = %f kelvin\n", celsius, kelvin);

  return 0;
}
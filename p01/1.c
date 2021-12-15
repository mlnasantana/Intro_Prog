//Milena Santana, 21.1.4175, BCC201 - Turma 41

#include <stdio.h>

int main()
{
  char letra;
  printf("Digite a letra escolhida:");
  scanf("%c", &letra);
  if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U' || letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
  printf("Sua letra e uma vogal\n");
}
  if (letra != 'A' && letra != 'E' && letra != 'I' && letra != 'O' && letra != 'U' && letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u'){
  printf("Sua letra nao e uma vogal");
 }
return 0;
  }
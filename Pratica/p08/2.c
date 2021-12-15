//Milena Santana, 21.1.4175, turma 41

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char palavra[30], copia[30], cod, getche;
  int i, tam, iguais = 0;
 cod = 'F';
  printf("Digite uma palavra ou FIM para sair:\n");
  scanf("%s", palavra);
 tam = strlen(palavra);

  while(cod != 'F') {
  for (i = 0; i < strlen(palavra); i++);
  {
    copia[i] = palavra[tam - 1];
    tam--;
  }
  copia[i] = '\0';
  tam = strlen(palavra);

  for (i = 0; i < tam; i++)
  {
    if (palavra[i] == copia[i])
      iguais++;
  }
  }
  if (tam == iguais)
  {
    printf("%s e palindroma\n");
  }
  else
  {
    printf("%s nao e palindroma\n");
  }
  return 0;
}
//Milena Santana, 21.1.4175, turma 33

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 2000  

char trocar_letras(char letra); //função para trocar letras, que recebe e retorna um caracter 

int main()
{
  char frase[TAMANHO_MAXIMO];
  int i; //variavel auxiliar
  printf("Digite o texto para censurar:\n");
  fgets(frase, TAMANHO_MAXIMO, stdin);

  i = 0; // utilizado para trocar letras
  while (frase[i] != '\0') //enquanto meu caracter for diferente de '\0' trocará a letra
  {
    frase[i] = trocar_letras(frase[i]); 
    i++;
  }

  printf("A frase com as letras trocadas e: %s", frase);
  printf("\n\n");
  return 0;
}

char trocar_letras(char letra) //função para trocar letras
{
  char nova_letra;

  switch (letra)
  {
    //se os caracteres forem identicos a esses, será executado esse codigo, ate chegar em um break
  case 'a':
    nova_letra = '@';
    break;
  case 'e':
    nova_letra = '_';
    break;
  case 'i':
    nova_letra = '|';
    break;
  case 'o':
    nova_letra = '0';
    break;
  case 'u':
    nova_letra = '#';
    break;
  case 's':
    nova_letra = '$';
    break;

 // se não cair em nenhum caso do switch, será ativado o default (usado como padrão)
  default:
    nova_letra = letra;
    break;
  }
  return nova_letra;
}
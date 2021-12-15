//Milena Santana, 21.1.4175, BCC201 turma 41

#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[50];
  double nota;
  double frequencia;
}Aluno;

double media(Aluno vetor[50], int i){
  double media;
  for (int j = 0; j < i; j++){
    media = vetor[j].nota / i;
  }
  return media;
}

int main()
{
  char arquivo[50];
  printf("Digite o nome do arquivo: ");
  int n = 0;
  scanf("%s", arquivo);
  FILE *file = fopen(arquivo, "r");

  Aluno vetor[50];
  while (!feof(file)){
    fgets(vetor[n].nome, 50, file);
    fscanf(file, "%lf", &vetor[n].nota);
    fscanf(file, "%lf", &vetor[n].frequencia);
    fgetc(file);
    n++;
  }

  for (int i = 0; i < n; ++i){
    printf("%s", vetor[i].nome);
    printf("%.0lf\n", vetor[i].nota);
    printf("%.0lf\n", vetor[i].frequencia);
  }
fclose(file);
}
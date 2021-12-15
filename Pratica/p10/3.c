//Milena Santana, 21.1.4175, BCC201 Turma 41

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float nota, freq;
} Aluno;

int main()
{
    FILE *arquivo = fopen("arquivo.txt", "w");
    int ver = 0;
    Aluno *a;
    do{
        printf("Digite 1 para finalizar o programa e 0 para add outro aluno.");
        scanf("%d", &ver);
        printf("\nDigite o nome do aluno: \n");
        scanf("%f", &a->nome);

        printf("\nDigite a nota do aluno: \n");
        scanf("%f", &a->nota);
        printf("\nDigite a frequencia do aluno em porcento: \n");
        scanf("%f", &a->freq);


        fprintf(arquivo, "%s %f %f", a->nome, a->nota, a->freq);
    }while(ver == 0);

    fclose(arquivo);

    return 0;
}
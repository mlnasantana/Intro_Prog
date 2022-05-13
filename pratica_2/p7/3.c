// Milena Santana, 21.1.4175, turma 41

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int tamanho, i, aux = 0, j = 0;
    char nome[70], ultimonome[70], restonome[70];
    printf(" Digite o nome completo: \n");
    fgets(nome, 70, stdin);
    tamanho = strlen(nome);
    nome[tamanho - 1] = '\0';
    tamanho = strlen(nome);

    for (i = 0; i < (tamanho); i++)
    {
        if (nome[i] == (char)32)
        {
            tamanho = tamanho - 1;
            aux = i;
        }
    }

    for (i = 0; i <= aux; i++)
    {
        restonome[i] = nome[i];
    }
    j = ((tamanho - aux));

    for (i = 0; (aux - 2) < tamanho; i++, aux++)
    {
        ultimonome[i] = nome[aux];
    }

    printf("\n %s , %s ", ultimonome, restonome);
    printf("\n total de letras : %d ", tamanho);
    printf("\n total de letras do ultimo sobrenome: %d ", j);

    return 0;
}
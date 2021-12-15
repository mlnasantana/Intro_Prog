//Milena Santana, 21.1.4175

#include <stdio.h>
#include <stdlib.h>

int main(){

    //Lendo o tamanho do vetor e criando ele
    int n; 
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    int *vet1 = malloc(sizeof(int) * n);

    //lendo os valores do vetor e somando valores para a média
    int media = 0;
    printf("Digite os valores do vetor: ");
    for(int i=0; i<n; i++){
        scanf("%d", &vet1[i]);
        media += vet1[i];
    }

    //calculando media
    media = media / n;

    //vendo quantos alunos ficaram acima ou abaixo da média
    int acima = 0, abaixo = 0;
    for (int i = 0; i < n; i++)
        vet1[i] >= media ? acima++ : abaixo++;
    //criando vetores de valores acima e abaixo da media
    int *up = malloc(sizeof(int) * acima);
    int *dw = malloc(sizeof(int) * abaixo);

    //passando valores para o vetor
    acima = 0, abaixo = 0;
    for(int i = 0; i < n; i++){
        if(vet1[i] >= media){
            up[acima] = vet1[i];
            acima++;
        }else{
            dw[abaixo] = vet1[i];
            abaixo++;
        }
    }

    //exibindo os resultados
    printf("A media eh: %d\n", media);
    printf("Vetor com valores abaixo da media: [");
    for (int i = 0; i < abaixo; i++)
        printf(" %d", dw[i]);
    printf(" ]\n");

    printf("Vetor com valores iguai ou acimas da media: [");
    for (int i = 0; i < acima; i++)
        printf(" %d", up[i]);
    printf(" ]\n");

    //liberando memoria
    free(dw);
    free(up);
    free(vet1);

    return 0;
}
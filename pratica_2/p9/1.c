//Milena Santana de Almeida, 21.1.4175

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, sub_med = 0;
    double media = 0;


    printf("Digite o valor de n: "); scanf("%d", &n);
    int *vet1 = malloc(n * sizeof(int));

    //Entrada do vetor
    printf("Digite os valores do vetor: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &vet1[i]);
        media += vet1[i];
    }

    media /= n;
    printf("A média é: %.2lf\n", media);

 
    for(int i = 0; i < n; i++){
        if(vet1[i] < media){
            sub_med++;
        }
    }

    int *vet2 = malloc(sub_med * sizeof(int));
    int *vet3 = malloc((n - sub_med) * sizeof(int));

    
    //Entrada dos vetores
    for(int i = 0, j = 0, k = 0; i < n; i++){
        if(vet1[i] < media){
            vet2[j] = vet1[i];
            j++;
        }
        else{
            vet3[k] = vet1[i];
            k++;
        }
    }

    printf("Vetor com %d valores abaixo da média: [ ", sub_med);
    for(int i = 0; i < sub_med; i++){
        printf("%d ", vet2[i]);
    }
    printf("]\n");

    printf("Vetor com %d valores iguais ou acima da média: [ ", n - sub_med);
    for(int i = 0; i < (n - sub_med); i++){
        printf("%d ", vet3[i]);
    }
    printf("]\n");


    free(vet1);
    free(vet2);
    free(vet3);

    return 0;
}
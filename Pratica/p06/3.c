//Milena Santana, 21.1.4175, T41

#include <stdio.h>
#include <math.h>

void imprime(int linha, int coluna){
    int dif = linha - coluna, verDif, verSoma; 
    int soma = linha + coluna;
    int contl = 1, contc = 1;
    
    while(contl <= 8){ 
        printf("%d |", contl);
        while(contc <= 8){
            verSoma = contl + contc;
            verDif = contl - contc;
            if(contl == linha && contc == coluna){
                printf(" O");
            }else if(verSoma == soma || verDif == dif){
                printf(" X");
            }else{
                printf(" -");
            }
            contc++;
        }
        printf("\n");
        contl++;
        contc = 1;
    }

}

int main(){
    int linha, coluna;
    printf("Movimentos de um Bispo no xadrez!\n");
    printf("Digite a linha em que o Bispo se encontra: ");
    scanf("%d", &linha);
    printf("Digite a coluna em que o Bispo se encontra: ");
    scanf("%d", &coluna);
    
    printf("\nMovimentos possiveis:");
    printf("\n    1 2 3 4 5 6 7 8");
    printf("\n-------------------------\n");

    imprime(linha, coluna);
}
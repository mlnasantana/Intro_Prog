//Milena Santana, 21.1.4175

#include <stdio.h>
#include <stdlib.h>

int verifica(int **q, int n){
    //inicializando vetores de soma
    int *sLinha = malloc(n * sizeof(int)); //soma das linhas
    int *sColuna = malloc(n * sizeof(int)); //soma das colunas
    int sDiag[2]; //soma das duas diagonais

    //somando as linhas, colunas e diagonais
    sDiag[0] = 0;
    sDiag[1] = 0;
    for (int i = 0; i < n; i++){
        sLinha[i] = 0;
        sColuna[i] = 0;
        for (int j = 0; j < n; j++){
            sLinha[i] += q[i][j];
            sColuna[i] += q[j][i];
            j == i ? sDiag[0] += q[j][i] : (sDiag[0] += 0);
        }
        sDiag[1] += q[i][n-i-1];
    }

    //a media de todas as somas tem que dar a propria soma
    int ver = 0;
    //somando todos os valores
    for (int j = 0; j < 2; j++)
        ver += sDiag[j];
    for (int i = 0; i < n; i++)
        ver += sLinha[i]+sColuna[i];
    //tirando a media
    ver = ver / (n * 2 + 2);

    //se der diferente as somas, retorna 0
    int retorno = 0;
    for (int i = 0; i < 2; i++)
        sDiag[i] == ver ? retorno++ : retorno--;
    for (int j = 0; j < n; j++){
            sLinha[j] == ver ? retorno++ : retorno--;
            sColuna[j] == ver ? retorno++ : retorno--;
    }

    //liberando o endereço de memória
    free(sColuna);
    free(sLinha);
    
    //se a variavel retorno tiver a mesma quantidade de resultados das somas, retorna 1
    if (retorno == (n * 2 + 2))
        return 1;
    return 0;
}

int main(){
    //lendo o tamanho da matriz
    int n;
    printf("Digite um valor de n: ");
    scanf("%d", &n);

    //criando a matriz do quadrado
    int **quadrado = malloc( n * sizeof(int*));
    for (int i = 0; i < n; i++)
        quadrado[i] = malloc( n * sizeof(int));
    
    //lendo os valores do quadrado
    printf("Digite os valores da matriz %d x %d: \n", n, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            scanf("%d", &quadrado[i][j]);
    }


    //verificando se é um quadrado mágico
    verifica(quadrado, n) == 1 ? printf("Essa matriz eh um quadrado magico!") : printf("Essa matriz nao eh um quadrado magico!");

    //liberando endereço de memória
    free(quadrado);    
    
    return 0;
}
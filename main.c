
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao que fnaliza o programa
void finaliza(char *string){
    if(strcmp(string, "sair") == 0){
        printf("\n\nTchau!");
        exit(0);
    }
}


//menu de inicio
int inicio(){
    char escolha[5];
    printf("\n\nBem vindo ao Caca Palavras\nO que deseja fazer:\n1. Comecar um novo jogo.\n2. Continuar um jogo.\n3. Instrucoes do jogo.\n\n");
    printf("Escolha a opcao (digite \'sair\' em qualquer lugar para sair do jogo): ");
    fgets(escolha, 5, stdin);
    finaliza(escolha);

    return (escolha[0] - '0');
}

//solicita nome do nome do arquivo
void solicitaNomeArquivo(char *nome){
   printf("\nDigite o nome do arquivo com as palavras: ");
    scanf("%s", nome);
    finaliza(nome);
}


void instrucoes(){


}

//funcao que cria matrizes de String
char **fazMatrizChar(int n, int m, int strinOuChar){
    char **matriz = malloc(n * sizeof(char**));

    if(strinOuChar == 1){ //se for 1, cria matriz de string
        for (int i = 0; i < n; i++)
            matriz[i] = malloc(m * sizeof(char*));
    }else{ //cria matriz de char
        for (int i = 0; i < n; i++)
            matriz[i] = malloc(m * sizeof(char));
    }
    return matriz;
}

//funcao que cria matrizes de Int
int **fazMatrizInt(int n, int m){
    int **matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matriz[i] = malloc(m * sizeof(int));
    return matriz;
}



int main()
{
    int escolha, dificuldade;
    char nome[100], nivelStr[10];

    do{
        escolha = inicio();
        switch (escolha){
            case 1: //iniciando um novo jogo
                solicitaNomeArquivo(nome);
                printf("\nDigite o nivel de dificuldade facil (1), medio (2) ou dificil (3).: ");
                scanf("%s", nivelStr);
                finaliza(nivelStr);
                dificuldade = (nivelStr[0] - '0'); // transformando a escolha em um inteiro

                break;

            case 2:
                break;
            case 3:
                instrucoes();
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }while(escolha != 1 && escolha != 2);

    FILE *arq = fopen("dicionario.txt", "r"); //abrindo um arquivo pra leitura
    int n = 0, m = 0, quantPalavras = 0;
    char **matriz;

    if(escolha == 1){ //se for um novo jogo

        fscanf(arq,  "%d %d\n%d\n", &n, &m, &quantPalavras); //lendo as 3 primeiras linhas do dicionario
        char **palavras = fazMatrizChar(quantPalavras, 100, 1);//criando uma matriz para as palavras
        printf("\n\nN: %d\nM: %d\nQuant: %d\n\n", n, m, quantPalavras);
        int *tamanhoPalavras = malloc(quantPalavras);

        //lendo o restante das palvras
       for (int i = 0; i < quantPalavras; i++){
            fscanf(arq, "%s\n", palavras[i]);
            tamanhoPalavras[i] = (strlen(palavras[i]));
            printf("%s - %d\n", palavras[i], tamanhoPalavras[i]);
        }

        matriz = fazMatrizChar(n, m, 2); //criando matriz do caca palavras
        printf("\n");

        for (int i = 0; i < n; i++){//preenchendo a matriz com valores aleat�rios
            for (int j = 0; j < m; j++){
                matriz[i][j] = 'A' + (char)(rand() % 26);
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n\nEntrou\n\n");



        int **linha = fazMatrizInt(quantPalavras, 2), **coluna = fazMatrizInt(quantPalavras, 2), orientacao, verificadorUsado;
        int **linhaUsada = fazMatrizInt(quantPalavras, 2), **colunaUsada = fazMatrizInt(quantPalavras, 2);

        if(dificuldade == 1){
            for (int i = 0; i < quantPalavras; i++){ //repetir todas as palavras

                verificadorUsado = 0;
                linhaUsada[i][0] = -5; //inicializando com valores aletorios a linha inicial.
                colunaUsada[i][0] = -5;//inicializando com valores aletorios a coluna inicial.
                linhaUsada[i][1] = -5; //inicializando com valores aletorios a linha final.
                colunaUsada[i][1] = -5;//inicializando com valores aletorios a coluna final.

                do{//enquanto n�o achar um espaco, nao muda de palavra

                    orientacao = (rand() % 2); //sorteando 0 ou 1 pra orienta��o
                    printf("orientacao: %d\n", orientacao);

                    if (orientacao == 0){ //se orientacao for igual a zero, � horizontal
                        linha[i][0] = (rand() % n);
                        coluna[i][0] = (rand() % (m-tamanhoPalavras[i]));//a coluna n�o deve estar mais proxima da borda do que o tamanho da palavra

                        linha[i][1] = linha[i][0];//ultima linha usada pela string
                        coluna[i][1] = coluna[i][0] + tamanhoPalavras[i]; //ultima coluna usada pela string


                        for (int j = 0; j <= i; j++){//verificando se j� foi usado a coluna ou a linha
                            verificadorUsado = 0;
                            if(linhaUsada[j][0] = linha){

                                if(coluna[i][0] >= colunaUsada[j][0] && coluna[i][0] <= colunaUsada[j][1]) //se estiver comecando dentro de alguma palavra usada
                                    verificadorUsado = 1;

                                if(coluna[i][1] >= colunaUsada[j][0] && coluna[i][1] <= colunaUsada[j][1]) //se estiver finalizando dentro de alguma palavra usada
                                    verificadorUsado += 10;

                                if((m - colunaUsada[j][1]) < (tamanhoPalavras[i] - 1) && colunaUsada[j][0] < (tamanhoPalavras[i] - 1)){ //se n�o tiver espaco depois da coluna ou antes
                                    verificadorUsado += 10;
                                }else verificadorUsado --;
                                
                            }
                            if(coluna[i][1] > m){
                                verificadorUsado += 10;
                            }else verificadorUsado --;

                        if (verificadorUsado % 10 != 0){
                                linhaUsada[i][0] = linha; // linha usada
                                linhaUsada[i][1]= linha; //linha final eh a mesma
                                colunaUsada[i][0] = coluna; //coluna usada inicial
                                colunaUsada[i][1] = coluna + tamanhoPalavras[i];  //coluna usada final

                                for(int k = 0; k < tamanhoPalavras[i]; k++)
                                    matriz[linha[i][0]][coluna[i][0] + k] = palavras[i][k];

                        }

                    }



                }while(verificadorUsado == 1);
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                printf("%c ", matriz[i][j]);
            printf("\n");
        }

    }

    return 0;
}

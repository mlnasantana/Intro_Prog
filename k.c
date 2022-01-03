/*
Trabalho prático caça-palavras
Gabriel cezar Rodrigues 21.1.4157
BCC201 - introdução a programação
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#ifndef _COLOR_H_INCLUDED
#define _COLOR_H_INCLUDED

#define CN_NO_COLOR    -1

// Colors
#define CN_BLACK       0
#define CN_RED         1
#define CN_GREEN       2
#define CN_YELLOW      3
#define CN_BLUE        4
#define CN_MAGENTA     5
#define CN_CYAN        6
#define CN_WHITE       7

// Color modifier
#define CN_BRIGHT      16

// Character attributes
#define CN_NORMAL      0
#define CN_REVERSE     128

// Character attributes (Linux only)
#define CN_BOLD        32
#define CN_UNDERLINE   64

int is_inside_terminal();

void textcolor(int attr, int fg, int bg);

void textcolor_show();

#endif //_COLOR_H_INCLUDED

#ifdef WIN32
#include <windows.h>
#include <io.h>
static HANDLE hConsole = NULL;
static WORD hConsoleDefAttr = 0;
#else
#include <unistd.h>
#endif

//#define USE_ARCHAIC_TERM

// System specific color values
#ifdef WIN32
#define BLACK       0
#define RED         (FOREGROUND_RED)
#define GREEN       (FOREGROUND_GREEN)
#define YELLOW      (FOREGROUND_RED | FOREGROUND_GREEN)
#define BLUE        (FOREGROUND_BLUE)
#define MAGENTA     (FOREGROUND_BLUE | FOREGROUND_RED)
#define CYAN        (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define WHITE       (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#else
#define BLACK       0
#define RED         1
#define GREEN       2
#define YELLOW      3
#define BLUE        4
#define MAGENTA     5
#define CYAN        6
#define WHITE       7

#define NORMAL      0
#define BRIGHT      1
#define DIM         2
#define ITALIC      3
#define UNDERLINE   4
#define BLINK_SLOW  5
#define BLINK_FAST  6
#define REVERSE     7
#define HIDDEN      8
#endif

static int GetSysConsoleColor(int nColor)
{
    int nSysColor = 0;
    switch(nColor)
    {
        case CN_BLACK:
            nSysColor = BLACK;
            break;
        case CN_BLUE:
            nSysColor = BLUE;
            break;
        case CN_GREEN:
            nSysColor = GREEN;
            break;
        case CN_CYAN:
            nSysColor = CYAN;
            break;
        case CN_RED:
            nSysColor = RED;
            break;
        case CN_MAGENTA:
            nSysColor = MAGENTA;
            break;
        case CN_YELLOW:
            nSysColor = YELLOW;
            break;
        case CN_WHITE:
            nSysColor = WHITE;
            break;
        default:
            nSysColor = 0;
    }
    return nSysColor;
}

int is_inside_terminal()
{
    static int g_IsTerminal = -1;
    if (!g_IsTerminal) return 0;
    if (g_IsTerminal==-1)
    {
        // Check if stdout is a terminal
#ifdef WIN32
        g_IsTerminal = _isatty(_fileno(stdout)) ? 1 : 0;
#else
        g_IsTerminal = isatty(fileno(stdout)) ? 1 : 0;
#endif
    }
    return g_IsTerminal!=0;
}

void textcolor(int attr/*=CN_NORMAL*/, int fg/*=CN_NO_COLOR*/, int bg/*=CN_NO_COLOR*/)
{
    if (!is_inside_terminal()) return;

#ifdef WIN32
    int fg_win = -1;
    int bg_win = -1;
    bool bReverse = (attr & CN_REVERSE)>0;
    bool bForegroundIntense = ( (fg>0 && (fg & CN_BRIGHT)) || (attr & CN_BOLD));
    bool bBackgroundIntense = bg>7;

    WORD hConsoleAttr = 0;
    if (hConsole==NULL)
    {
        // Get default colors
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        hConsoleDefAttr = consoleInfo.wAttributes;
    }
    if (attr==CN_NORMAL && fg<0 && bg<0)
        SetConsoleTextAttribute(hConsole, hConsoleDefAttr);

    // Set intended colors
    if (fg>=0)
        fg_win = GetSysConsoleColor(fg & 0x7);
    else
        fg_win = hConsoleDefAttr & 0x7;

    if (bg>=0)
        bg_win = GetSysConsoleColor(bg & 0x7);
    else
        bg_win = (hConsoleDefAttr & 0x70)>>4;

    // Set intensity
    if (bForegroundIntense) fg_win |= 8;
    if (bBackgroundIntense) bg_win |= 8;

    // Reverse if needed
    if (attr & CN_REVERSE)
    {
        int tmp = fg_win;
        fg_win = bg_win;
        bg_win = tmp;
    }

    // Set the colors
    hConsoleAttr = fg_win | (bg_win<<4);
    SetConsoleTextAttribute(hConsole, hConsoleAttr); //FOREGROUND_BLUE
#else
    int attr_lin = 0;
    int fg_lin = -1;
    int bg_lin = -1;
    if (fg>=0) fg_lin = GetSysConsoleColor(fg & 0x7);
    if (bg>=0) bg_lin = GetSysConsoleColor(bg & 0x7);

    if (attr & CN_BOLD) attr_lin |= BRIGHT;
    if (attr & CN_UNDERLINE) attr_lin |= UNDERLINE;
    if (attr & CN_REVERSE) attr_lin |= REVERSE;

#ifdef USE_ARCHAIC_TERM
    if (bg>0 && (bg & CN_BRIGHT))
    {
        if (fg>0 && (fg & CN_BRIGHT)) fg_lin += 60;
        bg_lin += 60;
        //if (bg>0 && (bg & CN_BRIGHT)) bg_lin += 60;
    }
    else
    {
        if (fg>0 && (fg & CN_BRIGHT)) attr_lin |= BRIGHT;
    }
#else
    if (fg>0 && (fg & CN_BRIGHT)) fg_lin += 60;
    if (bg>0 && (bg & CN_BRIGHT)) bg_lin += 60;
#endif
    char command[23];
    if (attr == CN_NORMAL && fg<0 && bg<0)
        sprintf(command, "%c[0m", 0x1B);
    else
    {
        if (fg<0 && bg<0)
            sprintf(command, "%c[%dm", 0x1B, attr_lin);
        else if (fg>0 && bg<0)
            sprintf(command, "%c[%d;%dm", 0x1B, attr_lin, fg_lin + 30 );
        else if (fg<0 && bg>0)
            sprintf(command, "%c[%d;%dm", 0x1B, attr_lin, bg_lin + 40 );
        else
            sprintf(command, "%c[%d;%d;%dm", 0x1B, attr_lin, fg_lin + 30, bg_lin + 40 );
#ifdef USE_256_COLORS
        if (bg<0)
            sprintf(command, "%c[38;5;%dm", 0x1B, fg_lin);
        else
            sprintf(command, "%c[38;5;%dm%c[48;5;%dm", 0x1B, fg_lin, 0x1B, bg_lin);
#endif
    }
    printf("%s", command);
#endif
    fflush(stdout);
}

//funcao que fnaliza o programa
void finaliza(char *string){
    if(strcmp(string, "sair") == 0){
        printf("\nTchau!");
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

int horizontal(char **palavras, int **linha, int**coluna, int n, int m, int *tamanhoPalavras, int i, int **linhaUsada, int**colunaUsada, char**matriz, int dir){
    int verificadorUsado;
    for (int j = 0; j <= i; j++){//verificando se já foi usado a coluna ou a linha
        verificadorUsado = 0;
        linha[i][0] = (rand() % (n-1));
        coluna[i][0] = (rand() % (m-1));//a coluna não deve estar mais proxima da borda do que o tamanho da palavra
        
        linha[i][1] = linha[i][0];//ultima linha usada pela string
        
        if(dir == 1)
            coluna[i][1] = coluna[i][0] + tamanhoPalavras[i] -1; //ultima coluna usada pela string para direita
        else 
            coluna[i][1] = coluna[i][0] - tamanhoPalavras[i] - 1; //ultima coluna usada pela string para esquerda
            

        if(linhaUsada[j][0] <= linha[i][0] && (coluna[i][0] - colunaUsada[j][0]) <= tamanhoPalavras[i])
            verificadorUsado = 7;
        
        //se crusar com uma palvra na vertical
        if(linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1] && coluna[i][0] <= colunaUsada[j][0] && coluna[i][1] >= colunaUsada[j][0])
            verificadorUsado = 1;
        
        if(coluna[i][0] == colunaUsada[j][0] && linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1])
            verificadorUsado = 1;

        //se comecar na mesma linha
        if(linhaUsada[j][0] == linha[i][0]){

            if(coluna[i][0] >= colunaUsada[j][0] && coluna[i][0] <= colunaUsada[j][1]) //se estiver comecando dentro de alguma palavra usada
                verificadorUsado = 2;

            if(coluna[i][1] >= colunaUsada[j][0] && coluna[i][1] <= colunaUsada[j][1]) //se estiver finalizando dentro de alguma palavra usada
                verificadorUsado = 3;

            if((m - colunaUsada[j][1]) < (tamanhoPalavras[i] - 1) && colunaUsada[j][0] < (tamanhoPalavras[i] - 1)) //se não tiver espaco depois da coluna ou antes
                verificadorUsado = 4;
            if(coluna[i][0] <= colunaUsada[j][0] && coluna[i][1] >= colunaUsada[j][0])
                verificadorUsado = 9;

        }
    
        if(coluna[i][1] > m || coluna[i][1] < 0)
            verificadorUsado = 5;

        printf(" - %d\n", verificadorUsado);
        if (verificadorUsado == 0){
            linhaUsada[i][0] = linha[i][0]; // linha usada
            linhaUsada[i][1]= linha[i][1]; //linha final eh a mesma
            colunaUsada[i][0] = coluna[i][0]; //coluna usada inicial
            colunaUsada[i][1] = coluna[i][1];  //coluna usada final

            for(int k = 0; k < tamanhoPalavras[i]; k++){
                if(dir == 1) // se for para direita
                    matriz[linha[i][0]][coluna[i][0] + k] = palavras[i][k];
                else //para esquerda
                    matriz[linha[i][0]][coluna[i][0] - k] = palavras[i][k];
                
            }
            
            break;    
        }
    }
}

int vertical(char **palavras, int **linha, int**coluna, int n, int m, int *tamanhoPalavras, int i, int **linhaUsada, int**colunaUsada, char**matriz, int dir){
    int verificadorUsado;
    for (int j = 0; j <= i; j++){//verificando se já foi usado a coluna ou a linha
                                
        verificadorUsado = 0;
        linha[i][0] = (rand() % (n-1));//a linha não deve estar mais proxima da borda do que o tamanho da palavra
        coluna[i][0] = (rand() % (m-1));

        if(dir == 1)
            linha[i][1] = linha[i][0] + tamanhoPalavras[i] - 1;//ultima linha usada pela string
        else
            linha[i][1] = linha[i][0] - tamanhoPalavras[i] + 1;//ultima linha usada pela string

        coluna[i][1] = coluna[i][0]; //ultima coluna usada pela string

        //se cruzar com alguma palavra na horizontal
        if(coluna[i][0] >= colunaUsada[j][0] && coluna[i][0] <= colunaUsada[j][1] && linha[i][0] <= linhaUsada[j][0] && linha[i][1] >= linhaUsada[j][0])
                verificadorUsado = 1;


        if(colunaUsada[j][0] == coluna[i][0]){

            if(linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1]) //se estiver comecando dentro de alguma palavra usada
                verificadorUsado = 2;


            if(linha[i][1] >= linhaUsada[j][0] && linha[i][1] <= linhaUsada[j][1]) //se estiver finalizando dentro de alguma palavra usada
                verificadorUsado = 3;


            if((n - linhaUsada[j][1]) < (tamanhoPalavras[i] - 1) && linhaUsada[j][0] < (tamanhoPalavras[i] - 1)) //se não tiver espaco depois da coluna ou antes
                verificadorUsado = 4;
        }

        if(linha[i][1] > n || linha[i][1] < 0)
            verificadorUsado = 5;

        printf(" - %d\n", verificadorUsado);
        
        if (verificadorUsado == 0){
            linhaUsada[i][0] = linha[i][0]; // linha usada
            linhaUsada[i][1]= linha[i][1]; //linha final eh a mesma
            colunaUsada[i][0] = coluna[i][0]; //coluna usada inicial
            colunaUsada[i][1] = coluna[i][1];  //coluna usada final

            for(int k = 0; k < tamanhoPalavras[i]; k++){
                if (dir == 1)//se for para cima                
                    matriz[linha[i][0]+k][coluna[i][0]] = palavras[i][k]; //colocando as string na matriz para cima
                else //para baixo
                    matriz[linha[i][0]-k][coluna[i][0]] = palavras[i][k]; //colocando as string na matriz para baixo
            }
            break;    
        }
    }
}

int diagonal(char **palavras, int **linha, int**coluna, int n, int m, int *tamanhoPalavras, int i, int **linhaUsada, int**colunaUsada, char**matriz, int dir){
    int verificadorUsado;
    for (int j = 0; j <= i; j++){//verificando se já foi usado a coluna ou a linha
                                
        verificadorUsado = 0;
        linha[i][0] = (rand() % n);//a linha não deve estar mais proxima da borda do que o tamanho da palavra
        coluna[i][0] = (rand() % m);
        if(dir == 1){
            linha[i][1] = linha[i][0] + tamanhoPalavras[i] - 1;//ultima linha usada pela string
            coluna[i][1] = coluna[i][0] + tamanhoPalavras[i] - 1; //ultima coluna usada pela string
        }else{
            linha[i][1] = linha[i][0] - tamanhoPalavras[i] + 1;//ultima linha usada pela string
            coluna[i][1] = coluna[i][0] - tamanhoPalavras[i] + 1; //ultima coluna usada pela string
        }

        //se cruzar com alguma palavra na horizontal
        if(coluna[i][0] >= colunaUsada[j][0] && coluna[i][0] <= colunaUsada[j][1] && linha[i][0] <= linhaUsada[j][0] && linha[i][1] >= linhaUsada[j][0])
                verificadorUsado = 1;
        
        //se cruzar com palavra na vertical
        if(linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1] && coluna[i][0] <= colunaUsada[j][0] && coluna[i][1] >= colunaUsada[j][0])
                verificadorUsado = 1;
        

        if(colunaUsada[j][0] == coluna[i][0]){

            if(linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1]) //se estiver comecando dentro de alguma palavra usada
                verificadorUsado = 2;


            if(linha[i][1] >= linhaUsada[j][0] && linha[i][1] <= linhaUsada[j][1]) //se estiver finalizando dentro de alguma palavra usada
                verificadorUsado = 3;


            if((n - linhaUsada[j][1]) < (tamanhoPalavras[i] - 1) && linhaUsada[j][0] < (tamanhoPalavras[i] - 1)) //se não tiver espaco depois da coluna ou antes
                verificadorUsado = 4;

            
        }

        if(linha[i][1] > n || coluna[i][1] > m || linha[i][1] < 0 || coluna[i][1] < 0)
            verificadorUsado = 5;

        printf(" - %d\n", verificadorUsado);
        
        if (verificadorUsado == 0){
            linhaUsada[i][0] = linha[i][0]; // linha usada
            linhaUsada[i][1]= linha[i][1]; //linha final eh a mesma
            colunaUsada[i][0] = coluna[i][0]; //coluna usada inicial
            colunaUsada[i][1] = coluna[i][1];  //coluna usada final

            for(int k = 0; k < tamanhoPalavras[i]; k++){
                if(dir == 1)//para direita baixo
                    matriz[linha[i][0]+k][coluna[i][0]+k] = palavras[i][k]; //colocando as string na matriz
                else //para esquerda cima
                    matriz[linha[i][0]-k][coluna[i][0]-k] = palavras[i][k]; //colocando as string na matriz
            }
            break;    
        }
    }
}

void exibeMatriz (char **matriz, int **cordInicial, int **cordFinal, int n, int m, int k){
    //exibindo a matriz com as palvras
        for (int i = 0; i < n; i++){
            if(i == 0){ 
                printf("     ");
                for (int j = 0; j < m; j++)
                    printf("%d ", (j+1));
                printf("\n");
            }
            i < 9 ? printf("%d  - ", (i+1)) : printf("%d - ", (i+1));
            for (int j = 0; j < m; j++)
                printf("%c ", matriz[i][j]);

            printf("\n");
        }
}


int main()
{
    srand ( time(NULL) );
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
                solicitaNomeArquivo(nome);
                break;
            case 3:
                //instrucoes();
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }while(escolha != 1 && escolha != 2);

    FILE *arq = fopen("dicionario.txt", "r"); //abrindo um arquivo pra leitura
    int n = 0, m = 0, quantPalavras = 0;
    char **matriz, **palavras;
    int **linhaUsada, **colunaUsada;  


    if(escolha == 1){ //se for um novo jogo
            fscanf(arq,  "%d %d\n%d\n", &n, &m, &quantPalavras); //lendo as 3 primeiras linhas do dicionario
            palavras = fazMatrizChar(quantPalavras, 100, 1);//criando uma matriz para as palavras
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

            for (int i = 0; i < n; i++){//preenchendo a matriz com valores aleatórios
                for (int j = 0; j < m; j++){
                    matriz[i][j] = 'A' + (char)(rand() % 26);
                    printf("%c ", matriz[i][j]);
                }
                printf("\n");
            }
            printf("\n\nEntrou\n\n");

            
            linhaUsada = fazMatrizInt(quantPalavras, 2);
            colunaUsada = fazMatrizInt(quantPalavras, 2);
            int **linha = fazMatrizInt(quantPalavras, 2), **coluna = fazMatrizInt(quantPalavras, 2), orientacao, verificadorUsado;

            if(dificuldade == 1){ //Dificuldade 1
                for (int i = 0; i < quantPalavras; i++){ //repetir todas as palavras

                    verificadorUsado = 0;
                    linhaUsada[i][0] = -5; //inicializando com valores aletorios a linha inicial.
                    colunaUsada[i][0] = -5;//inicializando com valores aletorios a coluna inicial.
                    linhaUsada[i][1] = 1000; //inicializando com valores aletorios a linha final.
                    colunaUsada[i][1] = 1000;//inicializando com valores aletorios a coluna final.
                    
                    do{//enquanto não achar um espaco, nao muda de palavra
                        
                        orientacao = (rand() % 2); //sorteando 0 ou 1 pra orientação
                        printf("\norientacao: %d - %s", orientacao, palavras[i]);

                        if (orientacao == 0) //se orientacao for igual a zero, é horizontal
                            verificadorUsado = horizontal(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz, 1); 
                            
                        if (orientacao == 1) //se orientacao for igual a 1, é vertical
                            verificadorUsado = vertical(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz, 1);
                        


                        
                    }while(verificadorUsado == 1);
                }    
            }
            if(dificuldade == 2){ //dificuldade 2
                for (int i = 0; i < quantPalavras; i++){ //repetir todas as palavras

                    verificadorUsado = 0;
                    linhaUsada[i][0] = -5; //inicializando com valores aletorios a linha inicial.
                    colunaUsada[i][0] = -5;//inicializando com valores aletorios a coluna inicial.
                    linhaUsada[i][1] = 1000; //inicializando com valores aletorios a linha final.
                    colunaUsada[i][1] = 1000;//inicializando com valores aletorios a coluna final.
                    
                    do{//enquanto não achar um espaco, nao muda de palavra
                        
                        orientacao = (rand() % 3); //sorteando 0, 1 ou 2 pra orientação
                        printf("\norientacao: %d - %s", orientacao, palavras[i]);

                        if (orientacao == 0) //se orientacao for igual a zero, é horizontal
                            verificadorUsado = horizontal(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz, 1); 
                            
                        if (orientacao == 1) //se orientacao for igual a 1, é vertical
                            verificadorUsado = vertical(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz, 1);
                        
                        if(orientacao == 2) //se orientacao for igual a 2, é diagonal
                            verificadorUsado = diagonal(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz, 1);


                        
                    }while(verificadorUsado == 1);
                }

            } 

            if(dificuldade == 3){
                int direcao; //variavel que armazena a direcao em que as palvras são dispostas
                 for (int i = 0; i < quantPalavras; i++){ //repetir todas as palavras

                    verificadorUsado = 0;
                    linhaUsada[i][0] = -5; //inicializando com valores aletorios a linha inicial.
                    colunaUsada[i][0] = -5;//inicializando com valores aletorios a coluna inicial.
                    linhaUsada[i][1] = 1000; //inicializando com valores aletorios a linha final.
                    colunaUsada[i][1] = 1000;//inicializando com valores aletorios a coluna final.
                    
                    do{//enquanto não achar um espaco, nao muda de palavra
                        
                        orientacao = (rand() % 3); //sorteando 0, 1 ou 2 pra orientação
                        direcao = (rand() % 2); //sortea 0 para esquerda ou pra cima e 1 para direita ou pra baixo
                        printf("\norientacao: %d - %s\nDirecao: %d\n", orientacao, palavras[i], direcao);

                        if (orientacao == 0) //se orientacao for igual a zero, é horizontal
                            verificadorUsado = horizontal(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz, direcao); 
                            
                        if (orientacao == 1) //se orientacao for igual a 1, é vertical
                            verificadorUsado = vertical(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz, direcao);
                        
                        if(orientacao == 2) //se orientacao for igual a 2, é diagonal
                            verificadorUsado = diagonal(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz, direcao);


                        
                    }while(verificadorUsado == 1);
                }
            }
        }
        


        printf("\n");

        char comando[40];
        int **coordInicial = fazMatrizInt(quantPalavras, 2);
        int **coordFinal = fazMatrizInt(quantPalavras, 2);
        int cont = 0, *verificador = malloc(quantPalavras);
        
        exibeMatriz(matriz, coordInicial, coordFinal, n, m);
        do{
            printf("\n\nPara jogar digite os seguinte comandos:\n\n\"marcar\".\n\"salvar jogo.txt\" (digite o nome do arquivo apos o comando para salvar.\n\"resolver\" (exibe as palavras marcadas).\n\"sair\" (para sair do jogo).\n");
            scanf("%s", comando);
            finaliza(comando); //finaliza se for digitado o comando de sair
    
            if(strcmp(comando, "marcar") == 0){ //comando de marcar palavra

                //lendo as posicoes
                printf("Voce tem %d tentativas!\n", (quantPalavras - cont));
                printf("Digite a linha e a coluna inicial da palavra. : ");
                scanf("%d %d", &coordInicial[cont][0], &coordInicial[cont][1]);
                printf("\nDigite a linha e a coluna final da palavra. : ");
                scanf("%d %d", &coordFinal[cont][0], &coordFinal[cont][1]);
                coordInicial[cont][0]--;
                coordInicial[cont][1]--;
                coordFinal[cont][0]--;
                coordFinal[cont][1]--;

                //verificando se as coordenadas possuem alguma palavra
                for(int i = 0; i < quantPalavras; i++){
                   // printf("\n\nInicial: %s\nlinha: %d - %d\ncoluna: %d - %d\n\nFinal:\nlinha: %d - %d\n coluna:%d - %d\n",palavras[i], coordInicial[cont][0], linhaUsada[i][0],coordInicial[cont][1], colunaUsada[i][0], coordFinal[cont][0], linhaUsada[i][1], coordFinal[cont][1], colunaUsada[i][1]);
                   
                    if(coordInicial[cont][0] == linhaUsada[i][0] && coordInicial[cont][1] == colunaUsada[i][0] && coordFinal[cont][0] == linhaUsada[i][1] && coordFinal[cont][1] == colunaUsada[i][1]){
                        exibeMatriz(matriz, coordInicial, coordFinal, n, m, i);
                    }
                    else{
                        printf("Palavra desconhecida!");
                    }
                }

                cont++;
            }
            
        }while(strcmp(comando, "sair") != 0);






    return 0;
}
//Milena Santana, 21.1.4175

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
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



//funcao que le as palavras do arquivo dicionario e armazena na matriz
void preenche_palavras(char **matriz, FILE *arquivo, int m){ 
    for(int i = 0; i < m; i++){
        fscanf(arquivo, "%s\n", matriz[i]);
    }
}

//funcao para criar matriz de char 
char ** criaMatriz(int m, int n){
    char **mat = malloc(m * sizeof(char*));
    for(int i = 0; i < m; i++){
        mat[i] = malloc( n * sizeof(char));
    }
    return mat;
}

//funcao para criar matriz de int
int ** criaMatrizInt(int m, int n){
    int **mat = malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        mat[i] = malloc( n * sizeof(int));
    }
    return mat;
}

//funcao para liberar o espaço alocado para a matriz
void liberaMatriz(char ** A, int m){
     for(int i = 0; i < m; i++){
        free(A[i]);
    }
    free(A);
}

//funcao para liberar o espaço alocado para a matriz
void liberaMatrizInt(int ** A, int m){
     for(int i = 0; i < m; i++){
        free(A[i]);
    }
    free(A);
}

//funcao para fechar arquivos
void fechaArquivo(FILE * arq){
    fclose(arq);
}


int faz_horizontal(int ** comeco, int *tam ,int ** fim, int ** linha, int ** coluna, int i, int n, int m, char ** matriz, char ** palavras, int d){
    int ocupado = 0;
        //variavel que diz se o local sorteado esta livreint ocupado = 0;
        for(int j = 0; j <= i; j ++){
            
            //0 -- linha do comeco  e 1 -- coluna do comeco
            comeco[i][0] = (rand() % n); 
            comeco[i][1] = (rand() % m); 

            //0 -- linha do final  e 1 -- coluna do final

            if (d == 0)
                fim[i][1] = comeco[i][1] + tam[i] - 1;
            else
                fim[i][1] = comeco[i][1] - tam[i] + 1;
            
            fim[i][0] = comeco[i][0];



        if(fim[i][1] > (m-1) || fim[i][1] < 0){
                ocupado = 1;
            }

            if(comeco[i][0] >= linha[j][0] && comeco[i][0] <= linha[j][1] && comeco[i][1] <= coluna[j][0] && fim[i][1] <= coluna[j][1]){
            ocupado = 1;
            }

            if(linha[j][0] == comeco[i][0]){

                if(comeco[i][1] >= coluna[j][0] && comeco[i][1] <= coluna[j][1]) 
                    ocupado = 1;

                if(fim[i][1] >= coluna[j][0] && fim[i][1] <= coluna[j][1]) 
                    ocupado = 1;

                if((m - coluna[j][1]) < (tam[i] - 1) && coluna[j][0] < (tam[i] - 1))
                ocupado = 1;

            }
            else if (ocupado == 0){

                //preenchendo matriz de linhas e colunas usadas
                linha[i][0] = comeco[i][0]; 
                linha[i][1]= fim[i][0]; 
                coluna[i][0] = comeco[i][1]; 
                coluna[i][1] = fim[i][1];  
            
                
                for(int k = 0; k < tam[i]; k++){
                    if(d == 0)
                        matriz[linha[i][0]][coluna[i][0] + k] = toupper(palavras[i][k]);
                    else
                        matriz[linha[i][0]][coluna[i][0] - k] = toupper(palavras[i][k]);

                } 
                break;             
            }
        }
        return ocupado;
    
}


int faz_vertical(int ** comeco, int * tam ,int ** fim, int ** linha, int ** coluna, int i, int n, int m, char ** matriz, char ** palavras, int d){
   int ocupado = 0;

        for(int j = 0; j <= i; j ++){
            
            //0 -- linha do comeco  e 1 -- coluna do comeco
            comeco[i][0] = (rand() % n); 
            comeco[i][1] = (rand() % m); 


            //0 -- linha do final  e 1 -- coluna do final
            if (d == 0) 
                fim[i][0] = comeco[i][0] + tam[i] - 1;
            else
                fim[i][0] = comeco[i][0] - tam[i] + 1;
            
            fim[i][1] = comeco[i][1];
    

            if(comeco[i][0] >=  linha[j][0] && comeco[i][0] <= linha[j][1] && comeco[i][1] >= coluna[j][0] && comeco[i][1] <= coluna[j][1]){
                // variavel sorteada esta entre linhas e colunas ja utilizadas
                ocupado = 1;
            }
            if( fim[i][1] > (m-1) || fim[i][0] < 0 || fim[i][1] < 0){
                ocupado = 1;
            }
            
            if(coluna[j][0] == comeco[i][1]){

                if(comeco[i][0] >= linha[j][0] && comeco[i][0] <= linha[j][1]) 
                    ocupado = 1;


                if(fim[i][0] >= linha[j][0] && fim[i][0] <= linha[j][1]) 
                    ocupado = 1;


                if((n - linha[j][1]) < (tam[i] - 1) && linha[j][0] < (tam[i] - 1))
                    ocupado = 1;
            }


            else if (ocupado == 0){
                linha[i][0] = comeco[i][0]; 
                linha[i][1]= fim[i][0];
                coluna[i][0] = comeco[i][1]; 
                coluna[i][1] = fim[i][1]; 

               

                for(int k = 0; k < tam[i]; k++){
                    if(d == 0)
                        matriz[linha[i][0] + k][coluna[i][0]] = toupper(palavras[i][k]);   
                    else
                        matriz[linha[i][0] - k][coluna[i][0]] = toupper(palavras[i][k]);  

                }  
                break;            
            }
        }
        return ocupado;

}


int faz_diagonal(int ** comeco, int * tam, int ** fim, int ** linha, int ** coluna, int i, int n, int m, char ** matriz, char ** palavras, int d){
    int ocupado;
    for (int j = 0; j <= i; j++){          
        ocupado = 0;
        //0 -- linha do comeco  e 1 -- coluna do comeco
        comeco[i][0] = (rand() % n); 
        comeco[i][1] = (rand() % m);

        //0 -- linha do final  e 1 -- coluna do final calculadas
        if(d == 0){
            fim[i][0] = comeco[i][0] + tam[i] -1;
            fim[i][1] = comeco[i][1] + tam[i] -1; 
        }else{
            fim[i][0] = comeco[i][0] - tam[i] +1;
            fim[i][1] = comeco[i][1] - tam[i] +1; 
        }

    
        if(comeco[i][1] >= coluna[j][0] && comeco[i][1] <= coluna[j][1] && comeco[i][0] <= linha[j][0] && comeco[i][0] >= linha[j][0])
                ocupado = 1;
        
    
        if(comeco[i][0] >= linha[j][0] && comeco[i][0] <= linha[j][1] && comeco[i][1] <= coluna[j][0] && comeco[i][1] >= coluna[j][0])
                ocupado = 1;


        if(coluna[j][0] == comeco[i][1]){

            if(comeco[i][0] >= linha[j][0] && comeco[i][0] <= linha[j][1]) 
                ocupado = 1;


            if(fim[i][0] >= linha[j][0] && fim[i][0] <= linha[j][1]) 
                ocupado = 1;


            if((n - linha[j][1]) < (tam[i] - 1) && linha[j][0] < (tam[i] - 1)) 
                ocupado = 1;
            
        }

        if(fim[i][0] > (n-1) || fim[i][1] > (m -1) || fim[i][0] < 0 || fim[i][1] < 0){
            ocupado = 1;
        }
            
        
        else if (ocupado == 0){
            linha[i][0] = comeco[i][0]; 
            linha[i][1]= fim[i][0]; 
            coluna[i][0] = comeco[i][1];
            coluna[i][1] = fim[i][1];  

            for(int k = 0; k < tam[i]; k++)
                if(d == 0)
                    matriz[comeco[i][0]+k][comeco[i][1]+k] = toupper(palavras[i][k]); 
                else
                    matriz[comeco[i][0]- k][comeco[i][1]- k] = toupper(palavras[i][k]); 

            break;    
        }
    }
    return ocupado;
}


//lendo um jogo salvo e armazenando suas palavras e respectivas coordenadas
void lendoJogoSalvo(char ini[2], char fin[2], char **comeca, char **termina, char ** palavras, int qtd, FILE *arq ){
    for(int i = 0; i < qtd; i++){
        fscanf(arq, "%s %s %s", palavras[i], ini, fin);
        comeca[0][i] = ini[0]; // linha inicial das palavras
        comeca[1][i] = ini[1]; // coluna inicial das palavras
        termina[0][i] = fin[0]; //linha final das palavras
        termina[1][i] = fin[1]; // coluna final das palavras
    }
}

int verifica_disposicao(char ** iniciais, char ** finais, int i){
    int r;
    //inciais [0] -- linha inicial
    //inciais [1] -- coluna inicial
    //finais [0] -- linha final
    //finais [1] -- coluna final
    if(strcmp(&iniciais[i][0], &finais[i][0])){
        //palavra na horizontal
        r = 0;
    }
    if(strcmp(&iniciais[i][1], &finais[i][1])){
        //palavra na vertical
        r = 1;
    }
    else{
        r = 2;
    }

    return r;
}

int main(){
    srand ( time(NULL) );
    char ** matriz;
    int m, n, op, qtd = 0;
    char  arquivo [50], **palavras, comando[50];
do{
    printf("Bem vindo ao jogo de CAÇA-PALAVRAS!\n");
    printf("Digite a opção desejada: \n\n");
    printf("1. Começar um novo jogo;\n2. Continuar um jogo salvo\n3. Ler instruções\n\n");
    scanf("%d", &op);

    switch (op){
        case 1:{
            printf("Digite o nome do arquivo com a lista das palavras: \n");
            scanf("%s", arquivo);
            FILE *file = fopen(arquivo, "r");
            fscanf(file, "%d\n", &n); //linha
            fscanf(file, "%d\n", &m); //coluna
            fscanf(file, "%d\n", &qtd); //quantidade de palavras
            palavras = criaMatriz(qtd, 50); // criando uma matriz de string para ler as palavras
            preenche_palavras(palavras, file, qtd); // preenchendo a matriz com as palavras do arquivo
            matriz = criaMatriz(n, m); // criando a matriz que será o futuro caça palavras
           
            for (int i = 0; i < n; i++){ 
                //preenchendo a matriz com valores aleatórios
                for (int j = 0; j < m; j++){
                    matriz[i][j] = 'A' + (char)(rand() % 26);
                }
            }

            int *tam = malloc(qtd);
            for(int i = 0; i < qtd; i ++){
                tam[i] = strlen(palavras[i]);
            }

            int **comeco = criaMatrizInt(qtd, 2), **fim = criaMatrizInt(qtd, 2), *pos = malloc(qtd * sizeof(int));
            int **linOcupada = criaMatrizInt(qtd, 2), **colOcupada = criaMatrizInt(qtd, 2); 
            int ocupado = 0; 

            for(int i = 0; i < qtd; i++){
                for(int j = 0; j < 2; j++){
                    linOcupada[j][i] = -1;
                    colOcupada[j][i] = -1;
                }
            }

            int nivel;
            printf("Escolha o nível de dificuldade:\n(1) fácil\n(2) médio\n(3) difícil\n");
            scanf("%d", &nivel);

            if(nivel==1){
                for (int i = 0; i < qtd; i++){ 
                    do{
                        pos[i] = (rand() % 2); 
                        if (pos[i] == 0){
                            //palavra horizontal
                            ocupado = faz_horizontal(comeco, tam,fim, linOcupada, colOcupada, i, n, m, matriz, palavras, 0);
                        } else{
                            // palavra na vertical
                            ocupado = faz_vertical(comeco, tam, fim, linOcupada, colOcupada, i , n , m, matriz, palavras, 0);
                        }
                    }while(ocupado == 1);
                }

            }
            if(nivel ==2){
                for (int i = 0; i < qtd; i++){ 
                        do{
                            pos[i] = (rand() % 3);

                            if (pos[i] == 0){
                                //palavra horizontal
                                 ocupado = faz_horizontal(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, 0);
                            }
                            if( pos[i] == 1){
                                // palavra na vertical
                                ocupado = faz_vertical(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, 0);
                            }
                            if(pos[i] == 2){
                                //palavra na diagonal
                                ocupado = faz_diagonal(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, 0);
                            }
                        }while(ocupado == 1);
                        
                    
                }
            }   
            if(nivel == 3){
                int d;
                 for (int i = 0; i < qtd; i++){ 
                        
                        pos[i] = (rand() % 3); 
                        d = (rand() % 2);
                        if (pos[i] == 0)
                        //palavra na horizontal
                            ocupado = faz_vertical(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, d); 
                            
                        if (pos[i] == 1) 
                        //palavra na vertical
                            ocupado = faz_vertical(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, d);
                        
                        if(pos[i] == 2) 
                        //palavra na diagonal
                           ocupado = faz_diagonal(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, d);
                }
            } 

            char **cmc = criaMatriz(qtd, 2);
            char **fin = criaMatriz(qtd, 2);
            for(int i = 0; i < qtd; i ++){
                cmc[i][0] = '-';
                fin[i][0] = '-';
                cmc[i][1] = '-';
                fin[i][1] = '-';
            }

            printf("    ");
            for (int j = 0; j < m; j++){
                printf("%c ", (j+65));
            }
            printf("\n");
            for(int i = 0; i < n; i++){
                printf("%c - ", (i+65));
            for (int j = 0; j < m; j++)
                printf("%c ", matriz[i][j]);

            printf("\n");
            }
            int cont = 0, *verificador = malloc(qtd * sizeof(int)); 
            
            printf("\nDigite o comando (MARCAR, SALVAR OU SAIR):\n");
            scanf("%s", comando);
    
            if(strcmp(comando, "marcar") == 0){ 
                printf("Agora, digite as coordenadas: \n");
                scanf("%c %c %c %c",&cmc[cont][0], &cmc[cont][1], &fin[cont][0], &fin[cont][1] );
                for(int i = 1; i < qtd; i++){
                    printf("%d %d %d %d\n", linOcupada[i][0], colOcupada[i][0], linOcupada[i][1], colOcupada[i][1]);
                    if(((int)cmc[cont][0] - 97 )== linOcupada[i][0] && ((int)cmc[cont][1] - 97 )== colOcupada[i][0] && ((int)fin[cont][0] - 97 )== linOcupada[i][1] && ((int)fin[cont][1] - 97 )== colOcupada[i][1]){
                        printf("%d %d", (int)cmc[cont][0] - 98, linOcupada[i][0]);
                        verificador[cont] = 1; //se acertar alguma palavra, ele salva 1 
                    }
                    else{
                        printf("Palavra desconhecida!");
                    }
                }

                cont++;
            }
            if(strcmp(comando, "salvar") == 0){
                printf("Digite o nome do arquivo par armazenar o jogo:\n");
                scanf("%s", arquivo);
                FILE * file = fopen(arquivo, "w");
                fprintf(file, "%d %d\n", n, m );
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        fprintf(file, "%c ", matriz[i][j]);
                    }
                    fprintf(file, "\n");
                }
                fprintf(file, "%d\n", qtd);
                for(int i = 0; i< qtd; i ++){
                    fprintf(file, "%s ", palavras[i]);
                    fprintf(file, "%c%c %c%c", cmc[i][0], cmc[i][1], fin[i][0], fin[i][1]);
                    
                    fprintf(file, "\n");
                }
                op = 0;
            }
            if(strcmp(comando, "resolver") == 0){
                printf("    ");
                for (int j = 0; j < m; j++){
                    printf("%c ", (j+65));
                }
                printf("\n");
                for(int i = 0; i < n; i++){
                    printf("%c - ", (i+65));
                for (int j = 0; j < m; j++)
                    if( (i == colOcupada[i][0] && j == linOcupada[i][0]) ){
                        textcolor( CN_REVERSE , CN_NO_COLOR , CN_NO_COLOR);
                        printf("%c ", matriz[i][j]); 
                    }else{
                        textcolor( CN_NORMAL , CN_NO_COLOR , CN_NO_COLOR);
                        printf("%c ", matriz[i][j]);
                    }

                printf("\n");
                }
                printf("Deseja realizar um novo jogo?\n(1)SIM\n(2)NAO\n");
                scanf("%d", &op);
                if(op == 2){
                    op = 0;
                }
            }
           if( strcmp(comando, "sair") == 0){
               op = 0;
           }

        break;
        liberaMatriz(cmc, qtd);
        liberaMatriz(fin, qtd);
        liberaMatrizInt(comeco, qtd);
        liberaMatrizInt(fim, qtd);
        liberaMatrizInt(linOcupada, qtd);
        liberaMatrizInt(colOcupada, qtd);
        liberaMatriz(palavras, qtd);
        liberaMatriz(matriz, n);
        fechaArquivo(file);
        
        }

        case 2: {
            printf("Digite o nome do arquivo com o jogo salvo:\n");
            scanf("%s", arquivo);
            FILE *arq = fopen(arquivo, "r");
            fscanf(arq, "%d %d\n", &n, &m); //lendo a linha e coluna do arquivo
            matriz = criaMatriz(n, m); 

            //lendo a matriz do arquivo
            for(int j = 0; j < n; j++){
                for(int k = 0; k < m; k++){
                    fscanf(arq, "%c ", &matriz[j][k]);
                }
            }
            fscanf(arq, "\n%d", &qtd); // lendo a quantidade de palavras
            palavras = criaMatriz(qtd, 50); //criando a matriz para armazenar as palavras

            char inicio[3], fim[3], **comeca, **termina;
            comeca = criaMatriz(qtd, 2);
            termina = criaMatriz(qtd, 2);
            for(int i = 0; i < qtd; i ++){
                comeca[i][0] = '-';
                termina[i][0] = '-';
                comeca[i][1] = '-';
                termina[i][1] = '-';
            }
            lendoJogoSalvo(inicio, fim, comeca, termina, palavras, qtd, arq);

            printf("\n");
            printf("    ");
            for (int j = 0; j < m; j++){
                printf("%c ", (j+65));
            }
            printf("\n");
            int p = 0;
            for(int j = 97; j < (n + 97); j++){
                int q = 0;
                printf("%c - ", (j-32));
                for(int k = 97; k < (m + 97); k++){ 
                        if(j >= comeca[0][p] && j <= termina[1][p] && k >= comeca[1][p] && k <= termina[1][p]){
                            textcolor( CN_REVERSE , CN_NO_COLOR , CN_NO_COLOR);
                            printf("%c ", matriz[p][q]); 
                        }
                        else{
                            textcolor( CN_NORMAL, CN_NO_COLOR, CN_NO_COLOR );
                            printf("%c ", matriz[p][q]);
                        }
                    q++;
                }
                printf("\n");
                p++;
            }

            printf("\nDigite o comando (MARCAR, SALVAR OU SAIR):\n");
            scanf("%s", comando);
            int cont = 0;
            op = 1;
    
            if(strcmp(comando, "marcar") == 0){ 
                printf("Agora, digite as coordenadas: \n");
                scanf("%c %c %c %c",&comeca[cont][0], &comeca[cont][1], &termina[cont][0], &termina[cont][1] );
            }
            if(strcmp(comando, "salvar") == 0){
                FILE * file = fopen(arquivo, "w");
                fprintf(file, "%d %d\n", n, m );
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        fprintf(file, "%c ", matriz[i][j]);
                    }
                    fprintf(file, "\n");
                }
                fprintf(file, "%d\n", qtd);
                for(int i = 0; i< qtd; i ++){
                    fprintf(file, "%s ", palavras[i]);
                    fprintf(file, "%c%c %c%c",  comeca[i][0], comeca[i][1], termina[i][0], termina[i][1]);
                    
                    fprintf(file, "\n");
                }
                printf("Arquivo atualizado com sucesso!\n");
                op = 0;
            }
            
           else if( strcmp(comando, "sair") == 0){
               op = 0;
           }

            liberaMatriz(comeca, qtd);
            liberaMatriz(termina, qtd);
            liberaMatriz(palavras, qtd);
            liberaMatriz(matriz, n);
            fechaArquivo(arq);
            break;
        }
        case 3: {
            printf("\nINSTRUÇÕES\n\n");
            printf("O jogo CAÇA-PALAVRAS é um jogo no qual será exibida uma matriz com m colunas e n linhas, escolhidas por você e informadas na primeira linha do arquivo*.\n");
            printf("Dentro dessa matriz, terá varias letras aleatórias. Você encontrará, em algum conjunto de posições da matriz, que essas letras formam algumas palavras, que também serão escolhidas e inseridas no arquivo*.\n");
            printf("Quando encontrar uma palavra, deverá marcá-la no caça-palavras. ");
            printf("Para isso, deverá digitar o comando \"marcar\" + coluna linha inicial + coluna linha final.\nExemplo: marcar AB CE, indica que a palavra começa na linha \"A\" coluna \"B\" e termina na linha \"C\" coluna \"E\" \n");
            printf("Para salvar o jogo e continuá-lo depois, basta digitar o comando \"salvar\" + o nome do arquivo em que deseja salvar (com a extensão .txt).\n");
            printf("Para visualizar o caça-palavras resolvido, digite \"resolver\" e para sair, digite \"sair\"\n");
            printf("Lembrando que ao sair, não serão salvas nenhuma alteração feita.\n\n");
            printf("* a estrutura do arquivo .txt deverá ser o seguinte:\n - Primeira linha: dimensões da matriz - linhas e colunas, respectivamente;\n - Segunda linha: Número de palavras;\n - Próximas linhas: as palavras escolhidas.\n\n");
            printf("Deseja voltar ao menu?\n(1)SIM\n(2)NAO\n");
            scanf("%d", &op);
            if(op == 2){
                op = 0;
            }
        break;        
        }
        default: {
        printf("Opção inválida!\n\n");
        
        break;
        }

    liberaMatriz(matriz, n);
    }
}while(op != 0);
    return 0;
}
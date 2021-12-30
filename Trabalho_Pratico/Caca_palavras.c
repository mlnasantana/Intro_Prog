//Milena Santana de Almeida, 21.1.4175

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET

// caracteres uteis para tabelas
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)
 

/* 
 * Funcao que imprime um exemplo de uso das cores e tabelas 
 */
void example() {
    // imprimindo uma tabela de exemplo
    printf("\n");
    printf(TAB_TL TAB_HOR TAB_TJ TAB_HOR TAB_TJ TAB_HOR TAB_TR "\n");
    printf(TAB_VER "a" TAB_VER "b" TAB_VER "c" TAB_VER "\n");
    printf(TAB_ML TAB_HOR TAB_MJ TAB_HOR TAB_MJ TAB_HOR TAB_MR "\n");
    printf(TAB_VER "d" TAB_VER "e" TAB_VER "f" TAB_VER "\n");
    printf(TAB_BL TAB_HOR TAB_BJ TAB_HOR TAB_BJ TAB_HOR TAB_BR "\n");
    printf("\n");

    // imprimindo textos com cores
    printf("\n");
    printf(BOLD(RED("vermelho negrito!")) "\n");
    printf(BLUE("azul!") "\n");
    printf(GREEN("verde!") "\n");
    printf(CYAN(BOLD("ciano negrito!")) "\n");
    printf(BOLD("negrito!") "\n");
    printf("texto normal\n");
    printf("\n");

    // imprimindo cores de fundo
    printf("\n");
    printf(BOLD(BG_RED("fundo vermelho e texto negrito!")) "\n");
    printf(WHITE(BG_BLUE("fundo azul e texto branco!")) "\n");
    printf(BG_GREEN(RED("fundo verde e texto vermelho!")) "\n");
    printf(BG_CYAN(BOLD("fundo ciano e texto negrito!")) "\n");
    printf(BG_WHITE(BLACK(BOLD("fundo branco e texto escuro negrito!"))) "\n");
    printf(BG_BLACK(WHITE(BOLD("fundo preto e texto branco negrito!"))) "\n");
    printf("texto normal\n");
    printf("\n");

    // imprimindo um pequeno "tabuleiro"    
    printf(BG_CYAN("  ") "  " BG_CYAN("  ") "  " BG_CYAN("  ") "  " "\n");
    printf("  " BG_CYAN("  ") "  " BG_CYAN("  ") "  " BG_CYAN("  ") "\n");
    printf(BG_CYAN("  ") "  " BG_CYAN("  ") "  " BG_CYAN("  ") "  " "\n");
    printf("  " BG_CYAN("  ") "  " BG_CYAN("  ") "  " BG_CYAN("  ") "\n");
    printf(BG_CYAN("  ") "  " BG_CYAN("  ") "  " BG_CYAN("  ") "  " "\n");
    printf("  " BG_CYAN("  ") "  " BG_CYAN("  ") "  " BG_CYAN("  ") "\n");
    printf("\n");

}

const int max=10;
char mat[11][11], palavra[], encontrada[];
int tam = 0;
int op,opPesquisa,i,j,k,l,m,n,o,p,q,r,s,t;
int *pos1,*pos2;

void menuPrincipal()
{
    printf("\n\n\t================MENU================\n");
    printf("\t1 - Cria Matriz a partir do teclado\n");
    printf("\t2 - Imprime a Matriz\n");
    printf("\t3 - Solicita uma palavra\n");
    printf("\t4 - Pesquisa\n");
    printf("\t5 - Executa teste padrao\n");
	printf("\t0 - Sair do Programa\n\n");
	printf("\tEscolha uma opcao: ");
    scanf("%d", &op);
    
	switch (op){
        
		case 1:
			leia();
		break;

		case 2:
        	imprima();
		break;

        case 3:
            leiaCad();
        break;

        case 4:
            pesquisa();
        break;

        case 5:
            matTeste();
        break;

        case 0:
        	system("cls");
            printf("\n\tSaindo...\n");
            return 0;
        break; 

        default:
            printf("\nValor invalido\n");
        break;
    }	
}

void leia(){
    
    system("cls");
    printf("\n\tInsira o tamanho da matriz quadrada(M x M): ");
    printf("\n\t*Insira as letras da Matriz*\n\n");
    printf("\t(ex: abcde...) (%d letras)\n",max);

	for (i = 0; i < max; i++)
	{
			printf("\tLinha %d: ",i);
            fflush(stdin);
            gets(mat[i]);
	}
    printf("\n\t!!!Pressione qualquer tecla para retornar ao menu principal!!!\n\n");
    system("pause>null");
    menuPrincipal();
}

void imprima(){

    system("cls");
    printf("\n\tMATRIZ:\n");
    printf("\t");
    for(i = 0; i < max; i++)
    {
        printf("%d ",i);
    }
      printf("\n\t");
        for(i = 0; i < max; i++)
        {
            printf("| ",i);
        }

    printf("\n");

    for (j = 0; j < max; j++)
	{
    printf("    %d--",j);
    printf("\t");
        for (k = 0; k < max; k++)
		{
			printf("%c ",mat[j][k]);
		}
    printf("\n");
	}
    menuPrincipal();  
}

void leiaCad(){
    

    printf("\n\t-----------------------------------");
    printf("\n\tInsira a palavra a ser encontrada: ");
	fflush(stdin);
    scanf("%s", palavra); 

    printf("\n\n\t!!!Pressione qualquer tecla para retornar ao menu principal!!!\n");
    system("pause>null");
    menuPrincipal();
}

void pesquisa(){

    printf("\n\t==========Escolha a direcao da pesquisa==========\n\n");
    printf("\t1 - Esquerda --> Direita\n");
    printf("\t2 - Direita --> Esquerda\n");
    printf("\t3 - Cima --> Baixo\n");
    printf("\t4 - Baixo --> Cima\n");
	printf("\t0 - Retornar ao menu principal\n\n");
	printf("\tEscolha uma opcao: ");
    
    scanf("%d", &opPesquisa);

    switch (opPesquisa){
        
		case 1:
			esqdir(palavra);
		break;

		case 2:
        	diresq(palavra);
		break;

        case 3:
            cimbaix(palavra);
        break;
        
        case 4:
            baixcim(palavra);
        break;  

        case 0:
        	printf("\n\n\t!!!Pressione qualquer tecla para retornar ao menu principal!!!\n");
            system("pause>null");
            menuPrincipal(); 
        break; 
        
        default:
            printf("\nValor invalido\n");
        break;
    }
}	

void matTeste(){
    
    mat[0][0]='G'; mat[0][1]='A'; mat[0][2]='O'; mat[0][3]='O'; mat[0][4]='E'; mat[0][5]='F'; mat[0][6]='S'; mat[0][7]='B'; mat[0][8]='A'; mat[0][9]='B';
	mat[1][0]='X'; mat[1][1]='T'; mat[1][2]='D'; mat[1][3]='L'; mat[1][4]='Y'; mat[1][5]='U'; mat[1][6]='A'; mat[1][7]='R'; mat[1][8]='B'; mat[1][9]='R'; 
	mat[2][0]='O'; mat[2][1]='L'; mat[2][2]='A'; mat[2][3]='S'; mat[2][4]='A'; mat[2][5]='P'; mat[2][6]='T'; mat[2][7]='M'; mat[2][8]='E'; mat[2][9]='R';
	mat[3][0]='A'; mat[3][1]='E'; mat[3][2]='S'; mat[3][3]='A'; mat[3][4]='E'; mat[3][5]='G'; mat[3][6]='O'; mat[3][7]='Z'; mat[3][8]='I'; mat[3][9]='N';
	mat[4][0]='P'; mat[4][1]='T'; mat[4][2]='C'; mat[4][3]='R'; mat[4][4]='U'; mat[4][5]='Z'; mat[4][6]='E'; mat[4][7]='I'; mat[4][8]='R'; mat[4][9]='O';
	mat[5][0]='C'; mat[5][1]='I'; mat[5][2]='S'; mat[5][3]='E'; mat[5][4]='G'; mat[5][5]='U'; mat[5][6]='N'; mat[5][7]='D'; mat[5][8]='A'; mat[5][9]='X';
	mat[6][0]='A'; mat[6][1]='C'; mat[6][2]='C'; mat[6][3]='A'; mat[6][4]='M'; mat[6][5]='P'; mat[6][6]='E'; mat[6][7]='A'; mat[6][8]='O'; mat[6][9]='X';
	mat[7][0]='O'; mat[7][1]='O'; mat[7][2]='V'; mat[7][3]='O'; mat[7][4]='E'; mat[7][5]='M'; mat[7][6]='E'; mat[7][7]='L'; mat[7][8]='H'; mat[7][9]='O';
	mat[8][0]='A'; mat[8][1]='C'; mat[8][2]='P'; mat[8][3]='A'; mat[8][4]='L'; mat[8][5]='T'; mat[8][6]='O'; mat[8][7]='C'; mat[8][8]='A'; mat[8][9]='S';
	mat[9][0]='G'; mat[9][1]='A'; mat[9][2]='N'; mat[9][3]='H'; mat[9][4]='O'; mat[9][5]='U'; mat[9][6]='B'; mat[9][7]='O'; mat[9][8]='N'; mat[9][9]='I';
	mat[9][0]='G'; mat[9][1]='o'; mat[9][2]='a'; mat[9][3]='z'; mat[9][4]='z'; mat[9][5]='z'; mat[9][6]='a'; mat[9][7]='m'; mat[9][8]='a'; mat[9][9]='l';
    imprima();
}

void esqdir(char palavra[]){
    
    int naoEncontrada = 0;

    tam = strlen(palavra);

    for (k = 0; k < max; k++)
    {  
        for (l = 0; l < max; l++)
        {    
            int l1 = 0;
            while(mat[k][l+l1] == palavra[l1] && mat[l][l+l1] != '\0' && l1 != tam && (l+l1) != max)
            {
                l1++;
                if(l1==tam)
                {
                    printf("\n\n\tPalavra '%s' ENCONTRADA!!!\n\tDir --> Esq: lin: %d col: %d", palavra, k, l);
                    naoEncontrada++;
                }

            }
              
        }
             
	}

    if(naoEncontrada==0)
    {
        printf("\n\tPalavra nao encontrada");
    }
}

void diresq(char palavra[]){
    int naoEncontrada = 0;
    tam = strlen(palavra);

    for (o = 0; o < max; o++)
    {  
        for (p = max-1; p > -1; p--)
        {    
            int cont = 0;
            while(mat[o][p-cont] == palavra[cont] && cont != tam && (p - cont) != -1)
            {
                cont++;
                if(cont == tam)
                {
                    printf("\n\n\tPalavra '%s' ENCONTRADA!!!\n\tDir --> Esq: lin: %d col: %d\n", palavra, o,p);
                    naoEncontrada++;
                }
            }
              
        }
             
	}

    if(naoEncontrada == 0)
    {
        printf("\n\tPalavra nao encontrada");
    }


}

void cimbaix(char palavra[]){
    int naoEncontrada = 0;
    tam = strlen(palavra);
    for (int q = 0; q < max; q++)
    { 
        for (int r = 0; r < max; r++)
        {    
            int cont = 0;
            while(mat[r + cont][q] == palavra[cont] && mat[r + cont][q] != '\0' && cont != tam && (r + cont) != max)
            {
                cont++;
                if(cont == tam)
                {
                    printf("\n\n\tPalavra '%s' ENCONTRADA!!!\n\tCim --> Baix: lin: %d col: %d\n", palavra, q,r);
                    naoEncontrada++;
                }
            }             
        }
             
	}

    if(naoEncontrada==0)
    {
        printf("\n\tPalavra nao encontrada");
    }
 }

 void baixcim(char palavra[]){
    int naoEncontrada = 0;
    tam = strlen(palavra);
    for (int s = 0; s < max; s++)
    {  
        for (int t = max-1; t > -1; t--)
        {    
            int cont = 0;
            while(mat[t - cont][s] == palavra[cont] && cont != tam && (t - cont) != max)
            {
                cont++;
                if(cont == tam)
                {
                    printf("\n\n\tPalavra '%s' ENCONTRADA!!!\n\tBaix --> Cim: lin: %d col: %d\n", palavra, t,s);
                    naoEncontrada++;
                }
            }
              
        }
             
	}

    if(naoEncontrada==0)
    {
        printf("\n\tPalavra nao encontrada");
    }
}

int main(){
    example()
    menuPrincipal();


 return 0;
}
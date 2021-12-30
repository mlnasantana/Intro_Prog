#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int max=10;
char mat[10][10], palavra[], encontrada[];
int tam = 0;
int op,opPesquisa,i,j,k,l,m,n,o,p,q,r,s,t;
int *pos1,*pos2;

void menuPrincipal();
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

void leia();
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

void imprima();
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

void leiaCad();
void leiaCad(){
    printf("\n\t-----------------------------------");
    printf("\n\tInsira a palavra a ser encontrada: ");
	fflush(stdin);
    scanf("%s", palavra); 

    printf("\n\n\t!!!Pressione qualquer tecla para retornar ao menu principal!!!\n");
    system("pause>null");
    menuPrincipal();
}

void pesquisa();
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

void matTeste();
void matTeste(){
    mat[0][0]='a'; mat[0][1]='b'; mat[0][2]='a'; mat[0][3]='c'; mat[0][4]='a'; mat[0][5]='x'; mat[0][6]='a'; mat[0][7]='b'; mat[0][8]='a'; mat[0][9]='a';
	mat[1][0]='c'; mat[1][1]='b'; mat[1][2]='y'; mat[1][3]='f'; mat[1][4]='a'; mat[1][5]='z'; mat[1][6]='a'; mat[1][7]='a'; mat[1][8]='a'; mat[1][9]='l'; 
	mat[2][0]='i'; mat[2][1]='t'; mat[2][2]='a'; mat[2][3]='e'; mat[2][4]='s'; mat[2][5]='t'; mat[2][6]='e'; mat[2][7]='r'; mat[2][8]='o'; mat[2][9]='a';
	mat[3][0]='p'; mat[3][1]='i'; mat[3][2]='r'; mat[3][3]='a'; mat[3][4]='v'; mat[3][5]='e'; mat[3][6]='r'; mat[3][7]='o'; mat[3][8]='f'; mat[3][9]='f';
	mat[4][0]='o'; mat[4][1]='z'; mat[4][2]='t'; mat[4][3]='a'; mat[4][4]='z'; mat[4][5]='m'; mat[4][6]='a'; mat[4][7]='d'; mat[4][8]='i'; mat[4][9]='f';
	mat[5][0]='i'; mat[5][1]='x'; mat[5][2]='q'; mat[5][3]='m'; mat[5][4]='u'; mat[5][5]='a'; mat[5][6]='l'; mat[5][7]='a'; mat[5][8]='l'; mat[5][9]='i';
	mat[6][0]='t'; mat[6][1]='c'; mat[6][2]='w'; mat[6][3]='n'; mat[6][4]='u'; mat[6][5]='s'; mat[6][6]='u'; mat[6][7]='l'; mat[6][8]='g'; mat[6][9]='n';
	mat[7][0]='t'; mat[7][1]='e'; mat[7][2]='s'; mat[7][3]='t'; mat[7][4]='e'; mat[7][5]='d'; mat[7][6]='e'; mat[7][7]='l'; mat[7][8]='i'; mat[7][9]='n';
	mat[8][0]='h'; mat[8][1]='o'; mat[8][2]='m'; mat[8][3]='a'; mat[8][4]='r'; mat[8][5]='o'; mat[8][6]='b'; mat[8][7]='o'; mat[8][8]='b'; mat[8][9]='a';
	mat[9][0]='k'; mat[9][1]='o'; mat[9][2]='a'; mat[9][3]='z'; mat[9][4]='z'; mat[9][5]='z'; mat[9][6]='a'; mat[9][7]='m'; mat[9][8]='a'; mat[9][9]='l';
    imprima();
}

void esqdir(char palavra[]);
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

void diresq(char palavra[]);
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

void cimbaix(char palavra[]);
void cimbaix(char palavra[]){
    int naoEncontrada = 0;
    //printf("\n%s\n",palavra);
    tam = strlen(palavra);
    //printf("\ntamanho antes: %d\n",tam);
    for (int q = 0; q < max; q++)
    { 
        for (int r = 0; r < max; r++)
        {    
            //printf("linc %d coli %d\n", q,r);
            int cont = 0;
            //printf("\ntam dps: %d\n",tam);
            while(mat[r + cont][q] == palavra[cont] && mat[r + cont][q] != '\0' && cont != tam && (r + cont) != max)
            {
                //printf("\nletra: %c\n", mat[q][r]);
                //printf("\nDentro while\n");
                cont++;
                //printf("\ntamanho: %d\n",tam);
                if(cont == tam)
                {
                    printf("\n\n\tPalavra '%s' ENCONTRADA!!!\n\tCim --> Baix: lin: %d col: %d\n", palavra, q,r);
                    naoEncontrada++;
                    //printf("\ndentro if\n");
                }
                //printf("\nfora do if\n");

            }
              
        }
             
	}

    if(naoEncontrada==0)
    {
        printf("\n\tPalavra nao encontrada");
    }
}

void baixcim(char palavra[]);
void baixcim(char palavra[]){
    int naoEncontrada = 0;
    //printf("\n%s\n",palavra);
    tam = strlen(palavra);
    //printf("\ntamanho antes: %d\n",tam);
    for (int s = 0; s < max; s++)
    {  
        for (int t = max-1; t > -1; t--)
        {    
            //printf("linc %d coli %d\n", s,t);
            int cont = 0;
            //printf("\ntam dps: %d\n",tam);
            while(mat[t - cont][s] == palavra[cont] && cont != tam && (t - cont) != max)
            {
                //printf("\nletra: %c\n", mat[s][t]);
                //printf("\nDentro while\n");
                cont++;
                //printf("\ntamanho: %d\n",tam);
                if(cont == tam)
                {
                    printf("\n\n\tPalavra '%s' ENCONTRADA!!!\n\tBaix --> Cim: lin: %d col: %d\n", palavra, t,s);
                    naoEncontrada++;
                    //printf("\ndentro if\n");
                }
                //printf("\nfora do if\n");

            }
              
        }
             
	}

    if(naoEncontrada==0)
    {
        printf("\n\tPalavra nao encontrada");
    }
}

int main(){

menuPrincipal();

return 0;
}
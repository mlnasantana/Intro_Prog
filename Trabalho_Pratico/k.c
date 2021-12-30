//Milena Santana de Almeida, 21.1.4175

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int max=10;
char mat[10][10];
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

int main(){




return 0;
}
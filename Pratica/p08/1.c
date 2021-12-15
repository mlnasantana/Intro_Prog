//Milena Santana, 21.1.4175, turma 41

#include <stdio.h>


void VerificaEntrada(int m, int p, int q, int n, double matriz1[][10], double matriz2[][10], double matriz3[][10] ) {
  double soma;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < p; j++)
        {
          printf("Digite um valo:\n");
          scanf("%lf", &matriz1[i][j]);
        }
  }

  for (int i = 0; i < q; i++) {
    for (int j = 0; j < n; j++) 
        {
          printf("Digite um valor:\n");
          scanf("%lf", &matriz2[i][j]);
    }
  }


 if (p == q) {
   for (int i = 0; i < m; i++) {
     for(int j = 0; j < n; j++){
			 for (int k = 0; k < q; k++)
      {
       soma = soma + matriz1[i][k] * matriz2[k][j];
     }
     matriz3[i][j] = soma;
     soma = 0;
   }
 }
 }

 for (int i =0; i < m; i++){
   for(int j = 0;j < n; j++)
   printf("%.2lf", matriz3[i][j]);
   printf("\n");
 }
}
int main()
{
  int m, p, q, n;
  printf("Digite o numero de linhas e colunas da primeira matriz:\n");
  scanf("%d %d", &m, &p);
  printf("Digite o numero de linhas e colunas da segunda matriz:\n");
 scanf("%d %d", &q, &n);

 while(m > 10 || p >10 || q > 10 || n > 10 || p != q) {
 printf("Digite o numero de linhas e colunas da primeira matriz:\n");
  scanf("%d %d", &m, &p);
  printf("Digite o numero de linhas e colunas da segunda matriz:\n");
 scanf("%d %d", &q, &n);
 }
double matriz1[10][10];
double matriz2[10][10];
double matriz3[10][10];
VerificaEntrada(m, p, q, n, matriz1, matriz2, matriz3);
return 0;
}

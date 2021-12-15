//Milena Santana de Almeida, 21.1.4175, T41

#include <stdio.h>

int par(int x, int y)
{
    if(x % 2 == 0 && y % 2 == 0) 
        return 1;
    else
       return 0;
}

int maiornumero(int x, int y) 
{
    if(x < y) 
        return 1;
   else 
        return 0;
}

int main()
{
     int x, y, pares, maior, linha, coluna;
     do{
              printf("Caro usuario, digite os valores de x e y. \n");
              printf("Lembre que os numeros devem ser par e y deve ser maior que x: \n");
              scanf("%d" "%d", &x, &y); 
              pares = par(x, y);
              maior = maiornumero(x, y);
              if (pares == 1 && maior != 1)
                    printf("Voce digitou dois numeros pares sendo y maior que x: \n");
             else 
                    printf("Apenas numeros pares sao aceitos sendo y maior que x: \n");
 }
 while (pares != 1 || maior != 1);
 while (x <= y) { 
    coluna = (y-x) / 2;
    while(coluna > 0) 
    {
      printf(" "); 
      coluna --;
    }
    linha = 0;
    while(linha < x)
    {
      printf("*");
      linha ++;
    }
      printf("\n");
      x = x +2;
 }
}
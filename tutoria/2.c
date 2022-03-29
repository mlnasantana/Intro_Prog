//Milena Santana de Almeida, 21.1.4175, turma 33

//bibliotecas 

#include <stdio.h>
#include <stdlib.h>

int main ()
{

//variaveis
   double salario_fixo, vendas_efetuadas; 
   float comissao, total; 
   
   printf("Salario fixo do vendedor:\n");
   scanf("%lf", &salario_fixo); 
   
   printf("Vendas efetuadas em R$:\n");
   scanf("%lf", &vendas_efetuadas); 
   
   comissao = vendas_efetuadas * 0.15; // Calcula a procentagem da comissao
   
   total = comissao + salario_fixo; // calcula o salario total
   
   printf("\ntotal = %.2lf\n", total); 
      
  }
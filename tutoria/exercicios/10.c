/* implemente seis funções em C para, dados dois numeros reais, calcular:

a) a soma dos numeros;
b)o produto do primeiro pelo quadrado do segundo;
c)o quadrado do primeiro numero;
d) a raiz quadrada da soma dos quadrados;
e) o seno da diferenca do primeiro pelo segundo;
f)o modulo do primeiro;

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//funcoes
double soma_numeros();
double produto_primeiro();
double quadrado_primeiro();
double raiz_quadrada_soma();
double seno_diferenca();
double modulo_primeiro();

//variaveis globais
int n1,n2;

int main(){
    printf("Informe dois numeros:");
    scanf("%d %d", &n1, &n2);

    void soma_numeros()
    void produto_primeiro()
    void quadrado_primeiro()
    void raiz_quadrada_soma()
    void seno_diferenca()
    void modulo_primeiro()

 return 0;   
}


void soma_numeros(n1, n2){
    int soma = n1 + n2;
    printf("A soma dos dois numeros e:", soma);
}

void produto_primeiro(n1, n2){
   int q1 = n2 * n2;
   int resultado = n1 / q1;

    printf("O produto do primeiro numero pelo quadrado do segundo e :", resultado);
}

void quadrado_primeiro(n1, n2){
    int resultado = n1 * n1;

    printf("O quadrado do primeiro numero e:", resultado);
}

void raiz_quadrada_soma(n1, n2){
    int q1 = n1 * n1;
    int q2 = n2 * n2;
    int soma = q1 + q2;
    int raiz = sqrt(soma);

    printf("A raiz quadrada da soma dos quadrados e :", soma);
}

void seno_diferenca(n1, n2){
    int diferenca = n1 - n2;
    int resultado = sin(diferenca);

    printf("O seno da diferenca do primeiro numero pelo segundo e:", resultado);  
}

void modulo_primeiro(n1){
    if(n1 > 0){
        printf("O modulo do primeiro numero e:", n1);
    }
}




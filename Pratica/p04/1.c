//Milena Santana de Almeida, 21.1.4175, T41

#include <stdio.h>
#include <math.h> 

long long fat(int n);

long long fat(int n) {
        long long  fatorial;
        fatorial = n;
        while (fatorial > 1) {
                n *= (fatorial - 1.0);
                fatorial --;
        }
        return n;
}
int main() {
    long long fatorial; 
    int n = 1;

    printf("Informe um valor para saber seu fatorial:\n");
    scanf("%d", &n); 

    fatorial = fat(n);

    printf("%d! = %lld", n, fatorial);
    return 0; 
}
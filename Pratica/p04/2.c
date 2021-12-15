//Milena Santana de Almeida, 21.1.4175, T41

#include <stdio.h>

int is_prime (int n);

int is_prime(int n){
    int result, cont = 2;
    do{
        result = n % cont;
        if(result == 0){
            return 0;
        }else{
            return 1;
        }
        cont++;
        if(cont > 10 && result != 0){
            return 1;
        }
    }while(cont < n);
}

int main(){
    int n, result;
    printf("Informe um numero\n");
    scanf("%d", &n);
    result = is_prime(n);
    if(result == 1){
        printf("%d eh um numero primo.", n);
    }else{
        printf("%d nao eh um numero primo.", n);
    }
    return 0;
}

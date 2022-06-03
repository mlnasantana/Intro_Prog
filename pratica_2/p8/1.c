//Milena Santana de Almeida, 21.1.4175

//Bibliotecas
#include <stdio.h>

//Structs
struct Racional {
    int numerador;
    int denominador;
};

//Prototipo de funções
struct Racional mdc(struct Racional x);
int equal(struct Racional r1, struct Racional r2);


//Funções
struct Racional mdc(struct Racional x){
    for(int i = 2; (i < x.numerador) && (i < x.denominador) ; i++){
        while ((x.denominador % i == 0) && (x.numerador % i == 0)){
            x.denominador /= i; x.numerador /= i;
        }
    }
    return x;
}

int equal(struct Racional r1, struct Racional r2){
    r1 = mdc(r1); r2 = mdc(r2);
    if((r1.denominador == r2.denominador) && (r1.numerador == r2.numerador)){ return 1; }
    else{ return 0; }
}



int main(){
    //variaveirs
    struct Racional r1,r2;
    printf("r1 - numerador: "); scanf("%d", &r1.numerador);
    printf("r1 - denominador: "); scanf("%d", &r1.denominador);
    printf("r2 - numerador: "); scanf("%d", &r2.numerador);
    printf("r2 - denominador: "); scanf("%d", &r2.denominador);

    switch (equal(r1, r2)){
    case 1:
        printf("1: São iguais\n");
        break;
    
    default:
        printf("0: São diferentes\n");
        break;
    }

    return 0;
}
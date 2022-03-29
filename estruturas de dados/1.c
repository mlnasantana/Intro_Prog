//Milena Santana de Almeida, 21.1.4175

//Bibliotecas
#include <stdio.h>

//Funções
double soma(double M[][12]);
double media(double M[][12]);

double soma(double M[][12]){
    double s = 0.0;
    
    for(int i = 1, k = 0; i < 6; i++, k++){
        for(int j = i; j < (12 - i); j++){
            s += M[k][j];
        }
    }
    
    return s;
}

double media(double M[][12]){
    double m = 0.0;
    int p = 0;

    for(int i = 1, k = 0; i < 6; i++, k++){
        for(int j = i; j < (12 - i); j++){
            m += M[k][j];
            p++;
        }
    }

    return m/p;
}

int main(){
    double M[12][12];
    char T;
    
    //Ler o tipo de operação
    scanf("%c", &T);

    //Completar matriz
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf", &M[i][j]);
        }
    }
    
    //Verifica o tipo de operação
    if(T == 'S'){
        printf("%.1lf\n", soma(M));
    }
    else{
        printf("%.1lf\n", media(M));
    }

    return 0;
}
//Milena Santana de Almeida, 21.1.4175


//Biblioteca
#include <stdio.h>

//Structs
typedef struct {
    double real;
    double imaginario;
} Complexo;

//Prototipo das funções
Complexo somaComplexo(Complexo x, Complexo y);
Complexo subComplexo(Complexo x, Complexo y);
Complexo multComplexo(Complexo x, Complexo y);

//Funções
//Soma
Complexo somaComplexo(Complexo x, Complexo y){
    Complexo temp;
    temp.real = x.real + y.real;
    temp.imaginario = x.imaginario + y.imaginario;
    return temp;
}

//Subtração
Complexo subComplexo(Complexo x, Complexo y){
    Complexo temp;
    temp.real = x.real - y.real;
    temp.imaginario = x.imaginario - y.imaginario;
    return temp;
}

//Multiplicação
Complexo multComplexo(Complexo x, Complexo y){
    Complexo temp;
    temp.real = (x.real * y.real) - (x.imaginario * y.imaginario);
    temp.imaginario = (x.real * y.imaginario) + (x.imaginario * y.real);
    return temp;
}

int main(){
    //Variaveis
    Complexo x, y;
    char op;

    //Entradas
    printf("Digite os valores de a e b (x = a + bi): "); scanf("%lf %lf", &x.real, &x.imaginario);
    printf("Digite os valored de c e d (y = c + di): "); scanf("%lf %lf", &y.real, &y.imaginario);
    printf("Digite a operaçao (+, - ou *): "); getchar(); scanf("%c", &op);

    //Define a operação e da saida
    switch (op){
        case '+':
            printf("%.0lf + (%.0lfi)\n", somaComplexo(x, y).real, somaComplexo(x, y).imaginario);
            break;
        
        case '-':
            printf("%.0lf + (%.0lfi)\n", subComplexo(x, y).real, subComplexo(x, y).imaginario);
            break;
            
        case '*':
            printf("%.0lf + (%.0lfi)\n", multComplexo(x, y).real, multComplexo(x, y).imaginario);
            break;
    }

    return 0;
}
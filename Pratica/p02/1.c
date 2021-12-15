//Milena Santana, 21.1.4175, BCC201 - Turma 41

#include <stdio.h>

void inicio();
void angulo();
void temp();
double graus(double);
double rad(double);
double celsius(double, int);
double fahrenheit(double, int);
double kelvin(double, int);

void inicio(){
    //Recebendo a opcao de escolha do usuario
    int opcao;
    printf("### CONVERSOR DE UNIDADES ###\n\n1) Angulo\n2) Temperatura\n\nDigite uma opcao:");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            angulo();
            break;
        case 2:
            temp();
            break;
        default:
            printf("A opcao digitada nao existe!");
            break;
    }
}
void angulo(){
    int opcao;
    printf("\nQual a unidade de origem?\n\n1) Graus\n2) Radianos\n\nSelecione um opcao:");
    scanf("%d", &opcao);
    double valor = 0, resultado = 0;
    switch(opcao){
        case 1:
            printf("\nDigite um valor em Graus: ");
            scanf("%lf", &valor);
            resultado = graus(valor);
            printf("Valor em Radianos: %.6lf", resultado);
            break;
        case 2:
            printf("\nDigite um valor em Radianos: ");
            scanf("%lf", &valor);
            resultado = rad(valor);
            printf("Valor em Graus: %.6lf", resultado);
            break;
        default:
            printf("\nA opcao digitada nao existe!");
            break;

    }

}
double graus(double valor){
    return valor * (3.14159 / 180);
}

double rad(double valor){
    return valor * (180 / 3.14159);
}

void temp(){
    int opcao;
    printf("\nQual a unidade de origem?\n\n1) Celsius\n2) Fahrenheit\n3) Kelvin\n\nSelecione um opcao:");
    scanf("%d", &opcao);

    double valor = 0, f = 0, c = 0, k = 0;
    switch(opcao){
        case 1:
            printf("\nDigite um valor em Celsius: ");
            scanf("%lf", &valor);

            f = fahrenheit(valor, opcao);
            printf("\nValor em Fahrenheit: %.2lf", f);

            k = kelvin(valor, opcao);
            printf("\nValor em Kelvin: %.2lf", k);
            break;

        case 2:
            printf("\nDigite um valor em Fahrenheit: ");
            scanf("%lf", &valor);

            c = celsius(valor, opcao);
            printf("\nValor em Celsius: %.2lf", c);

            k = kelvin(valor, opcao);
            printf("\nValor em Kelvin: %.2lf", k);
            break;

        case 3:
            printf("\nDigite um valor em Kelvin: ");
            scanf("%lf", &valor);
            c = celsius(valor, opcao);
            printf("\nValor em Celsius: %.2lf", c);

            f = fahrenheit(valor, opcao);
            printf("\nValor em Fahrenheit: %.2lf", f);
            break;
        default:
            printf("\nA opcao digitada nao existe!");
            break;

    }

}

double celsius(double valor, int opcao){
    switch(opcao){
        case 2:
            return (valor - 32) * 5/9;
            break;

        case 3:
            return  valor - 273.15;
            break;
        default:
            break;
    }
    return 0;
}

double fahrenheit(double valor, int opcao){
    switch(opcao){
        case 1:
            return (valor * 9/5) + 32;
            break;

        case 3:
            return  (valor - 273.15) * 9/5 + 32;
            break;
        default:
            break;
    }
    return 0;
}

double kelvin(double valor, int opcao){
    switch(opcao){
        case 1:
            return valor + 273.15;
            break;
        case 2:
            return  (valor - 32) * 5/9 + 273.15;
            break;
        default:
            break;
    }
    return 0;
}
int main() {
    inicio();
    return 0;
}
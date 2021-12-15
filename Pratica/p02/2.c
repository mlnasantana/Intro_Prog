//Milena Santana, 21.1.4175, BCC201 - Turma 41
#include <stdio.h>
#include <math.h>

double distancia(double x1, double y1, double x2, double y2);
double distancia(double x1, double y1, double x2, double y2){
    return sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) ); 
}

int main(){
    double x1, y1, x2, y2;

    printf("Informe as coordenadas dos dois pontos:\n\n");
    printf("Cordenada x do ponto 1: "); scanf("%lf", &x1);
    printf("Cordenada x do ponto 2: "); scanf("%lf", &x2);
    printf("Cordenada y do ponto 1: "); scanf("%lf", &y1);
    printf("Cordenada y do ponto 2: "); scanf("%lf", &y2);

    printf("A distancia entre os dois pontos eh %lf\n", distancia(x1, y1, x2, y2));
    return 0;
}
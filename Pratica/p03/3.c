//Milena Santana 21.1.4175 BCC201 T41

#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int duracao(int *horainIcio, int *minInicio, int *horaTermino, int *minTermino);

int main() {
    int horaInicio, minInicio, horaTermino, minTermino, resultado;
    printf("Qual a hora e o minuto de inicio e final?\n");
    scanf("%d %d %d %d", &horaInicio, &minInicio, &horaTermino, &minTermino);
    printf("O tempo total de jogo e %d em minutos", resultado);
    return 0;
}

int duracao(int *horaInicio, int *minInicio, int *horaTermino, int *minTermino) {
      int horaTotalInicial = (*horaInicio * 60) + *minInicio;
      int horaTotalFinal = (*horaTermino * 60) + *minTermino;
      if (horaTotalInicial >= horaTotalFinal) {
      int tempoTotal = 1440 + horaTotalFinal - horaTotalInicial;
      return tempoTotal;
}
      else {
            int tempoTotal = horaTotalFinal - horaTotalInicial;
            return tempoTotal;
}
}
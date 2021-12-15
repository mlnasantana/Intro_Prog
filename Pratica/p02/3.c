//Milena Santana, 21.1.4175, BCC201 - Turma 41

#include <stdio.h>
#include <stdlib.h>

char letra = 'a';
int vogal();

int vogal(){
    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
        letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        return 1;
}

void main(){
    printf("O valor armazenado na variavel global eh: %c\n", letra);

    if(vogal() == 1)
        printf("A variavel global eh uma vogal.");
    else
        printf("A variavel global eh uma consoante.");
}
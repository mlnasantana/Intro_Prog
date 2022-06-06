/*crie um programa  que le um caracter e determine se o dado lido é
uma letra minuscula (a-z), maiuscula(A-Z), ou nao
(!,@,#,$,%,1,2,3,etc).
*/

#include<stdio.h>

int main(){
    char frase[50];
    int i;

    printf("digite seu texto:\n");
    fgets(frase, 49, stdin);

        for (i = 0; frase[i] != '\0'; i++){
            if(frase[i] >= 97 && frase[i] <= 122){
                frase[i] -= 32;
            }
        }
    printf("\n novo texto: %s\n", frase);

    return 0;
}


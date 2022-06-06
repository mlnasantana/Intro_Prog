/*desenvolva uma função que recebe o peso (kg) e a altura (m)
de uma pessoa e imprima o seu indice de Massa corporal(IMC);

IMC = peso / altura ^2

*/

#include<stdio.h>
#include<math.h>

int main(){
    float peso, altura;
    int IMC;

    printf("Caro usuaria, informe seu peso:");
    scanf("%f", &peso);
    printf("Informe sua altura:");
    scanf("%f", &altura);

    IMC =  peso / altura * altura;

    if(IMC < 16 ){
        printf("seu indice de massa corporal e baixo peso severo");
    }
        if(IMC < 16 && IMC > 16,9){
            printf("seu indice de massa corporal e baixo peso moderado");
        }
            if(IMC < 17 && IMC > 18,49){
                printf("seu indice de massa corporal e baixo peso leve");
            }   
                if(IMC < 18,5 && IMC > 24,9){
                    printf("seu indice de massa corporal e peso ideal");
                }
                    if(IMC => 25){
                    printf("seu indice de massa corporal e sobrepeso");
                }
                        if(IMC > 25 && < 29,9){
                        printf("seu indice de massa corporal e pre-obesidade");
                        }
                            if(IMC > 30 && IMC < 34,9){
                                printf("seu indice de massa corporal e obesidade moderada:");
                            }
                                if(IMC > 35 && IMC < 39,9){
                                    printf("seu indice de massa corporal e obesidade alta");
                                }
                                    if(IMC => 40){
                                        printf("seu indice de massa corporal e obesidade muito alta");
                                    }
 }

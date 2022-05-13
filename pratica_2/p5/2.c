<<<<<<< HEAD
//Milena Santana, 21.1.4175, T33

#include <stdio.h>
#include <math.h>

int validaCpf(long long int cpf);

int validaCpf(long long int cpf){
    int digito; 
    int multiplicador = 10;
    int verificador = 0;
    long long int cont = 100000000;

    long long int primeiros = cpf/100;

    int primeiroV = cpf/10 - (primeiros * 10); 
    int segundoV = cpf - (primeiros * 100) - primeiroV * 10; 

    while(cont > 0 && multiplicador >= 2){ 
        digito = primeiros/cont;
        primeiros -= digito*cont;
        cont /= 10;

        verificador += digito * multiplicador; 
        multiplicador--; 
    }
    verificador = (verificador * 10) % 11;

    if(verificador == primeiroV){
        multiplicador = 11; 
        cont = 10000000000;
        verificador = 0;

        while(multiplicador >= 2){
            digito = cpf/cont; 
            cpf -= digito*cont; 
            cont /= 10; 
            verificador += digito * multiplicador;
            multiplicador--;
        }
        verificador = (verificador * 10) % 11; 
        if(verificador == segundoV){
            return 1; 
        }
    }
    return 0;
}


int main(){
    long long int cpf;
    printf("Digite o seu cpf: ");
    scanf("%lld", &cpf);
    if(validaCpf(cpf) == 1)
        printf("Seu CPF %lld se encontra validado.", cpf);
    else
        printf("O CPF %lld se encontra invalido.", cpf);
    return 0;
=======
//Milena Santana, 21.1.4175, T33

#include <stdio.h>
#include <math.h>

int validaCpf(long long int cpf);

int validaCpf(long long int cpf){
    int digito; 
    int multiplicador = 10;
    int verificador = 0;
    long long int cont = 100000000;

    long long int primeiros = cpf/100;

    int primeiroV = cpf/10 - (primeiros * 10); 
    int segundoV = cpf - (primeiros * 100) - primeiroV * 10; 

    while(cont > 0 && multiplicador >= 2){ 
        digito = primeiros/cont;
        primeiros -= digito*cont;
        cont /= 10;

        verificador += digito * multiplicador; 
        multiplicador--; 
    }
    verificador = (verificador * 10) % 11;

    if(verificador == primeiroV){
        multiplicador = 11; 
        cont = 10000000000;
        verificador = 0;

        while(multiplicador >= 2){
            digito = cpf/cont; 
            cpf -= digito*cont; 
            cont /= 10; 
            verificador += digito * multiplicador;
            multiplicador--;
        }
        verificador = (verificador * 10) % 11; 
        if(verificador == segundoV){
            return 1; 
        }
    }
    return 0;
}


int main(){
    long long int cpf;
    printf("Digite o seu cpf: ");
    scanf("%lld", &cpf);
    if(validaCpf(cpf) == 1)
        printf("Seu CPF %lld se encontra validado.", cpf);
    else
        printf("O CPF %lld se encontra invalido.", cpf);
    return 0;
>>>>>>> a4b31fe438e3c04283dc40fd6cec71e3c0689bf0
}
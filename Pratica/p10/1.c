//Milena Santana, 21.1.4175, BCC201 Turma 41

#include <stdio.h>

typedef struct
{
    int numerador;
    int denominador;
} Racional;

void leitorR(Racional r, int n)
{
    printf("Digite o numerador e denominador de r%d: ", n);
    scanf("%d %d", r->numerador, r->denominador);
}
int divisor(Racional *r)
{
    int t;
    while (r.numerador > 0)
    {
        if (r.numerador < r.denominador)
        {
            t = r.numerador;
            r.numerador = r.denominador;
            r.denominador = t;
        }

        r.numerador -= r.denominador;
    }

    return r.denominador;
}

void reduz(Racional *r)
{

    r->numerador = r->numerador / (float)divisor(*r);
    r->denominador = r->denominador / (float)divisor(*r);
}

int equal(Racional r1, Racional r2)
{
    if (r1.numerador == r2.numerador && r1.denominador == r2.denominador)
        return 1;
    else
        return 0;
}

int main()
{

    struct Racional r1, r2;
    leitorR(&r1, 1);
    leitorR(&r2, 2);

    reduz(&r1);
    reduz(&r2);

    if(equal(r1, r2) == 1)
        printf("\nr1 e r2 sao iguais!");
    else
        printf("\nr1 e r2 sao diferentes!");
    
    return 0;
}
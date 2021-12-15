//Milena Santana, 21.1.4175, BCC201 Turma 41

#include<stdio.h>
#include<math.h>

typedef struct {
double real;
double imaginario;
 } Complexo;

// funcao que retorna x + y
 Complexo somaComplexo(Complexo x, Complexo y){
    double real = (x.real + y.real) ;
    double imaginario = ((x.imaginario) + (y.imaginario));
    Complexo p = {real,imaginario};
    return p ; 

 }

// funcao que retorna x - y
 Complexo subComplexo(Complexo x, Complexo y){
    double real = x.real - y.real ;
    double imaginario = (x.imaginario) - (y.imaginario);
    Complexo p = {real,imaginario};
    return p ; 
 }
  

// funcao que retorna x * y
 Complexo multComplexo(Complexo x, Complexo y){
    double real  =(x.real * y.real)  + (x.imaginario*y.imaginario * -1);
    double imaginario = (x.real * y.imaginario) + (x.imaginario*y.real);
    Complexo p = {real,imaginario};
    return p;
 }

 int main (){
     Complexo x,y,z;
     char tipo;
     printf("Calculadora de numeros complexos!\n");
     printf("\nDigite os valores de a e b (x = a + bi):");
     scanf("%lf %lf",&x.real,&x.imaginario);
     printf("\nDigite os valores de c e d (y = c + di):");
     scanf("%lf %lf",&y.real,&y.imaginario);
     gets(stdin);

     printf("\nDigite a operacao (+, - ou *):\n");
     scanf("%c",&tipo);
     switch (tipo)
     {
        case  '+' :
             z = somaComplexo(x,y);
            printf("Resultado : %.0lf + %2.lf i ", z.real, z.imaginario);
        break;
        case '-':
            z =subComplexo(x,y);
            printf("Resultado : %.0lf + %2.lf i", z.real, z.imaginario);
        break;
        case '*':
             z =multComplexo(x,y);
            printf("Resultado : %.0lf + %2.lf i", z.real, z.imaginario);
        break;
     default:
         break;
     }

    return 0;
 }
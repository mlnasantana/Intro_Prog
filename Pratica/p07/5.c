//Milena Santana, 21.1.4175

#include <stdio.h>

//Tamanho do vetor
#define t_aluno 15
#define n_prova 2

int main(){
    //Variaveis
    int alunos[t_aluno];
    double provas[t_aluno * n_prova];

    //Indentificção aluno
    for(int i = 0; i < t_aluno; i++){alunos[i] = i + 1;}

    //entrada das provas
    for(int i = 0, j = 0 ; i < t_aluno; i++, j+= 2){
        printf("Qual a nota das provas do aluno %d: ", alunos[i]); scanf("%lf %lf", &provas[j], &provas[j + 1]);
    }

    //Calcular media e imprimir situação do aluno
    for(int i = 0, j = 0 ; i < t_aluno; i++, j+= 2){
        if((provas[j] + provas[j + 1])/n_prova >= 60){
            printf("O aluno %d foi aprovado\n", alunos[i]);
        }
        else{
            printf("O aluno %d foi reprovado\n", alunos[i]);
        }
    }
    
    return 0;
}
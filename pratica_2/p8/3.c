//Milena Santana de Almeida, 21.1.4175


//Bibliotecas
#include <stdio.h>
#include <string.h>


#define t_nam 100 //tamnho maximo dos nomes
#define t_aln 100 //quantidade maxima de alunos
#define t_txt 100 //tamnho maximo do caminho do arquivo

//Structs
typedef struct{
    char nam[t_nam];
    float nota;
    float freq; 
} Aluno;


Aluno addAluno();
void print_txt(char file[], Aluno temp[],  int n);

//Funcoes
Aluno addAluno(){

    Aluno temp;

    printf("Nome: "); getchar(); fgets(temp.nam, t_nam, stdin);
    temp.nam[strlen(temp.nam) - 1] = '\0';

    //Nota do aluno
    printf("Nota: "); scanf("%f", &temp.nota);

    //Frequencia do aluno
    printf("Frequencia(Porcentagem): "); scanf("%f", &temp.freq);

    return temp;
}

void print_txt(char file[], Aluno temp[],  int n){
    FILE *input = fopen(file, "w");

    fprintf(input, "%d\n", n);

    for(int i = 0; i < n; i++){
         fprintf(input, "%s\n%f %f\n", temp[i].nam, temp[i].nota, temp[i].freq);
    }

    fclose(input);
}

int main(){
    
    Aluno aluno[t_aln];
    char file[t_txt];
    int n;

    //Entradas
    printf("Quantos alunos serão cadastrados: "); scanf("%d", &n);
    
    //Entradas da struct
    for(int i = 0; i < n; i++){
        printf("Aluno %d\n", i + 1); aluno[i] = addAluno();
    }

    //Entrada do nome do arquivo
    printf("Digite o nome do arquivo que os dados serão salvos: "); getchar(); fgets(file, t_txt, stdin);
    file[strlen(file) - 1] = '\0';

    //Saida
    print_txt(file, aluno, n);

    return 0;
}
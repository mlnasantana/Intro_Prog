//Milena Santana de Almeida, 21.1.4175

#include <stdio.h>
#include <string.h>


#define t_nam 100 //tamnho maximo dos nomes
#define t_aln 100 //quantidade maxima de alunos
#define t_txt 100 //tamnho maximo do caminho do arquivo
#define nota_apro 6.0 //nota minima de aprovaçãp
#define freq_apro 60.0 //frequencia minima de aprovação


//Structs
typedef struct{
    char nam[t_nam];
    float nota;
    float freq; 
} Aluno;

//Prototipo das funções
double media_nota(Aluno temp[], int n);
double media_freq(Aluno temp[], int n);
double aprov(Aluno temp[], int n);

//Funções
double media_nota(Aluno temp[], int n){
    double media = 0;
    
    for(int i = 0; i < n; i++){
        media += temp[i].nota;
    }

    return media/n;
}

double media_freq(Aluno temp[], int n){
    double media = 0;
    
    for(int i = 0; i < n; i++){
        media += temp[i].freq;
    }

    return media/n;
}

double aprov(Aluno temp[], int n){
    double aprov = 0;

    for(int i = 0; i < n; i++){
        if((temp[i].nota >= nota_apro) && (temp[i].freq >= freq_apro)){
            aprov++;
        }
    }

    return (aprov/n) * 100; //Retorna em porcentagem
}



int main(){
    //Variaveis
    char file[t_txt];
    Aluno aluno[t_aln];
    int n;
    double med_nota, med_freq, apv;

    //Nome do arquivo de entrada
    printf("Digite o nome do arquivo: ");
    fgets(file, t_nam, stdin); file[strlen(file) - 1] = '\0';

    //Leitura do arquivo
    FILE *input = fopen(file, "r");

    //pega as dimensões das matrizes
    fscanf(input, "%d", &n);

    for(int i = 0; i < n; i++){
        //Pega o nome
        fgetc(input); fgets(aluno[i].nam, t_nam, input); aluno[i].nam[strlen(aluno[i].nam) - 1] = '\0';

        //Pega a nota e a frequencia
        fscanf(input, "%f %f", &aluno[i].nota, &aluno[i].freq);
    }

    fclose(input);

    //Processamento
    med_nota = media_nota(aluno, n);
    med_freq = media_freq(aluno, n);
    apv = aprov(aluno, n);

    //Saidas
    printf("Nota média: %.2lf\n", med_nota);
    printf("Frequencia média(porcentagem): %.2lf\n", med_freq);
    printf("Porcentagem de aprovação(porcentagem): %.2lf\n", apv);


    printf("\nNomes dos alunos com nota acima da nota média:\n");
    for(int i = 0; i < n; i++){
        if(aluno[i].nota > med_nota){
            printf("%s\n", aluno[i].nam);
        }
    }

    return 0;
}
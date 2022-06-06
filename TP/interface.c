

//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Arquivos cabeçalho
#include "layouts.h"
#include "jogo.h"

void read(char arquivo[100]){ //Função le um arquivo txt e imprime
    FILE *txt = fopen(arquivo, "r"); //Abrindo arquivo a ser lido
    char temp[1000]; //string temporaria
    char resp[3];

    while (1){
        fgets(temp, 1000, txt); //Le todas as linhas do arquivo
        if(strcmp(temp, "#end") == 0){break;} //caso o arquivo tenha terminado
        printf("%s", temp); //E imprime da msm forma que está lá
    }

    printf("Digite \"OK\" para continuar: "); scanf("%s", resp); //Confirmação de leitura
    while ((strcmp(resp, "ok") != 0) &&  (strcmp(resp, "OK") != 0)){ //Caso for uma entrada invalida
       printf("ERRO entrada invalida\nDigite \"OK\" para continuar: "); scanf("%s", resp);
    }
    
    fclose(txt); //Fecha o arquivo
}

int verifica_arqnovo(FILE *txt){ //Função que verifica se o arquivo segue as condições de bom funcionamento
    int m, n, qnt_wrds;
    fscanf(txt, "%d %d\n%d", &m, &n, &qnt_wrds); //Pega as dimesões e o numero de palvras

    if((m > 26) || (n > 26)){ //Caso as dimensões do caça palavras utrapassem 26
        printf("\nERRO Alguma das dimensões do caça palavras utrapassa 26\n\n");
        return 1;
    } 
    
    if((qnt_wrds > m) || (qnt_wrds > n)){ //Caso a quantidade de palvras ultrapasse alguma dimensão
        printf("\nERRO A quantidade de palvras ultrapassa alguma das dimenções\n\n");
        return 1;
    } 
    
    char palavra[qnt_wrds][27];
    int tamanho;

    for(int i = 0; i < qnt_wrds; i++){
        fscanf(txt, "%s", palavra[i]); //Pega palavra por palavra
        tamanho = strlen(palavra[i]); //Pega o tamanho da palavra

        if((tamanho > m) || (tamanho > n)){ //Caso alguma palavra for maior que alguma dimensão
            printf("\nERRO Há uma palavra que é maior que alguma das dimenções\n\n");
            return 1;
        } 
        
        for(int j = 0; j < tamanho; j++){
            if(((palavra[i][j] < 'A') || (palavra[i][j] > 'Z')) &&
               ((palavra[i][j] < 'a') || (palavra[i][j] > 'z'))){
                printf("\nERRO Em alguma palavra há um caracter que não é letra\n");
                printf("Ou o numero de quantidade de palvras é maior que a quantidade de palavras presentes\n\n");
                return 1;
            } //Caso haja algum caracter que não seja uma letra na palvra 
            //ou a quantidades de palvras é maior que a quantidade de palavras presentes
        }
    }

    return 0; //Nenhum erro encontrado
}

int verifica_arqsalvo(FILE *txt){ //Função que verifica a estrutura do arquivo do jogo salvo
    int m, n;
    fscanf(txt, "%d %d\n", &m, &n); //Pega as dimesões e o numero de palvras

    if((m > 26) || (n > 26)){return 1;} //Caso as dimensões do caça palavras utrapassem 26

    char temp[n][m];
    for(int i = 0; i < m; i++){ //Colocando a matriz no arquivo
        for(int j = 0; j < n; j++){
            fscanf(txt, "%c ", &temp[i][j]); //Pega os caracteres do caça palavras
            if((temp[i][j] < 'A') || (temp[i][j] > 'Z')){return 1;} //Caso um dos carcter do caça palavras não seja uma letra maiuscula
        }
    }
    
    int qnt_wrds;

    fscanf(txt, "%d", &qnt_wrds); //Pega a quantidade de palvras

    if((qnt_wrds > m) || (qnt_wrds > n)){return 1;} //Caso a quantidade de palvras ultrapasse alguma dimensão
    
    char palavra[qnt_wrds][27];
    char localiza[qnt_wrds][4];
    int tamanho;

    for(int i = 0; i < qnt_wrds; i++){
        //Pega as palavras e coordenadas
        fscanf(txt, "%s %c%c %c%c", palavra[i], &localiza[i][0], &localiza[i][1], &localiza[i][2], &localiza[i][3]);
        tamanho = strlen(palavra[i]);

        if((tamanho > m) || (tamanho > n)){return 1;} //Caso alguma palavra for maior que alguma dimensão
        
        for(int j = 0; j < tamanho; j++){
            if(((palavra[i][j] < 'A') || (palavra[i][j] > 'Z')) &&
               ((palavra[i][j] < 'a') || (palavra[i][j] > 'z'))){return 1;}
            //Caso haja algum caracter que não seja uma letra na palvra 
            //ou a quantidades de palvras é maior que a quantidade de palavras presentes
        }
        
        if((localiza[i][0] >= 'A') && (localiza[i][0] <= 'Z')){ //Se a primeira coordenada for uma letra maiuscula
            for(int j = 1; j < 4; j++){
                //Se tiver algum caracter que não seja letra maiusula nas outras coordenadas
                if((localiza[i][j] < 'A') || (localiza[i][j] > 'Z')){return 1;}
            }
        }

        else if(localiza[i][0] == '-'){ //Se a primeira coordenada for '-'
            for(int j = 1; j < 4; j++){
                //Se tiver algum caracter que não seja '-' nas outras coordenadas
                if(localiza[i][j] != '-'){return 1;}
            }
        }

        else{return 1;} //Se a primeira coordenada for um caracter invalido
    }

    return 0; //Nenhum erro encontrado
}

void nivel_newgame(char arquvivo[]){ //Função pega o nivel do jogo
    system(limpa); //Limpar tela
    char escolha[10];
    //Tela para definir a dificuldade
    printf("\n\nSelecione um nivel de difculdade\n\n");
    printf("1 - Facíl\n");
    printf("2 - Médio\n");
    printf("3 - Difícil\n\n");
    printf("Qualquer duvida vá à \"Instruções do jogo\" na tela inicial\n");
    printf("Para mudar a escolha de arquivo digite \"arquivo\"\n");
    printf("Digite \"sair\" para sair do jogo ou \"inicio\" para voltar a tela inicial\n\n");

    while(1){
        printf("Escolha uma opção: "); scanf("%s", escolha); //Entrada do jogador
        if(strcmp(escolha, "arquivo") == 0){arq_newgame(0); break;} //Caso o jogador queira mudar o arquivo
        else if(strcmp(escolha, "sair") == 0){printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "inicio") == 0){main_layout(); break;} //Caso o jogador queira voltar a tela inicial
        else if(strcmp(escolha, "1") == 0){ cria_jogo(arquvivo, 1); break;} //Caso o jogador queira jogar no modo Facil
        else if(strcmp(escolha, "2") == 0){ cria_jogo(arquvivo, 2); break;} //Caso o jogador queira jogar no modo Médio
        else if(strcmp(escolha, "3") == 0){ cria_jogo(arquvivo, 3); break;} //Caso o jogador queira jogar no modo Dificil
        else{printf("ERRO!!! Escolha uma opção valida\n"); continue;} //Caso o jogador digite uma opção invalida
    }
}

void arq_newgame(int i){ //Função pega o arquivo dicionario e verifica se ele exite e é valido
    system(limpa); //limpar tela

    if(i == 1){printf("A preparação do jogo atingiu o tempo limite de execução, tente novamente, ou use um outro arquivo");}

    int confim; //variavel que confirma se ta tudo certo
    char arquivo[100];
    
    //Tela de novo jogo
    printf("\n\nNOVO JOGO\n\n");
    printf("Digite \"sair\" para sair do jogo ou \"inicio\" para voltar a tela inicial\n");
    printf("Qualquer duvida vá à \"Instruções do jogo\" na tela inicial\n\n");
    printf("OBS: Há alguns arquvios dicionario pre-montados na pasta \"dicionarios/\"\n\n");

    while(1){
        printf("Qual o arquivo dicionario que deseja usar? "); scanf("%s", arquivo); //Entrada do arquivo dicionario
        if(strcmp(arquivo, "sair") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(arquivo, "inicio") == 0){ main_layout(); break;} //Caso o jogador queira voltar a tela inicial
        else {
            FILE *txt = fopen(arquivo, "r"); //Abre o arquivo
            if(txt){//Verifica se o arquivo existe
                confim = verifica_arqnovo(txt); //Testa para ver se a estrutura do arquivo está certa
                fclose(txt);//fecha o arquivo
                
                if(confim == 0){nivel_newgame(arquivo); break;} //Ta tudo certo
                
                //Possiveis erros
                else{continue;}
            }
            else{ //Caso o arquivo não existir
                printf("ERRO arquivo não encontrado\n");
                continue;
            }
        }
    }
}

void arq_continuegame(){ //Função que abre um arquvo de um jogo salvo
    system(limpa); //limpar tela

    int confim; //variavel que confirma se ta tudo certo
    char arquivo[100];

    //Tela de continuar jogo
    printf("\n\nCONTINUAR JOGO\n\n");
    printf("Digite \"sair\" para sair do jogo ou \"inicio\" para voltar a tela inicial\n");
    printf("Qualquer duvida vá à \"Instruções do jogo\" na tela inicial\n\n");

    while(1){
        printf("Qual o arquivo do jogo que quer coninuar? "); scanf("%s", arquivo); //Entrada do arquivo do jogo salvo
        if(strcmp(arquivo, "sair") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(arquivo, "inicio") == 0){ main_layout(); break;} //Caso o jogador queira voltar a tela inicial
        else {
            FILE *txt = fopen(arquivo, "r"); //Abre o arquivo
            if(txt){//Verifica se o arquivo existe
                confim = verifica_arqsalvo(txt); //Testa para ver se a estrutura do arquivo está certa
                fclose(txt);//fecha o arquivo
                
                if(confim == 0){carrega_jogo(arquivo); break;} //Ta tudo certo
                
                //Possiveis erros
                else{
                    printf("\nERRO a estrutura do arquivo foi adulterada, tente outro arquivo ou comece um novo jogo\n\n");
                    continue;
                }
            }
            else{ //Caso o arquivo não exista
                printf("ERRO arquivo não encontrado\n");
                continue;
            }
        }
    }
}

void instructions(){ //Função das instruções do jogo
    system(limpa); //limpar tela
    char escolha[5];
    //Tela de instruções
    printf("\n\nINSTRUÇÕES\n");
    printf("O que deseja fazer:\n\n");
    printf("1 - Sobre o jogo\n");
    printf("2 - Sobre os niveis\n");
    printf("3 - Sobre os arquivos dicionario\n");
    printf("4 - Como jogar\n\n");
    printf("Digite \"sair\" para sair do jogo ou \"inicio\" para voltar a tela inicial\n\n");

    while(1){
        printf("Escolha uma opção: "); scanf("%s", escolha); //Entrada do jogador
        if(strcmp(escolha, "sair") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "inicio") == 0){ main_layout(); break;} //Caso o jogador queira voltar a tela inicial
        else if(strcmp(escolha, "1") == 0){read("files/jogo.txt"); instructions();} //Caso o jogador queira saber sobre o jogo
        else if(strcmp(escolha, "2") == 0){read("files/niveis.txt"); instructions();} //Caso o jogador queira saber sobre os niveis do jogo
        else if(strcmp(escolha, "3") == 0){read("files/dicionarios.txt"); instructions();} //Caso o jogador queira saber sobre os arquivos dicionario
        else if(strcmp(escolha, "4") == 0){read("files/conojogar.txt"); instructions();} //Caso o jogador queira saber sobre as mecanicas de jogo
        else{printf("ERRO: Escolha uma opção valida\n"); continue;} //caso o jogador tenha colocado uma opção errada
    }
}

void main_layout(){ //Tela inicial do jogo
    system(limpa); //limpar tela
    char escolha[5];
    //Tela inicial
    printf("\n\nOla :) Bem vindo ao jogo de caça-palavras\n");
    printf("O que deseja fazer:\n\n");
    printf("1 - Começar um novo jogo\n");   
    printf("2 - Continuar um jogo anterior\n");
    printf("3 - Instruções do jogo\n\n");
    printf("Digite \"sair\" para sair do jogo\n\n");

    while(1){
        printf("Escolha uma opção: "); scanf("%s", escolha); //Entrada do jogador
        if(strcmp(escolha, "sair") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){arq_newgame(0); break;} //Caso o jogador queira começar um novo jogo
        else if(strcmp(escolha, "2") == 0){arq_continuegame(); break;} //Caso o jogador queira continuar um jogo
        else if(strcmp(escolha, "3") == 0){instructions(); break;} //Caso o jogador queira ler as instruções
        else{printf("ERRO: Escolha uma opção valida\n"); continue;} //Caso o jogador digite uma opção invalida
    }
}
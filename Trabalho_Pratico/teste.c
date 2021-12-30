/*  
Nome: Pedro Augusto Sousa Gonçalves;
Nº de matricula: 21.1.4015;
turma: 41;
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Arquivos cabeçalho
#include "jogo.h"
#include "cor.h"
#include "layouts.h"

jogo gera_matriz(jogo game, int nivel){
    srand(time(NULL)); //Semete para gerar numeros aleatorios

    for(int i = 0; i < game.m; i++){
        for(int j = 0; j < game.n; j++){
           game.matriz[i][j] = '-'; //Gera uma matriz de '-'
        }
    }

    int confirm = 0; //variavel que confirma se a função funcionol
    int sizestring; //Tamanho das palavras
    int position; //Posição da palavra
    char temp[50]; //string temporaria das palavras;

    for(int i = 0; i < game.wrds; i++){ //Define a posição e coordenadas de cada palavra
        sizestring = strlen(game.palavras[i]); //Tamanho da palavra
        
        while (confirm == 0){ //Se o comfirm for zero ao final, ira ser definido uma nova posição e coordenadas para a palvra
            position = 0;
            confirm = 1;//Se não for alterado, todas as condições estão corretas

            switch (nivel){ //Define a posição da palavra pelo nivel
                case 1: position = rand() % 2; break; //Se for 0 será na horizontal, se for 1 será na vertical
                case 2: position = rand() % 4; break; //Se for 2 será na diagonal de cima para baixo,se for 3 de baixo para cima
                case 3: position = rand() % 8; break; //Se 4 5 6 7 será 0 1 2 3 com palavras invertidas
            }

            if(position > 3){ //Se a palavra precisar ser invetida
                for(int j = 0; j < sizestring; j++){
                    temp[j] = game.palavras[i][sizestring - j - 1];
                }
                temp[sizestring + 1] = '\0'; 
            }

            else{ //Se a palavra não precisar ser invertida
                strcpy(temp, game.palavras[i]);
            }

            for(int j = 0; j < sizestring; j++){ //Deixa as letras maiusculas
                if((temp[j] <= 'z') && (temp[j] >= 'a')){temp[j] -= 32;}
            }

            switch(position){ //Define as corredenadas iniciais e finais
                case 0: case 4://Se a palavra ficar na horizontal
                    game.wrdsspot[i][0] = rand() % (game.m + 1); //Linha inicial da palavra
                    game.wrdsspot[i][1] = rand() % ((game.n - sizestring) + 1); //Coluna inicial da palavra
                    game.wrdsspot[i][2] = game.wrdsspot[i][0]; //Linha final da palavra
                    game.wrdsspot[i][3] = game.wrdsspot[i][1] + sizestring - 1; //Coluna final da palavra

                    for(int j = game.wrdsspot[i][1], k = 0; j <= game.wrdsspot[i][3]; j++, k++){ //Laço ira varrer a area que a palvra vai vicar em busca de algum impecilio
                        if((game.matriz[game.wrdsspot[i][0]][j] != '-') && //Se no locoal tiver uma letra
                        (game.matriz[game.wrdsspot[i][0]][j] != temp[k])){confirm = 0; break;} //Se a letra no local for diferente da letra correspontende na palavra o comfirm muda
                    }

                    if(confirm == 1){
                        for(int j = game.wrdsspot[i][1], k = 0; j <= game.wrdsspot[i][3]; j++, k++){ //Laço ira alocar a palvra na matiz
                            game.matriz[game.wrdsspot[i][0]][j] = temp[k];
                        }
                    }

                    break;

                case 1: case 5: //Se a palavra ficar na vertical
                    game.wrdsspot[i][0] = rand() % ((game.m - sizestring) + 1); //Linha inicial da palavra
                    game.wrdsspot[i][1] = rand() % (game.n + 1); //Coluna inicial da palavra
                    game.wrdsspot[i][2] = game.wrdsspot[i][0] + sizestring - 1; //Linha final da palavra
                    game.wrdsspot[i][3] = game.wrdsspot[i][1]; //Coluna final da palavra

                    for(int j = game.wrdsspot[i][0], k = 0; j <= game.wrdsspot[i][2]; j++, k++){ //Laço ira varrer a area que a palvra vai vicar em busca de impecilio             
                        if((game.matriz[j][game.wrdsspot[i][1]] != '-') && //Se no locoal tiver uma letra
                        (game.matriz[j][game.wrdsspot[i][1]] != temp[k])){confirm = 0; break;} //Se a letra no local for diferente da letra correspontende na palavra o comfirm muda
                    }

                    if(confirm == 1){
                        for(int j = game.wrdsspot[i][0], k = 0; j <= game.wrdsspot[i][2]; j++, k++){ //Laço ira alocar a palvra na matiz
                            game.matriz[j][game.wrdsspot[i][1]] = temp[k];
                        }
                    }

                    break;
                
                case 2: case 6://Se a palavra ficar na diagonal de cima para baixo
                    game.wrdsspot[i][0] = rand() % ((game.m - sizestring) + 1); //Linha inicial da palavra
                    game.wrdsspot[i][1] = rand() % ((game.n - sizestring) + 1); //Coluna inicial da palavra
                    game.wrdsspot[i][2] = game.wrdsspot[i][0] + sizestring - 1; //Linha final da palavra
                    game.wrdsspot[i][3] = game.wrdsspot[i][1] + sizestring - 1; //Coluna final da palavra

                    for(int j = game.wrdsspot[i][0], p =  game.wrdsspot[i][1], k = 0; j <= game.wrdsspot[i][2]; j++, p++, k++){ //Laço ira varrer a area que a palvra vai vicar em busca de impecilio
                        if((game.matriz[j][p] != '-') && //Se no locoal tiver uma letra
                        (game.matriz[j][p] != temp[k])){confirm = 0; break;} //Se a letra no local for diferente da letra correspontende na palavra o comfirm muda
                    }

                    if(confirm == 1){
                        for(int j = game.wrdsspot[i][0], p =  game.wrdsspot[i][1], k = 0; j <= game.wrdsspot[i][2]; j++, p++, k++){ //Laço ira alocar a palvra na matiz
                            game.matriz[j][p] = temp[k];
                        }
                    }

                    break; 

                case 3: case 7://Se a palavra ficar na diagonal de baixo para cima
                    game.wrdsspot[i][2] = rand() % ((game.m - sizestring) + 1); //Linha final da palavra
                    game.wrdsspot[i][1] = rand() % ((game.n - sizestring) + 1); //Coluna inicial da palavra
                    game.wrdsspot[i][0] = game.wrdsspot[i][2] + sizestring - 1; //Linha inicial da palavra
                    game.wrdsspot[i][3] = game.wrdsspot[i][1] + sizestring - 1; //Coluna final da palavra

                    for(int j = game.wrdsspot[i][0], p =  game.wrdsspot[i][1], k = 0; p <= game.wrdsspot[i][3]; j--, p++, k++){ //Laço ira varrer a area que a palvra vai vicar em busca de impecilio
                        if((game.matriz[j][p] != '-') && //Se no locoal tiver uma letra
                        (game.matriz[j][p] != temp[k])){confirm = 0; break;} //Se a letra no local for diferente da letra correspontende na palavra ela o comfirm muda
                    }

                    if(confirm == 1){
                        for(int j = game.wrdsspot[i][0], p =  game.wrdsspot[i][1], k = 0; p <= game.wrdsspot[i][3]; j--, p++, k++){ //Laço ira alocar a palvra na matiz
                            game.matriz[j][p] = temp[k];
                        }
                    }

                    break; 
            }
        }

        confirm = 0;
    }

    for(int i = 0; i < game.m; i++){ //Gera letras aleatorias para completar a matriz
        for(int j = 0; j < game.n; j++){
            if(game.matriz[i][j] == '-'){ game.matriz[i][j] = (char)( 65 + (rand() % 26));}
        }
    }
    
    return game;
}

void play_jogo(jogo game){ //Função que vai rodar o jogo
    system(limpa);
    //Parte de cima do caça-palavras
    printf("   ");
    for(int i = 65; i < game.n + 65; i++){
        printf(ANSI_BOLD  ANSI_COLOR_YELLOW "%4c" ANSI_RESET, (char) i);
    }
    printf("\n");

    //Parte de cima da estrutura do caça_palavras
    printf("    " TAB_TL TAB_HOR TAB_HOR TAB_HOR);
    for(int i = 0; i < game.n - 1; i++){
        printf(TAB_TJ TAB_HOR TAB_HOR  TAB_HOR );
    }
    printf(TAB_TR "\n");

    for(int i = 0; i < game.m; i++){
        //Parte lateral esquerda do caça-palavras
        printf(ANSI_BOLD  ANSI_COLOR_YELLOW "%3c " ANSI_RESET, (char) (i + 65)); 

        //Palavras do caça-palavras
        for(int j = 0; j < game.n; j++){
            printf(TAB_VER "%2c ", game.matriz[i][j]);
        }
        printf(TAB_VER);        
        
        //Parte lateral esquerda do caça-palavras
        printf(ANSI_BOLD  ANSI_COLOR_YELLOW " %c" ANSI_RESET, (char) (i + 65)); 
        
        //Meios do caça-palavras
        if(i < game.m - 1){
            printf("\n    " TAB_ML TAB_HOR TAB_HOR TAB_HOR);
            for(int j = 0; j < game.n - 1; j++){
                printf(TAB_MJ TAB_HOR TAB_HOR TAB_HOR);
            }        
            printf(TAB_MR);
        }

        printf("\n");
    }

    //Parte de baixo da estrutura do caça_palavras
    printf("    " TAB_BL TAB_HOR TAB_HOR TAB_HOR);
    for(int i = 0; i < game.n - 1; i++){
        printf(TAB_BJ TAB_HOR TAB_HOR  TAB_HOR );
    }
    printf(TAB_BR "\n");   
    
    printf("   ");
    for(int i = 65; i < game.n + 65; i++){
        printf(ANSI_BOLD  ANSI_COLOR_YELLOW "%4c" ANSI_RESET, (char) i);
    }
    printf("\n\n");

    //Palavras
    for(int i = 0; i < game.wrds; i++){
        printf("     %s %c%c %c%c\n", game.palavras[i], game.wrdsspot_ok[i][0], game.wrdsspot_ok[i][1], game.wrdsspot_ok[i][2], game.wrdsspot_ok[i][3]);
    }  
    printf("\n");
}

void cria_jogo(char arquvivo[], int nivel){ //Cria a struct do jogo
    jogo game; //Struct do jogo
    
    FILE *txt = fopen(arquvivo, "r"); //Abre o arquivo

    fscanf(txt, "%d %d", &game.m, &game.n); //Pega as dimensões da matriz
    fscanf(txt, "%d", &game.wrds); //Pega a quantidade de palavras do arquivo

    for(int i = 0; i < game.wrds; i++){//Pega as palavras do arquivo
        fscanf(txt, "%s", game.palavras[i]);
    }
    
    fclose(txt); //Fecha o arquivo

    game = gera_matriz(game, nivel); 
    play_jogo(game);
}
//Arquivos cabeçalho
#include "layouts.h"
#include "jogo.h"

//Prototipo de funções
void read(char arquivo[100]);
int verifica_arq(FILE *txt);

int verifica_arq(FILE *txt){ //Função que verifica se o arquivo segue as condições de bom funcionamento
    int m, n, qnt_wrds;
    fscanf(txt, "%d %d\n%d", &m, &n, &qnt_wrds);

    if((m > 26) || (n > 26)){ //Caso as dimenções do caça palavras utrapassem 26
        printf("\nERRO Alguma das dimenções do caça palavras utrapassa 26\n\n");
        return 1;
    } 
    
    if((qnt_wrds > m) || (qnt_wrds > n)){ //Caso a quantidade de palvras ultrapasse alguma dimenção
        printf("\nERRO A quantidade de palvras ultrapassa alguma das dimenções\n\n");
        return 1;
    } 
    
    char palavra[qnt_wrds][26];
    int tamanho;

    for(int i = 0; i < qnt_wrds; i++){
        fscanf(txt, "%s", palavra[i]);
        tamanho = strlen(palavra[i]);

        if((tamanho > m) || (tamanho > n)){ //Caso alguma palavra for maior que alguma dimenção
            printf("\nERRO Há uma palavra que é maior que alguma das dimenções\n\n");
            return 1;
        } 
        
        for(int j = 0; j < tamanho; j++){
            if(((palavra[i][j] < 'A') || (palavra[i][j] > 'Z')) &&
               ((palavra[i][j] < 'a') || (palavra[i][j] > 'z'))){
                printf("\nERRO Em alguma palavra há um caracter que não é letra\n");
                printf("Ou a quantidades de palvras é maior que a quantidade de palavras presentes\n\n");
                return 1;
            } //Caso haja algum caracter que não seja uma letra na palvra 
            //ou a quantidades de palvras é maior que a quantidade de palavras presentes
        }
    }

    return 0; //Nenhum erro encontrado
}

void read(char arquivo[100]){ //Função le um arquivo txt e imprime
    system(limpa); //limpar tela
    FILE *txt = fopen(arquivo, "r"); //Abrindo arquivo a ser lido
    char temp[1000]; //string temporaria
    char resp;

    while (1){
        fgets(temp, 1000, txt);
        if(strcmp(temp, "#end") == 0){break;} //caso o arquivo tenha terminado
        printf("%s", temp);
    }
    getchar(); scanf("%c", &resp);
    fclose(txt);
}

void nivel_newgame(char arquvivo[]){ //Função pega o nivel do jogo
    system(limpa); //Limpar tela
    char escolha[5];
    //Tela para definir a dificuldade
    printf("\n\nSelecione um nivel de difculdade\n\n");
    printf("1 - Facíl\n");
    printf("2 - Médio\n");
    printf("3 - Difícil\n\n");
    printf("Qualquer duvida vá à \"Instruções do jogo\" na tela inicial\n");
    printf("Para mudar a escolha de arquivo digite \"file\"\n");
    printf("Digite \"exit\" para sair do jogo ou \"main\" para voltar a tela inicial\n\n");
    printf("Escolha uma opção: "); scanf("%s", escolha);
    while(1){
        if(strcmp(escolha, "file") == 0){arq_newgame(); break;} //Caso o jogador queira mudar o arquivo
        else if(strcmp(escolha, "exit") == 0){printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "main") == 0){main_layout(); break;} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){ cria_jogo(arquvivo, 1); break;} //Caso o jogador queira jogar no modo Facil
        else if(strcmp(escolha, "2") == 0){ cria_jogo(arquvivo, 2); break;} //Caso o jogador queira jogar no modo Médio
        else if(strcmp(escolha, "3") == 0){ cria_jogo(arquvivo, 3); break;} //Caso o jogador queira jogar no modo Dificil
        else{
            printf("ERRO!!! Escolha uma opção valida: "); scanf("%s", escolha);
        }
    }
}

void arq_newgame(){ //Função pega o arquivo dicionario e verifica se ele exite
    system(limpa); //limpar tela
    int confim; 
    char arquivo[100];
    //Tela de novo jogo
    printf("\n\nNOVO JOGO\n\n");
    printf("Digite \"exit\" para sair do jogo ou \"main\" para voltar a tela inicial\n");
    printf("Qualquer duvida vá à \"Instruções do jogo\" na tela inicial\n\n");
    printf("OBS: Há alguns arquvios dicionario pre-montados na pasta \"dicionarios/\"\n\n");
    printf("Qual o arquivo dicionario que deseja usar? "); scanf("%s", arquivo); //Entrada do arquivo dicionario

    while(1){
        if(strcmp(arquivo, "exit") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(arquivo, "main") == 0){ main_layout(); break;} //Caso o jogador queira sair
        else {
            FILE *txt = fopen(arquivo, "r"); //Abre o arquivo
            if(txt){//Verifica se o arquivo existe
                confim = verifica_arq(txt); //Testa para ver se esta tudo certo
                fclose(txt);//fecha o arquivo
                
                if(confim == 0){nivel_newgame(arquivo); break;} //Ta tudo certo
                
                //Possiveis erros
                else{printf("Qual o arquivo dicionario que deseja usar? "); scanf("%s", arquivo);}
            }
            else{
                printf("ERRO arquivo não encontrado\n");
                printf("Qual o arquivo dicionario que deseja usar? "); scanf("%s", arquivo);
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
    printf("Digite \"exit\" para sair do jogo ou \"main\" para voltar a tela inicial\n\n");
    printf("Escolha uma opção: "); scanf("%s", escolha);

    while(1){
        if(strcmp(escolha, "exit") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "main") == 0){ main_layout(); break;} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){read("files/jogo.txt");} //Caso o jogador queira começar um novo jogo
        else if(strcmp(escolha, "2") == 0){read("files/niveis.txt");}
        else if(strcmp(escolha, "3") == 0){read("files/dicionarios.txt");}
        else if(strcmp(escolha, "4") == 0){read("files/conojogar.txt");}
        else{printf("ERRO: Escolha uma opção valida: "); scanf("%s", escolha); continue;}
        system(limpa); //limpar tela
        printf("\n\nINSTRUÇÕES\n");
        printf("O que deseja fazer:\n\n");
        printf("1 - Sobre o jogo\n");
        printf("2 - Sobre os niveis\n");
        printf("3 - Sobre os arquivos dicionario\n");
        printf("4 - Como jogar\n\n");
        printf("Digite \"exit\" para sair do jogo ou \"main\" para voltar a tela inicial\n\n");
        printf("Escolha uma opção: "); scanf("%s", escolha);
    }
}

void main_layout(){ //Tela inicial do jogo
    system(limpa); //limpar tela
    char escolha[5];
    //Tela inicial
    printf("\n\nOla :) Bem vindo ao jogo de caça palavras\n");
    printf("O que deseja fazer:\n\n");
    printf("1 - Começar um novo jogo\n");   
    printf("2 - Continuar um jogo anterior\n");
    printf("3 - Instruções do jogo\n\n");
    printf("Digite \"exit\" para sair do jogo\n\n");
    printf("Escolha uma opção: "); scanf("%s", escolha);
    
    while(1){
        if(strcmp(escolha, "exit") == 0){ printf("\nAté logo ;)\n\n"); exit(0);} //Caso o jogador queira sair
        else if(strcmp(escolha, "1") == 0){arq_newgame(); break;} //Caso o jogador queira começar um novo jogo
        else if(strcmp(escolha, "2") == 0){/*continue_game();*/ break;}
        else if(strcmp(escolha, "3") == 0){instructions(); break;}
        else{printf("ERRO: Escolha uma opção valida: "); scanf("%s", escolha);}
    }
}
int main(){
    main_layout();  //Tela inicial do jogo
    return 0;
}
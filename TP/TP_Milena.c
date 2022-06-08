/* Trabalho Prático - Quebra cabeca das 8 pastilhas
Milena Santana de Almeida, 21.1.4175
BCC201 Introdução a programação, turma 33
*/

//funcao para fechar arquivos
void fechaArquivo(FILE * arq){
    fclose(arq);
}

int main(){
    srand ( time(NULL) );
    char ** matriz;
    int m, n, op, qtd = 0;
    char  arquivo [50], **palavras, comando[50];
do{
    printf("Bem vindo ao jogo de CAÇA-PALAVRAS!\n");
    printf("Digite a opção desejada: \n\n");
    printf("1. Começar um novo jogo;\n2. Continuar um jogo salvo\n3. Ler instruções\n\n");
    scanf("%d", &op);

    switch (op){
        case 1:{
            printf("Digite o nome do arquivo com a lista das palavras: \n");
            scanf("%s", arquivo);
            FILE *file = fopen(arquivo, "r");
            fscanf(file, "%d\n", &n); //linha
            fscanf(file, "%d\n", &m); //coluna
            fscanf(file, "%d\n", &qtd); //quantidade de palavras
            palavras = criaMatriz(qtd, 50); // criando uma matriz de string para ler as palavras
            preenche_palavras(palavras, file, qtd); // preenchendo a matriz com as palavras do arquivo
            matriz = criaMatriz(n, m); // criando a matriz que será o futuro caça palavras
           
            for (int i = 0; i < n; i++){ 
                //preenchendo a matriz com valores aleatórios
                for (int j = 0; j < m; j++){
                    matriz[i][j] = 'A' + (char)(rand() % 26);
                }
            }

            int *tam = malloc(qtd);
            for(int i = 0; i < qtd; i ++){
                tam[i] = strlen(palavras[i]);
            }

            int **comeco = criaMatrizInt(qtd, 2), **fim = criaMatrizInt(qtd, 2), *pos = malloc(qtd * sizeof(int));
            int **linOcupada = criaMatrizInt(qtd, 2), **colOcupada = criaMatrizInt(qtd, 2); 
            int ocupado = 0; 

            for(int i = 0; i < qtd; i++){
                for(int j = 0; j < 2; j++){
                    linOcupada[j][i] = -1;
                    colOcupada[j][i] = -1;
                }
            }

            int nivel;
            printf("Escolha o nível de dificuldade:\n(1) fácil\n(2) médio\n(3) difícil\n");
            scanf("%d", &nivel);

            if(nivel==1){
                for (int i = 0; i < qtd; i++){ 
                    do{
                        pos[i] = (rand() % 2); 
                        if (pos[i] == 0){
                            //palavra horizontal
                            ocupado = faz_horizontal(comeco, tam,fim, linOcupada, colOcupada, i, n, m, matriz, palavras, 0);
                        } else{
                            // palavra na vertical
                            ocupado = faz_vertical(comeco, tam, fim, linOcupada, colOcupada, i , n , m, matriz, palavras, 0);
                        }
                    }while(ocupado == 1);
                }

            }
            if(nivel ==2){
                for (int i = 0; i < qtd; i++){ 
                        do{
                            pos[i] = (rand() % 3);

                            if (pos[i] == 0){
                                //palavra horizontal
                                 ocupado = faz_horizontal(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, 0);
                            }
                            if( pos[i] == 1){
                                // palavra na vertical
                                ocupado = faz_vertical(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, 0);
                            }
                            if(pos[i] == 2){
                                //palavra na diagonal
                                ocupado = faz_diagonal(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, 0);
                            }
                        }while(ocupado == 1);
                        
                    
                }
            }   
            if(nivel == 3){
                int d;
                 for (int i = 0; i < qtd; i++){ 
                        
                        pos[i] = (rand() % 3); 
                        d = (rand() % 2);
                        if (pos[i] == 0)
                        //palavra na horizontal
                            ocupado = faz_vertical(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, d); 
                            
                        if (pos[i] == 1) 
                        //palavra na vertical
                            ocupado = faz_vertical(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, d);
                        
                        if(pos[i] == 2) 
                        //palavra na diagonal
                           ocupado = faz_diagonal(comeco, tam, fim, linOcupada, colOcupada, i, n, m, matriz, palavras, d);
                }
            } 

            char **cmc = criaMatriz(qtd, 2);
            char **fin = criaMatriz(qtd, 2);
            for(int i = 0; i < qtd; i ++){
                cmc[i][0] = '-';
                fin[i][0] = '-';
                cmc[i][1] = '-';
                fin[i][1] = '-';
            }

            printf("    ");
            for (int j = 0; j < m; j++){
                printf("%c ", (j+65));
            }
            printf("\n");
            for(int i = 0; i < n; i++){
                printf("%c - ", (i+65));
            for (int j = 0; j < m; j++)
                printf("%c ", matriz[i][j]);

            printf("\n");
            }
            int cont = 0, *verificador = malloc(qtd * sizeof(int)); 
            
            printf("\nDigite o comando (MARCAR, SALVAR OU SAIR):\n");
            scanf("%s", comando);
    
            if(strcmp(comando, "marcar") == 0){ 
                printf("Agora, digite as coordenadas: \n");
                scanf("%c %c %c %c",&cmc[cont][0], &cmc[cont][1], &fin[cont][0], &fin[cont][1] );
                for(int i = 1; i < qtd; i++){
                    printf("%d %d %d %d\n", linOcupada[i][0], colOcupada[i][0], linOcupada[i][1], colOcupada[i][1]);
                    if(((int)cmc[cont][0] - 97 )== linOcupada[i][0] && ((int)cmc[cont][1] - 97 )== colOcupada[i][0] && ((int)fin[cont][0] - 97 )== linOcupada[i][1] && ((int)fin[cont][1] - 97 )== colOcupada[i][1]){
                        printf("%d %d", (int)cmc[cont][0] - 98, linOcupada[i][0]);
                        verificador[cont] = 1; //se acertar alguma palavra, ele salva 1 
                    }
                    else{
                        printf("Palavra desconhecida!");
                    }
                }

                cont++;
            }
            if(strcmp(comando, "salvar") == 0){
                printf("Digite o nome do arquivo par armazenar o jogo:\n");
                scanf("%s", arquivo);
                FILE * file = fopen(arquivo, "w");
                fprintf(file, "%d %d\n", n, m );
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        fprintf(file, "%c ", matriz[i][j]);
                    }
                    fprintf(file, "\n");
                }
                fprintf(file, "%d\n", qtd);
                for(int i = 0; i< qtd; i ++){
                    fprintf(file, "%s ", palavras[i]);
                    fprintf(file, "%c%c %c%c", cmc[i][0], cmc[i][1], fin[i][0], fin[i][1]);
                    
                    fprintf(file, "\n");
                }
                op = 0;
            }
            if(strcmp(comando, "resolver") == 0){
                printf("    ");
                for (int j = 0; j < m; j++){
                    printf("%c ", (j+65));
                }
                printf("\n");
                for(int i = 0; i < n; i++){
                    printf("%c - ", (i+65));
                for (int j = 0; j < m; j++)
                    if( (i == colOcupada[i][0] && j == linOcupada[i][0]) ){
                        textcolor( CN_REVERSE , CN_NO_COLOR , CN_NO_COLOR);
                        printf("%c ", matriz[i][j]); 
                    }else{
                        textcolor( CN_NORMAL , CN_NO_COLOR , CN_NO_COLOR);
                        printf("%c ", matriz[i][j]);
                    }

                printf("\n");
                }
                printf("Deseja realizar um novo jogo?\n(1)SIM\n(2)NAO\n");
                scanf("%d", &op);
                if(op == 2){
                    op = 0;
                }
            }
           if( strcmp(comando, "sair") == 0){
               op = 0;
           }

        break;
        liberaMatriz(cmc, qtd);
        liberaMatriz(fin, qtd);
        liberaMatrizInt(comeco, qtd);
        liberaMatrizInt(fim, qtd);
        liberaMatrizInt(linOcupada, qtd);
        liberaMatrizInt(colOcupada, qtd);
        liberaMatriz(palavras, qtd);
        liberaMatriz(matriz, n);
        fechaArquivo(file);
        
        }

        case 2: {
            printf("Digite o nome do arquivo com o jogo salvo:\n");
            scanf("%s", arquivo);
            FILE *arq = fopen(arquivo, "r");
            fscanf(arq, "%d %d\n", &n, &m); //lendo a linha e coluna do arquivo
            matriz = criaMatriz(n, m); 

            //lendo a matriz do arquivo
            for(int j = 0; j < n; j++){
                for(int k = 0; k < m; k++){
                    fscanf(arq, "%c ", &matriz[j][k]);
                }
            }
            fscanf(arq, "\n%d", &qtd); // lendo a quantidade de palavras
            palavras = criaMatriz(qtd, 50); //criando a matriz para armazenar as palavras

            char inicio[3], fim[3], **comeca, **termina;
            comeca = criaMatriz(qtd, 2);
            termina = criaMatriz(qtd, 2);
            for(int i = 0; i < qtd; i ++){
                comeca[i][0] = '-';
                termina[i][0] = '-';
                comeca[i][1] = '-';
                termina[i][1] = '-';
            }
            lendoJogoSalvo(inicio, fim, comeca, termina, palavras, qtd, arq);

            printf("\n");
            printf("    ");
            for (int j = 0; j < m; j++){
                printf("%c ", (j+65));
            }
            printf("\n");
            int p = 0;
            for(int j = 97; j < (n + 97); j++){
                int q = 0;
                printf("%c - ", (j-32));
                for(int k = 97; k < (m + 97); k++){ 
                        if(j >= comeca[0][p] && j <= termina[1][p] && k >= comeca[1][p] && k <= termina[1][p]){
                            textcolor( CN_REVERSE , CN_NO_COLOR , CN_NO_COLOR);
                            printf("%c ", matriz[p][q]); 
                        }
                        else{
                            textcolor( CN_NORMAL, CN_NO_COLOR, CN_NO_COLOR );
                            printf("%c ", matriz[p][q]);
                        }
                    q++;
                }
                printf("\n");
                p++;
            }

            printf("\nDigite o comando (MARCAR, SALVAR OU SAIR):\n");
            scanf("%s", comando);
            int cont = 0;
            op = 1;
    
            if(strcmp(comando, "marcar") == 0){ 
                printf("Agora, digite as coordenadas: \n");
                scanf("%c %c %c %c",&comeca[cont][0], &comeca[cont][1], &termina[cont][0], &termina[cont][1] );
            }
            if(strcmp(comando, "salvar") == 0){
                FILE * file = fopen(arquivo, "w");
                fprintf(file, "%d %d\n", n, m );
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        fprintf(file, "%c ", matriz[i][j]);
                    }
                    fprintf(file, "\n");
                }
                fprintf(file, "%d\n", qtd);
                for(int i = 0; i< qtd; i ++){
                    fprintf(file, "%s ", palavras[i]);
                    fprintf(file, "%c%c %c%c",  comeca[i][0], comeca[i][1], termina[i][0], termina[i][1]);
                    
                    fprintf(file, "\n");
                }
                printf("Arquivo atualizado com sucesso!\n");
                op = 0;
            }
            
           else if( strcmp(comando, "sair") == 0){
               op = 0;
           }

            liberaMatriz(comeca, qtd);
            liberaMatriz(termina, qtd);
            liberaMatriz(palavras, qtd);
            liberaMatriz(matriz, n);
            fechaArquivo(arq);
            break;
        }
        case 3: {
            printf("\nINSTRUÇÕES\n\n");
            printf("O jogo CAÇA-PALAVRAS é um jogo no qual será exibida uma matriz com m colunas e n linhas, escolhidas por você e informadas na primeira linha do arquivo*.\n");
            printf("Dentro dessa matriz, terá varias letras aleatórias. Você encontrará, em algum conjunto de posições da matriz, que essas letras formam algumas palavras, que também serão escolhidas e inseridas no arquivo*.\n");
            printf("Quando encontrar uma palavra, deverá marcá-la no caça-palavras. ");
            printf("Para isso, deverá digitar o comando \"marcar\" + coluna linha inicial + coluna linha final.\nExemplo: marcar AB CE, indica que a palavra começa na linha \"A\" coluna \"B\" e termina na linha \"C\" coluna \"E\" \n");
            printf("Para salvar o jogo e continuá-lo depois, basta digitar o comando \"salvar\" + o nome do arquivo em que deseja salvar (com a extensão .txt).\n");
            printf("Para visualizar o caça-palavras resolvido, digite \"resolver\" e para sair, digite \"sair\"\n");
            printf("Lembrando que ao sair, não serão salvas nenhuma alteração feita.\n\n");
            printf("* a estrutura do arquivo .txt deverá ser o seguinte:\n - Primeira linha: dimensões da matriz - linhas e colunas, respectivamente;\n - Segunda linha: Número de palavras;\n - Próximas linhas: as palavras escolhidas.\n\n");
            printf("Deseja voltar ao menu?\n(1)SIM\n(2)NAO\n");
            scanf("%d", &op);
            if(op == 2){
                op = 0;
            }
        break;        
        }
        default: {
        printf("Opção inválida!\n\n");
        
        break;
        }

    liberaMatriz(matriz, n);
    }
}while(op != 0);
    return 0;
}
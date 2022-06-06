
// menu de inicio
int inicio()
{
    char escolha[5];
    printf("\n\nBem vindo ao Quebra-Cabecas\n 0. Sair do Jogo\n1. Começar um novo jogo.\n2. Continuar o jogo atual \n 3. Continuar um jogo salvo. \n 4. Instrucoes do jogo. \n\n");
    printf("Escolha a opcao (digite \'sair\' em qualquer lugar para sair do jogo): ");
    fgets (escolha, 5, stdin);
    final (escolha);

    retorno (escolha[0] - '0');
}

// solicitar nome do nome do arquivo
solicitação de vazioNomeArquivo (char *nome)
{
    printf ("\nDigite o nome do arquivo com as palavras: ");
    scanf("%s", nome);
    final(nome);
}
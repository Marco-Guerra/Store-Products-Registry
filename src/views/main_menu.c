/**
 * @file menu.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar a
 * interface com o usuário
 * @version 0.1
 * @date 03/05/2021
 */

#include "../headers/menu.h"

void printCabecalho(const char *mensagem) {
    system(CLEAR);
    printLinha();
    printAlinhadoCentro(mensagem);
    printLinha();
}

void printAlinhadoDireita(const char *mensagem) {
    printf("|%s", mensagem);
    // -2 por causa dos |
    printExtedido(' ', TAM_LINHA - strlen(mensagem) - 2);
    printf("|\n");
}

void printAlinhadoCentro(const char *mensagem) {
    int tam_escrito = (strlen(mensagem) + 2);
    int espaco = (TAM_LINHA - tam_escrito) / 2;
    printf("|");
    printExtedido(' ', espaco);
    printf("%s", mensagem);
    printExtedido(' ', espaco);
    if (!(tam_escrito % 2)) {
        printf(" ");
    }
    printf("|\n");
}

void printAlinhadoEsquerda(const char *mensagem) {
    printf("|");
    printExtedido(' ', (TAM_LINHA - (strlen(mensagem) + 2)));
    printf("%s|\n", mensagem);
}

void printOpcao(const char* mensagem, int selecionado) {
    printf("| [");
    if(selecionado) {
        printf("x");
    }else {
        printf(" ");
    }
    printf("] %s", mensagem);
    // 6 caracteres antes da mensagem e 1 depois
    printExtedido(' ', TAM_LINHA - (strlen(mensagem) + 7));
    printf("|\n");
}

void printLinha() {
    printf("|");
    printExtedido('-', TAM_LINHA - 2);
    printf("|\n");
}

void printExtedido(char c, int qnt) {
    for(int i = 0; i < qnt; i++) {
        printf("%c", c);
    }
}

void printMenuEspera() {
    printLinha();
    // imprime uma linha em branco
    printf("|%*s|\n", TAM_LINHA - 2, "");
    printf("|%*s|\n", TAM_LINHA - 2, "");
    printAlinhadoCentro("Pressione [Enter] para continuar");
    printf("|%*s|\n", TAM_LINHA - 2, "");
    printf("|%*s|\n", TAM_LINHA - 2, "");
    printLinha();
    getchar();
}

void printMensagemFinal() {
    system(CLEAR);
    printLinha();
    printf("|%*s|\n", TAM_LINHA - 2, "");
    printf("|%*s|\n", TAM_LINHA - 2, "");
    printAlinhadoCentro("Programa finalizado com sucesso");
    printf("|%*s|\n", TAM_LINHA - 2, "");
    printf("|%*s|\n", TAM_LINHA - 2, "");
    printLinha();
}

void printMenuPrincipal(int escolhido) {
    printCabecalho("Controle de Estoque (Nome Legal)");
    printOpcao("Inserir", escolhido == 0);
    printOpcao("Remover", escolhido == 1);
    printOpcao("Alterar quantidade em estoque", escolhido == 2);
    printOpcao("Alterar preco", escolhido == 3);
    printOpcao("Alterar local do produto", escolhido == 4);
    printOpcao("Carregar estoque", escolhido == 5);
    printOpcao("Buscar produto", escolhido == 6);
    printOpcao("Listar produtos", escolhido == 7);
    printOpcao("Mostar arvore", escolhido == 8);
    printOpcao("Mostrar posicoes livres", escolhido == 9);
    printOpcao("Finalizar programa", escolhido == 10);
    printLinha();
}

void printFila(Fila *f) {
    printLinha();
    printAlinhadoDireita("Conteudo da Fila");
    printLinha();
    if (vaziaFila(f)) {
        printAlinhadoDireita("[vazia]");
    }else {
        printf("|");
        printFilaCauda(f->cabeca, f->cauda);
        printf("|\n");
    }
    printLinha();
}

void printFilaCauda(No *inicio, No *fim) {
    if (inicio == fim) {
        printf("|%d", inicio->info);
    }else {
        printf("|%d ", inicio->info);
        printFilaCauda(inicio->prox, fim);
    }
}

void printProduto(Produto p) {
    int tam = 11;
    char buffer[50];
    printLinha();

    sprintf(buffer, "%d", p.cod);
    printf("|Codigo    : %s", buffer);
    printExtedido(' ', TAM_LINHA - (tam + strlen(buffer) + 3));
    printf("|\n");

    printf("|Nome      : %s", p.nome);
    printExtedido(' ', TAM_LINHA - (tam + strlen(p.nome) + 3));
    printf("|\n");

    sprintf(buffer, "%d", p.qnt);
    printf("|Quantidade: %s", buffer);
    printExtedido(' ', TAM_LINHA - (tam + strlen(buffer) + 3));
    printf("|\n");

    sprintf(buffer, "%.2f R$", p.preco);
    printf("|Preco     : %s", buffer);
    printExtedido(' ', TAM_LINHA - (tam + strlen(buffer) + 3));
    printf("|\n");

    printf("|Local     : %s", p.local);
    printExtedido(' ', TAM_LINHA - (tam + strlen(p.local) + 3));
    printf("|\n");

    printLinha();
}
/**
 * @file menu.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar a
 * interface com o usuário
 * @version 0.1
 * @date 03/05/2021
 */

#include "main_menu.h"

void printHead(const char *message) {
    system(CLEAR);
    printLine();
    printAlignedCenter(message);
    printLine();
}

void printAlignedRight(const char *message) {
    printf("|%s", message);
    // -2 por causa dos |
    printExtended(' ', SIZE_LINE - strlen(message) - 2);
    printf("|\n");
}

void printAlignedCenter(const char *message) {
    int sizeRead = (strlen(message) + 2);
    int space = (SIZE_LINE - sizeRead) / 2;
    printf("|");
    printExtended(' ', space);
    printf("%s", message);
    printExtended(' ', space);
    if (!(sizeRead % 2)) {
        printf(" ");
    }
    printf("|\n");
}

void printAlignedLeft(const char *message) {
    printf("|");
    printExtended(' ', (SIZE_LINE - (strlen(message) + 2)));
    printf("%s|\n", message);
}

void printOption(const char* message, int selected) {
    printf("| [");
    if(selected) {
        printf("x");
    }else {
        printf(" ");
    }
    printf("] %s", message);
    // 6 caracteres antes da mensagem e 1 depois
    printExtended(' ', SIZE_LINE - (strlen(message) + 7));
    printf("|\n");
}

void printLine() {
    printf("|");
    printExtended('-', SIZE_LINE - 2);
    printf("|\n");
}

void printExtended(char c, int number) {
    for(int i = 0; i < number; i++) {
        printf("%c", c);
    }
}

void printWaitMenu() {
    printLine();
    // imprime uma linha em branco
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Pressione [Enter] para continuar");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
    getchar();
}

void printEndMessage() {
    system(CLEAR);
    printLine();
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Programa finalizado com sucesso");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
}

void printMainMenu(int selected) {
    printHead("Controle de Estoque (Nome Legal)");
    printOption("Inserir", selected == 0);
    printOption("Remover", selected == 1);
    printOption("Alterar quantidade em estoque", selected == 2);
    printOption("Alterar preco", selected == 3);
    printOption("Alterar local do produto", selected == 4);
    printOption("Carregar estoque", selected == 5);
    printOption("Buscar produto", selected == 6);
    printOption("Listar produtos", selected == 7);
    printOption("Mostar arvore", selected == 8);
    printOption("Mostrar posicoes livres", selected == 9);
    printOption("Finalizar programa", selected == 10);
    printLine();
}

void printQueue(Queue *queue) {
    printLine();
    printAlignedRight("Conteudo da Fila");
    printLine();
    if (emptyQueue(queue)) {
        printAlignedRight("[vazia]");
    }else {
        printf("|");
        printQueueTail(queue->head, queue->tail);
        printf("|\n");
    }
    printLine();
}

void printQueueTail(Node *start, Node *end) {
    if (start == end) {
        printf("|%d", start->data);
    }else {
        printf("|%d ", start->data);
        printQueueTail(start->prox, end);
    }
}

void printProduct(Product product) {
    int size = 11;
    char buffer[50];

    printLine();

    sprintf(buffer, "%d", product.code);
    printf("|Codigo    : %s", buffer);
    printExtended(' ', SIZE_LINE - (size + strlen(buffer) + 3));
    printf("|\n");

    printf("|Nome      : %s", product.name);
    printExtended(' ', SIZE_LINE - (size + strlen(product.name) + 3));
    printf("|\n");

    sprintf(buffer, "%d", product.number);
    printf("|Quantidade: %s", buffer);
    printExtended(' ', SIZE_LINE - (size + strlen(buffer) + 3));
    printf("|\n");

    sprintf(buffer, "%.2f R$", product.value);
    printf("|Preco     : %s", buffer);
    printExtended(' ', SIZE_LINE - (size + strlen(buffer) + 3));
    printf("|\n");

    printf("|Local     : %s", product.local);
    printExtended(' ', SIZE_LINE - (size + strlen(product.local) + 3));
    printf("|\n");

    printLine();
}
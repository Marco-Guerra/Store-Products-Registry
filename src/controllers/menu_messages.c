#include "menu_messages.h"

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

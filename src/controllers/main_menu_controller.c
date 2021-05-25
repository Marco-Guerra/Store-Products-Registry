/**
 * @file controle_principal.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as funções que controlam o menu principal, bem como a chamada de todas as funções a partir do mesmo
 * @version 0.1
 * @date 04/05/2021
 */

#include "main_menu_controller.h"

int mainMenuController(char **filePath) {
    Menu *mainMenu = createMenu();
    
    addEntryToMenu(mainMenu, "Insert", actionInsert);
    addEntryToMenu(mainMenu, "Search", actionSearch);
    addEntryToMenu(mainMenu, "Change", actionChange);
    addEntryToMenu(mainMenu, "Load", actionLoad);
    addEntryToMenu(mainMenu, "Remove", actionRemove);
    addEntryToMenu(mainMenu, "Close", actionClose);
    
    controlMenu(mainMenu);
    return 1;
}

int actionInsert() {
    printHead("Inserindo novo produto");
    Product *product = allocProduct();
    printf("\n\n   Insira o codigo do produto: ");
    readCodeProduct(&product->code);
    printf("   Insira o nome do produto: ");
    readNameProduct(product->name);
    printf("   Insira a quantidade produto(s): ");
    readNumberProduct(&product->number);
    printf("   Insira o preco do produto: ");
    readValueProduct(&product->value);
    printf("   Insira o local do produto: ");
    readLocalProduct(product->local);

    printf("\n\n");
    printProduct(*product);

    if (confirm()) {
        printHead("Operacao bem suces");
    }

    printWaitMenu();
    return 1;
}

int actionSearch() {
    searchMenuController();
    return 1;
}

int actionChange() {
    changeMenuController();
    return 1;
}

int actionLoad() {
    printLine();
    printAlignedRight("Load");
    printLine();
    printWaitMenu();
    return 1;
}

int actionRemove() {
    printLine();
    printAlignedRight("Remove");
    printLine();
    printWaitMenu();
    return 1;
}

int actionClose() {
    printLine();
    printAlignedRight("Close");
    printLine();
    printWaitMenu();
    return 0;
}

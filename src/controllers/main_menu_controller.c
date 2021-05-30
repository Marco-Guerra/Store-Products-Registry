/**
 * @file controle_principal.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as funções que controlam o menu principal, bem como a chamada de todas as funções a partir do mesmo
 * @version 0.1
 * @date 04/05/2021
 */

#include "main_menu_controller.h"

int mainMenuController(FILE *dataFile) {
    Menu *mainMenu = createMenu();
    
    addEntryToMenu(mainMenu, "Inserir produto.", actionInsert);
    addEntryToMenu(mainMenu, "Buscar produto.", actionSearch);
    addEntryToMenu(mainMenu, "Cambiar informacao de produto..", actionChange);
    addEntryToMenu(mainMenu, "Carregar lista de produtos.", actionLoad);
    addEntryToMenu(mainMenu, "Remover produto.", actionRemove);
    addEntryToMenu(mainMenu, "Fechar programa.", actionClose);
    
    controlMenu(mainMenu, dataFile);
    return 1;
}

int actionInsert(FILE *dataFile) {
    Product *product = scanProduct();
    insertProduct(dataFile, product);
    free(product);
    printWaitMenu();
    return 1;
}

int actionSearch(FILE *dataFile) {
    searchMenuController(dataFile);
    return 1;
}

int actionChange(FILE *dataFile) {
    changeMenuController(dataFile);
    return 1;
}

int actionLoad(FILE *dataFile) {
    printWaitMenu();
    return 1;
}

int actionRemove(FILE *dataFile) {
    printWaitMenu();
    return 1;
}

int actionClose(FILE *dataFile) {
    printEndMessage();
    return 0;
}
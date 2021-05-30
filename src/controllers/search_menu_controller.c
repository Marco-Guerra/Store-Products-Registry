#include "search_menu_controller.h"

int searchMenuController(FILE *dataFile) {
    Menu *searchMenu = createMenu();
    
    addEntryToMenu(searchMenu, "Buscar produto por nome.", actionSearchProductByName);
    addEntryToMenu(searchMenu, "Buscar produto por codigo.", actionSearchProductByCode);
    addEntryToMenu(searchMenu, "Listar produtos.", actionListProducts);
    addEntryToMenu(searchMenu, "Mostrar arvore.", actionPrintTree);
    addEntryToMenu(searchMenu, "Mostrar espacos livres.", actionPrintFreeSpaces);
    addEntryToMenu(searchMenu, "Voltar.", actionSearchReturn);
    
    controlMenu(searchMenu, dataFile);
    return 1;
}

int actionSearchProductByName(FILE *dataFile) {
    char name[MAX_NAME];
    printf("Insira o nome do produto: ");
    scanf("%s", name);
    searchProductByName(dataFile, name);
    printWaitMenu();
    return 1;
}

int actionSearchProductByCode(FILE *dataFile) {
    int code;
    printf("Insira o codigo do produto: ");
    scanf("%d", code);
    searchProductByCode(dataFile, code);
    printWaitMenu();
    return 1;
}

int actionListProducts(FILE *dataFile) {
    
    printWaitMenu();
    return 1;
}

int actionPrintTree(FILE *dataFile) {
    printWaitMenu();
    return 1;
}

int actionPrintFreeSpaces(FILE *dataFile) {
    printWaitMenu();
    return 1;
}

int actionSearchReturn(FILE *dataFile) {
    return 0;
}

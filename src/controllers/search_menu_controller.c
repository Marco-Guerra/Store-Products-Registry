#include "search_menu_controller.h"

int searchMenuController() {
    Menu *searchMenu = createMenu();
    
    addEntryToMenu(searchMenu, ".", actionProductInfo);
    addEntryToMenu(searchMenu, ".", actionListProducts);
    addEntryToMenu(searchMenu, ".", actionPrintTree);
    addEntryToMenu(searchMenu, ".", actionPrintFreeSpaces);
    addEntryToMenu(searchMenu, "voltar.", actionSearchReturn);
    
    controlMenu(searchMenu);
    return 1;
}

int actionProductInfo() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
    return 1;
}

int actionListProducts() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
    return 1;
}

int actionPrintTree() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
    return 1;
}

int actionPrintFreeSpaces() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
    return 1;
}

int actionSearchReturn() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
    return 0;
}

#include "change_menu_controller.h"

int changeMenuController() {
    Menu *changeMenu = createMenu();
    
    addEntryToMenu(changeMenu, "Alterar estoque.", actionChangeNumber);
    addEntryToMenu(changeMenu, "Alterar preco.", actionChangeValue);
    addEntryToMenu(changeMenu, "Alterar localizacao.", actionChangeLocal);
    addEntryToMenu(changeMenu, "voltar.", actionChangeReturn);
    
    controlMenu(changeMenu);
    return 1;
}

int actionChangeNumber() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
}

int actionChangeValue() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
}

int actionChangeLocal() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
}

int actionChangeReturn() {
    printLine();
    printAlignedRight("");
    printLine();
    printWaitMenu();
    return 0;
}

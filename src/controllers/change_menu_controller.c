#include "change_menu_controller.h"

int changeMenuController(FILE *dataFile) {
    Menu *changeMenu = createMenu();
    
    addEntryToMenu(changeMenu, "Alterar estoque.", actionChangeNumber);
    addEntryToMenu(changeMenu, "Alterar preco.", actionChangeValue);
    addEntryToMenu(changeMenu, "Alterar localizacao.", actionChangeLocal);
    addEntryToMenu(changeMenu, "Voltar.", actionChangeReturn);
    
    controlMenu(changeMenu, dataFile);
    return 1;
}

int actionChangeNumber(FILE *dataFile) {
    printWaitMenu();
}

int actionChangeValue(FILE *dataFile) {
    printWaitMenu();
}

int actionChangeLocal(FILE *dataFile) {
    printWaitMenu();
}

int actionChangeReturn(FILE *dataFile) {
    return 0;
}

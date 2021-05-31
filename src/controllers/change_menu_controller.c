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
    int code, number;
    printf("Indique o codigo do produto: ");
    scanf("%d", number);
    if(searchProductByCode(dataFile, code) != -1) {
        
    }else{
        printf("Produto nao encontrado.");
    }
    printWaitMenu();
    return 1;
}

int actionChangeValue(FILE *dataFile) {
    int code, value;
    printf("Indique o codigo do produto: ");
    scanf("%d", value);
    if(searchProductByCode(dataFile, code) != -1) {
        
    }else{
        printf("Produto nao encontrado.");
    }
    printWaitMenu();
    return 1;
}

int actionChangeLocal(FILE *dataFile) {
    int code;
    char local[MAX_LOCAL];
    printf("Indique o codigo do produto: ");
    scanf("%s", local);
    if(searchProductByCode(dataFile, code) != -1) {
        
    }else{
        printf("Produto nao encontrado.");
    }
    printWaitMenu();
    return 1;
}

int actionChangeReturn(FILE *dataFile) {
    return 0;
}

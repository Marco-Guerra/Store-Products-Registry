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
    int code, position;
    printf("Indique o codigo do produto: ");
    scanf("%d", &code);
    if((position = searchProductByCode(dataFile, code)) != -1) {
        Product *product = readNodeProduct(dataFile, position);
        printf("Indique o numero de produtos em estoque: ");
        scanf("%d%*c", &(product->number));
        if(confirm()) {
            updateProduct(dataFile, position, product);
        }
        free(product);
    }else{
        printf("Produto nao encontrado.");
    }
    printWaitMenu();
    return 1;
}

int actionChangeValue(FILE *dataFile) {
    int code, position;
    printf("Indique o codigo do produto: ");
    scanf("%d", &code);
    if((position = searchProductByCode(dataFile, code)) != -1) {
        Product *product = readNodeProduct(dataFile, position);
        printf("Indique o novo valor do produto: ");
        scanf("%f%*c", &(product->value));
        if(confirm()) {
            updateProduct(dataFile, position, product);
        }
        free(product);
    }else{
        printf("Produto nao encontrado.");
    }
    printWaitMenu();
    return 1;
}

int actionChangeLocal(FILE *dataFile) {
    int code, position;
    printf("Indique o codigo do produto: ");
    scanf("%d", &code);
    if((position = searchProductByCode(dataFile, code)) != -1) {
        Product *product = readNodeProduct(dataFile, position);
        printf("Indique o novo local do produto: ");
        scanf("%[^\n]%*c", product->local);
        if(confirm()) {
            updateProduct(dataFile, position, product);
        }
        free(product);
    }else{
        printf("Produto nao encontrado.");
    }
    printWaitMenu();
    return 1;
}

int actionChangeReturn(FILE *dataFile) {
    return 0;
}

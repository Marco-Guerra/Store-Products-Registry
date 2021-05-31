/**
 * @file search_menu_controller.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 31/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "search_menu_controller.h"

/**
 * @brief
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int searchMenuController(FILE *dataFile) {
    Menu *searchMenu = createMenu();
    
    //addEntryToMenu(searchMenu, "Buscar produto por nome.", actionSearchProductByName);
    addEntryToMenu(searchMenu, "Buscar produto por codigo.", actionSearchProductByCode);
    addEntryToMenu(searchMenu, "Listar produtos.", actionListProducts);
    addEntryToMenu(searchMenu, "Mostrar arvore.", actionPrintTree);
    addEntryToMenu(searchMenu, "Mostrar espacos livres.", actionPrintFreeSpaces);
    addEntryToMenu(searchMenu, "Voltar.", actionSearchReturn);
    
    controlMenu(searchMenu, dataFile);
    return 1;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
int actionSearchProductByName(FILE *dataFile) {
    char name[MAX_NAME];
    printf("Insira o nome do produto: ");
    scanf("%[^\n]%*c", name);
    searchProductByName(dataFile, name);
    printWaitMenu();
    return 1;
}
 */

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchProductByCode(FILE *dataFile) {
    int code, position;
    printf("Insira o codigo do produto: ");
    scanf("%d%*c", &code);
    if((position = searchProductByCode(dataFile, code)) != -1) {
        Product *product = readNodeProduct(dataFile, position);
        printProduct(product);
        free(product);
    }
    printWaitMenu();
    return 1;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionListProducts(FILE *dataFile) {
    printHead("Imprimindo a Arvore em ordem crescente");
    printInOrder(dataFile);
    printWaitMenu();
    return 1;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintTree(FILE *dataFile) {
    printHead("Imprimindo a Arvore em niveis");
    printByLevel(dataFile);
    printWaitMenu();
    return 1;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintFreeSpaces(FILE *dataFile) {
    printHead("Espacos livres");
    printFreeSpaces(dataFile);
    printWaitMenu();
    return 1;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchReturn(FILE *dataFile) {
    return 0;
}

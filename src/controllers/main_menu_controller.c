/**
 * @file controle_principal.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as funções que controlam o menu principal, bem como a chamada de todas as funções a partir do mesmo
 * @version 0.1
 * @date 04/05/2021
 */

#include "main_menu_controller.h"

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
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

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionInsert(FILE *dataFile) {
    Product *product = scanProduct();
    insertProduct(dataFile, product);
    free(product);
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
int actionSearch(FILE *dataFile) {
    searchMenuController(dataFile);
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
int actionChange(FILE *dataFile) {
    changeMenuController(dataFile);
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
int actionLoad(FILE *dataFile) {
    char inputPath[FILE_PATH_NAME];
    printf("Nome de arquivo de entrada: ");
    scanf("%s", inputPath);
    loadInputFile(inputPath, dataFile);
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
int actionRemove(FILE *dataFile) {
    int code;
    printf("Codigo do produto: ");
    scanf("%d", &code);
    if(removeProduct(dataFile, code) != -1) {
        printf("Produto removido com sucesso.");
    }else{
        printf("Produto nao encontrado.");
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
int actionClose(FILE *dataFile) {
    printEndMessage();
    return 0;
}

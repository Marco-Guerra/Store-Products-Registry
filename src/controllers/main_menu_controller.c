/**
 * @file main_menu_controller.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 04/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "main_menu_controller.h"

/**
 * @brief Insere no menu principal cada função necessaria
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Menu com as funções inseridas
 */
int mainMenuController(FILE *dataFile) {
    Menu *mainMenu = createMenu();
    addEntryToMenu(mainMenu, "Inserir produto.", actionInsert);
    addEntryToMenu(mainMenu, "Buscar produto.", actionSearch);
    addEntryToMenu(mainMenu, "Cambiar informacao de produto.", actionChange);
    addEntryToMenu(mainMenu, "Carregar lista de produtos.", actionLoad);
    addEntryToMenu(mainMenu, "Remover produto.", actionRemove);
    addEntryToMenu(mainMenu, "Fechar programa.", actionClose);
    controlMenu(mainMenu, dataFile);
    return 1;
}

/**
 * @brief Insere produto no arquivo
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto inserido na arvore
 */
int actionInsert(FILE *dataFile) {
    Product *product = scanProduct();
    insertProduct(dataFile, product);
    free(product);
    printWaitMenu();
    return 1;
}

/**
 * @brief chama funçao responsavel em realizar a busca pelo produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto encontrado
 */
int actionSearch(FILE *dataFile) {
    searchMenuController(dataFile);
    return 1;
}

/**
 * @brief chama funçao responsavel em realizar a atualizaçao dos componentes
 * do produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto alterado
 */
int actionChange(FILE *dataFile) {
    changeMenuController(dataFile);
    return 1;
}

/**
 * @brief Roda arquivo
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post arquivo rodado
 */
int actionLoad(FILE *dataFile) {
    char inputPath[FILE_PATH_NAME];
    printf("\tNome de arquivo de entrada: ");
    scanf("%s", inputPath);
    loadInputFile(inputPath, dataFile);
    printWaitMenu();
    return 1;
}

/**
 * @brief Remove produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Produto removido
 */
int actionRemove(FILE *dataFile) {
    int code;
    printf("\tCodigo do produto: ");
    scanf("%d%*c", &code);
    if(removeProduct(dataFile, code) != -1)
        printf("Produto removido com sucesso.\n");
    else
        printf("Produto nao encontrado.\n");
    printWaitMenu();
    return 1;
}

/**
 * @brief chama função responsavel por imprimir a mensagem que indica o
 * encerramento do programa
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Mensagem no console
 */
int actionClose(FILE *dataFile) {
    printEndMessage();
    return 0;
}

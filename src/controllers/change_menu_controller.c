/**
 * @file change_menu_controller.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 31/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "change_menu_controller.h"

/**
 * @brief Insere atualizações no menu
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Menu alterado
 */
int changeMenuController(FILE *dataFile) {
    Menu *changeMenu = createMenu();
    addEntryToMenu(changeMenu, "Alterar estoque.", actionChangeNumber);
    addEntryToMenu(changeMenu, "Alterar preco.", actionChangeValue);
    addEntryToMenu(changeMenu, "Alterar localizacao.", actionChangeLocal);
    addEntryToMenu(changeMenu, "Voltar.", actionChangeReturn);
    controlMenu(changeMenu, dataFile);
    return 1;
}

/**
 * @brief Atualiza a quantidade de um produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto atualizado
 */
int actionChangeNumber(FILE *dataFile) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d", &code);
    if((position = searchProductByCode(dataFile, code)) != -1) {
        Product *product = readNodeProduct(dataFile, position);
        printf("\tIndique o numero de produtos em estoque: ");
        scanf("%d%*c", &(product->number));
        if(confirm())
            updateProduct(dataFile, position, product);
        free(product);
    }else{
        printf("Produto nao encontrado.\n");
    }
    printWaitMenu();
    return 1;
}

/**
 * @brief Atualza o preço do produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post preço atualizado
 */
int actionChangeValue(FILE *dataFile) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d", &code);
    if((position = searchProductByCode(dataFile, code)) != -1) {
        Product *product = readNodeProduct(dataFile, position);
        printf("Indique o novo valor do produto: ");
        scanf("%f%*c", &(product->value));
        if(confirm())
            updateProduct(dataFile, position, product);
        free(product);
    }else{
        printf("Produto nao encontrado.\n");
    }
    printWaitMenu();
    return 1;
}

/**
 * @brief Atualiza o lugar do estoque do produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post local alterado
 */
int actionChangeLocal(FILE *dataFile) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d%*c", &code);
    if((position = searchProductByCode(dataFile, code)) != -1) {
        Product *product = readNodeProduct(dataFile, position);
        printf("Indique o novo local do produto: ");
        scanf("%[^\n]%*c", product->local);
        if(confirm())
            updateProduct(dataFile, position, product);
        free(product);
    }else{
        printf("Produto nao encontrado.\n");
    }
    printWaitMenu();
    return 1;
}

/**
 * @brief Volta ao menu anterior
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post 
 */
int actionChangeReturn(FILE *dataFile) {
    return 0;
}

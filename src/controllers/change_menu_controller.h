#ifndef CHANGE_MENU_CONTROLLER
#define CHANGE_MENU_CONTROLLER

#include "../utilities/menu.h"
#include "../utilities/utilities.h"
#include "../models/product_tree.h"

/**
 * @brief atualiza menu
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Menu alterado
 */
int changeMenuController(FILE *dataFile);

/**
 * @brief Atualiza a quantidade de um produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto atualizado
 */
int actionChangeNumber(FILE *dataFile);

/**
 * @brief Atualza o preço do produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post preço atualizado
 */
int actionChangeValue(FILE *dataFile);

/**
 * @brief Atualiza o lugar do estoque do produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post local alterado
 */
int actionChangeLocal(FILE *dataFile);

/**
 * @brief Volta ao menu anterior
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post 
 */
int actionChangeReturn(FILE *dataFile);

#endif

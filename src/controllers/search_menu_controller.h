#ifndef SEARCH_MENU_CONTROLLER
#define SEARCH_MENU_CONTROLLER

#include "../utilities/menu.h"
#include "../utilities/utilities.h"
#include "../models/product_tree.h"

/**
 * @brief Insere operações de busca no menu
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Menu com funções de busca
 */
int searchMenuController(FILE *dataFile);

int actionSearchProductByName(FILE *dataFile);

/**
 * @brief Busca produto pelo código
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto encontrado pelo código
 */
int actionSearchProductByCode(FILE *dataFile);

/**
 * @brief Imprime arvore binaria de produtos
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Lista de produtos no console
 */
int actionListProducts(FILE *dataFile);

/**
 * @brief Imprime arvore binaria em niveis
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Arvore em niveis no console
 */
int actionPrintTree(FILE *dataFile);

/**
 * @brief Imprime espaços em branco
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Espaços no console
 */
int actionPrintFreeSpaces(FILE *dataFile);

/**
 * @brief Volta ao menu anterior
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchReturn(FILE *dataFile);

#endif

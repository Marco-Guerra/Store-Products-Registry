/**
 * @file main_menu_controller.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 1.0
 * @date 28/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef MAIN_MENU_CONTROLLER
#define MAIN_MENU_CONTROLLER

#include "../utilities/menu.h"
#include "../utilities/utilities.h"
#include "../models/input_file.h"
#include "../models/product_tree.h"
#include "search_menu_controller.h"
#include "change_menu_controller.h"

/**
 * @brief Insere no menu principal cada função necessaria
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Menu com as funções inseridas
 */
int mainMenuController(FILE *dataFile);

/**
 * @brief Insere produto no arquivo
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto inserido na arvore
 */
int actionInsert(FILE *dataFile);

/**
 * @brief chama funçao responsavel em realizar a busca pelo produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto encontrado
 */
int actionSearch(FILE *dataFile);

/**
 * @brief chama funçao responsavel em realizar a atualizaçao dos componentes
 * do produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post produto alterado
 */
int actionChange(FILE *dataFile);

/**
 * @brief Roda arquivo
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post arquivo rodado
 */
int actionLoad(FILE *dataFile);

/**
 * @brief Remove produto
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Produto removido
 */
int actionRemove(FILE *dataFile);

/**
 * @brief chama função responsavel por imprimir a mensagem que indica o
 * encerramento do programa
 * 
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post Mensagem no console
 */
int actionClose(FILE *dataFile);

#endif
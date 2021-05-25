#ifndef MAIN_MENU_CONTROLLER
#define MAIN_MENU_CONTROLLER

/**
 * @file controle_principal.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir as funções que controlam
 * o menu principal, bem como a chamada de todas as funções a partir do mesmo
 * @version 0.1
 * @date 04/05/2021
 */

/**
 * @file controle_operacao.h
 * @author
 * @brief
 * @version 0.1
 * @date 21/05/2021
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../utilities/menu.h"
#include "../utilities/utilities.h"
#include "search_menu_controller.h"
#include "change_menu_controller.h"

int mainMenuController();

int actionInsert();
int actionSearch();
int actionChange();
int actionLoad();
int actionRemove();
int actionClose();

#endif
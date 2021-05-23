#ifndef CONTROLE
#define CONTROLE

/**
 * @file controle_principal.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir as funções que controlam
 * o menu principal, bem como a chamada de todas as funções a partir do mesmo
 * @version 0.1
 * @date 04/05/2021
 */

#include "menu.h"
#include "../utilities/utilities.h"
#include "../views/main_menu.h"

/**
 * @brief Indica qual a última opção que o menu principal possui
 *
 * Dessa forma também informa a quantidade total de opções no menu
 */
#define ULTIMA_OPCAO_MENU_PRICIPAL 10

/**
 * @brief Lê uma confirmação do usuário
 *
 * @return int boolenano, 1 quando o usuário confirmou
 * 0 quando negou a operação
 * @pre stdin limpo
 * @post Nenhuma
 */
int confirm();

/**
 * @brief Responsável por controlar o menu principal
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
void controlMainMenu(char **caminho);

#endif

#ifndef CONTROLE_OPERACAO
#define CONTROLE_OPERACAO

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

#include "../models/product.h"
#include "menu.h"

void controlInsertMenu();

#endif
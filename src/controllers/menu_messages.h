#ifndef MENU_MESSAGES
#define MENU_MESSAGES

#include "../utilities/utilities.h"

/**
 * @brief Imprime um menu para pausar o programa, semelhante
 * ao system(PAUSE)
 *
 * @pre buffer stdout limpo
 * @post Nenhuma
 */
void printWaitMenu();

/**
 * @brief Imprime a mensagem que indica o encerramento do programa
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEndMessage();

#endif

/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifdef __gnu_linux__
#include <termios.h>
#include <limits.h>
#include <unistd.h>
#else
#include <conio.h>
#include <wchar.h>
#include <windows.h>
#endif

/**
 * @brief Indica qual tecla quando pressionada move a opção selecionada
 * uma para cima
 */
#define CIMA 'w'

/**
 * @brief Indica qual tecla quando pressionada move a opção selecionada
 * uma para baixo
 */
#define BAIXO 's'

char getChar();

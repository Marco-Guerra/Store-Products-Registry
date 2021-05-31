#ifndef UTILITIES
#define UTILITIES

/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#ifdef __gnu_linux__

#include <termios.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

/**
 * @brief Indica qual o valor ascii da tecla enter no sistema operacional Linux
 */
#define ENTER 10

/**
 * @brief Indica qual o comando para "limpar a tela" no sistema operacional Linux
 */
#define CLEAR "clear"

#else

#include <conio.h>
#include <wchar.h>
#include <windows.h>

/**
 * @brief Indica qual o valor ascii da tecla enter no sistema operacional Windows
 */
#define ENTER 13

/**
 * @brief Indica qual o comando para "limpar a tela" no sistema operacional Windows
 */
#define CLEAR "cls"

#endif

/**
 * @brief Indica qual tecla quando pressionada move a opção selecionada
 * uma para cima
 */
#define UP 'w'

/**
 * @brief Indica qual tecla quando pressionada move a opção selecionada
 * uma para baixo
 */
#define DOWN 's'

/**
 * @brief 
 */
#define MESSAGE_SIZE 101

/**
 * @brief Define o tamanho de uma linha do menu
 */
#define SIZE_LINE 101

/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
 */
char getChar();

/**
 * @brief Reseta a string
 * 
 * @param str ponteiro para char
 * @param size tamanho da string
 * @pre Nenhuma
 * @post string vazia
 */
void reset(char *str, int size);

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
 * @brief Imprime o cabeçalho do menu
 *
 * @param message Título do cabeçalho
 * @pre Nenhuma
 * @post Cabeçalho do menu impresso
 */
void printHead(const char *message);

/**
 * @brief Imprime mensagem
 * 
 * @param message ponteiro para char, informação impressa no menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void printString(const char* message);

/**
 * @brief Imprime uma linha com um mensagem alinhada à direita
 *
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedRight(const char *message);

/**
 * @brief Imprime uma linha com um mensagem alinhada no centro
 *
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedCenter(const char *message);

/**
 * @brief Imprime uma linha com um mensagem alinhada à esquerda
 *
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedLeft(const char *message);

/**
 * @brief Imprime uma linha separadora, preenchida com '-'
 *
 * @pre Nenhuma
 * @post Uma única linha separadora impressa no menu
 */
void printLine();

/**
 * @brief Imprime um caractere (qnt) vezes
 *
 * @param c caractere a ser impresso no Menu
 * @param number quantidade de vezes que o caractere deve ser impresso
 * @pre Nenhuma
 * @post Caractere impresso (qnt) vezes na tela
 */
void printExtended(char c, int number);

#endif

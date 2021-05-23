#ifndef MENU
#define MENU

/**
 * @file menu.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir a
 * interface com o usuário
 * @version 1
 * @date 21/05/2021
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../structs/queue.h"
#include "../models/product.h"

#ifdef __gnu_linux__
/**
 * @brief Indica qual o valor ascii da tecla enter no sistema operacional Linux
 */
#define ENTER 10

/**
 * @brief Indica qual o comando para "limpar a tela" no sistema operacional Linux
 */
#define CLEAR "clear"
#else
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
 * @brief Define o tamanho de uma linha do menu
 */
#define SIZE_LINE 101

/**
 * @brief Imprime o cabeçalho do menu
 *
 * @param message Título do cabeçalho
 * @pre Nenhuma
 * @post Cabeçalho do menu impresso
 */
void printHead(const char *message);

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
 * @brief Imprime uma linha do menu, contendo uma opção
 *
 * Sendo a opção podendo estar selecionada ou não a partir do
 * parâmetro "selecionado"
 *
 * @param message
 * @param selecionado
 * @pre Nenhuma
 * @post Nenhuma
 */
void printOption(const char* message, int selected);

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

/**
 * @brief Imprime na tela o menu principal
 *
 * @param selected inteiro correspondente a qual
 * opção está selecionada
 * @pre Nenhuma
 * @post Menu principal impresso na tela
 */
void printMainMenu(int selected);

/**
 * @brief Interface para imprimir todos os elementos da fila
 *
 * @param Queue Uma fila
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
void printQueue(Queue *queue);

/**
 * @brief Imprime recursivamente todos os elementos da fila
 *
 * @param start Primeiro elemento da fila, ou
 * em chamadas posteriores o elemento atual da impressão
 * @param end Ultimo elemento da fila
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
void printQueueTail(Node *start, Node *end);

/**
 * @brief Imprime um produto na tela
 *
 * @param product Um produto
 * @pre O Produto deve ter todos os campos inicializados
 * @post Produto impresso na tela
 */
void printProduct(Product product);

#endif

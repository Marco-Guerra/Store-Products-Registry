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

#include "fila.h"
#include "produto.h"

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
#define TAM_LINHA 101

/**
 * @brief Imprime o cabeçalho do menu
 *
 * @param mensagem Título do cabeçalho
 * @pre Nenhuma
 * @post Cabeçalho do menu impresso
 */
void printCabecalho(const char *mensagem);

/**
 * @brief Imprime uma linha com um mensagem alinhada à direita
 *
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlinhadoDireita(const char *mensagem);

/**
 * @brief Imprime uma linha com um mensagem alinhada no centro
 *
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlinhadoCentro(const char *mensagem);

/**
 * @brief Imprime uma linha com um mensagem alinhada à esquerda
 *
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlinhadoEsquerda(const char *mensagem);

/**
 * @brief Imprime uma linha do menu, contendo uma opção
 *
 * Sendo a opção podendo estar selecionada ou não a partir do
 * parâmetro "selecionado"
 *
 * @param mensagem
 * @param selecionado
 * @pre Nenhuma
 * @post Nenhuma
 */
void printOpcao(const char* mensagem, int selecionado);

/**
 * @brief Imprime uma linha separadora, preenchida com '-'
 *
 * @pre Nenhuma
 * @post Uma única linha separadora impressa no menu
 */
void printLinha();

/**
 * @brief Imprime um caractere (qnt) vezes
 *
 * @param c caractere a ser impresso no Menu
 * @param qnt quantidade de vezes que o caractere deve ser impresso
 * @pre Nenhuma
 * @post Caractere impresso (qnt) vezes na tela
 */
void printExtedido(char c, int qnt);

/**
 * @brief Imprime um menu para pausar o programa, semelhante
 * ao system(PAUSE)
 *
 * @pre buffer stdout limpo
 * @post Nenhuma
 */
void printMenuEspera();

/**
 * @brief Imprime a mensagem que indica o encerramento do programa
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
void printMensagemFinal();

/**
 * @brief Imprime na tela o menu principal
 *
 * @param escolhido inteiro correspondente a qual
 * opção está selecionada
 * @pre Nenhuma
 * @post Menu principal impresso na tela
 */
void printMenuPrincipal(int escolhido);

/**
 * @brief Interface para imprimir todos os elementos da fila
 *
 * @param f Uma fila
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
void printFila(Fila *f);

/**
 * @brief Imprime recursivamente todos os elementos da fila
 *
 * @param inicio Primeiro elemento da fila, ou
 * em chamadas posteriores o elemento atual da impressão
 * @param fim Ultimo elemento da fila
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
void printFilaCauda(No *inicio, No *fim);

/**
 * @brief Imprime um produto na tela
 *
 * @param p Um produto
 * @pre O Produto deve ter todos os campos inicializados
 * @post Produto impresso na tela
 */
void printProduto(Produto p);

#endif

#ifndef QUEUE
#define QUEUE

/**
 * @file fila.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Biblioteca responsável por definir uma fila de inteiros
 * genérica, bem como suas funções.
 *
 * Sendo essa uma lista encadeada com cabeça e cauda
 * @version 0.1
 * @date 03/05/2021
 */

#include "../utilities/utilities.h"

/**
 * @brief Estrutura que representa um único elemento da fila
 */
typedef struct queueNode {
	int position;
    int tabs;
	struct queueNode * prox;
}QueueNode;

/**
 * @brief Estrutura que representa uma Fila
 */
typedef struct {
    int size;
    struct queueNode *head;
    struct queueNode *tail;
}Queue;

/**
 * @brief Informa se a lista passada como argumento é vazia
 *
 * @param queue Uma fila
 * @return int retorno booleano 1 se a fila é vazia ou 0 caso contrário
 * @pre Nenhuma
 * @post Nenhuma
 */
int emptyQueue(Queue *queue);

/**
 * @brief Inicializa uma nova fila
 *
 * @return Fila* Uma fila inicializada
 * @pre Nenhuma
 * @post Uma nova Fila foi inicializada
 */
Queue* createQueue();

/**
 * @brief Aloca um novo elemento para a fila
 *
 * @return No* Um nó alocado na memória
 * @pre Nenhuma
 * @post Novo Nó criado
 */
QueueNode* allocQueueNode();

/**
 * @brief Retorna o tamanho da fila
 *
 * @param f Uma fila
 * @return int o tamanho da fila
 * @pre Nenhuma
 * @post Nenhuma
 */
int sizeQueue(Queue *queue);

/**
 * @brief Insere como último elemento da fila
 *
 * Mantendo o padrão primeiro a entrar, primeiro a sair (FIFO)
 * @param queue Uma fila
 * @param data o valor a ser inserido
 */
void insertQueue(Queue *queue, int position, int tabs);

/**
 * @brief Desaloca o primeiro elemento da fila
 *
 * Mantendo o padrão primeiro a entrar, primeiro a sair (FIFO)
 * @param queue Uma fila
 * @return int valor do elemento retirado
 */
int removeQueue(Queue *queue);

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
void printQueueTail(QueueNode *start, QueueNode *end);

#endif
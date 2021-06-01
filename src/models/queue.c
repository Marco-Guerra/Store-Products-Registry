/**
 * @file queue.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Biblioteca responsável por definir uma fila de inteiros
 * genérica, bem como suas funções.
 * @version 1.0
 * @date 03/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "queue.h"

/**
 * @brief Informa se a lista passada como argumento é vazia
 *
 * @param queue Uma fila
 * @return int retorno booleano 1 se a fila é vazia ou 0 caso contrário
 * @pre Nenhuma
 * @post Nenhuma
 */
int emptyQueue(Queue *queue) {
    return (queue->head == NULL);
}

/**
 * @brief Inicializa uma nova fila
 *
 * @return Fila* Uma fila inicializada
 * @pre Nenhuma
 * @post Uma nova Fila foi inicializada
 */
Queue* createQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->size = 0;
    newQueue->head = newQueue->tail = NULL;
    return newQueue;
}

/**
 * @brief Aloca um novo elemento para a fila
 *
 * @return No* Um nó alocado na memória
 * @pre Nenhuma
 * @post Novo Nó criado
 */
QueueNode* allocQueueNode() {
    return (QueueNode *)malloc(sizeof(QueueNode));
}

/**
 * @brief Retorna o tamanho da fila
 *
 * @param f Uma fila
 * @return int o tamanho da fila
 * @pre Nenhuma
 * @post Nenhuma
 */
int sizeQueue(Queue *queue) {
    return queue->size;
}

/**
 * @brief Insere como último elemento da fila
 *
 * Mantendo o padrão primeiro a entrar, primeiro a sair (FIFO)
 * @param queue Uma fila
 * @param data o valor a ser inserido
 */
void insertQueue(Queue *queue, int position, int tabs) {
    QueueNode *newTail = allocQueueNode();
    newTail->position = position;
    newTail->tabs = tabs;
    newTail->prox = NULL;
    if (emptyQueue(queue))
        queue->head = newTail;
    else
        queue->tail->prox = newTail;
    queue->size++;
    queue->tail = newTail;
}

/**
 * @brief Desaloca o primeiro elemento da fila
 *
 * Mantendo o padrão primeiro a entrar, primeiro a sair (FIFO)
 * @param queue Uma fila
 * @return int valor do elemento retirado
 */
int removeQueue(Queue * queue) {
    QueueNode *head = queue->head;
    int position = head->position;
    if (head == queue->tail)
        queue->tail = NULL;
    queue->head = queue->head->prox;
    free(head);
    queue->size--;
    return position;
}

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
void printQueue(Queue *queue) {
    printLine();
    printAlignedRight("Conteudo da Fila");
    printLine();
    if(emptyQueue(queue)) {
        printAlignedRight("[vazia]");
    }else{
        printf("|");
        printQueueTail(queue->head, queue->tail);
        printf("|\n");
    }
    printLine();
}

/**
 * @brief Imprime toda a fila de dados
 * 
 * @param start ponteiro para uma estrutura com os dados da fila
 * @param end ponteiro para uma estrutura com os dados da fila
 * @pre Nenhuma
 * @post Fila no console
 */
void printQueueTail(QueueNode *start, QueueNode *end) {
    if(start == end) {
        printf("|%d", start->position);
    }else{
        printf("|%d ", start->position);
        printQueueTail(start->prox, end);
    }
}
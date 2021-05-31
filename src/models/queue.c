/**
 * @file queue.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 03/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "queue.h"

/**
 * @brief Verifica se a fila é vazia
 * 
 * @param queue ponteiro para uma estrutura com os dados da fila
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int emptyQueue(Queue *queue) {
    return (queue->head == NULL);
}

/**
 * @brief Create a Queue object
 * 
 * @return Queue* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Queue* createQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->size = 0;
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

/**
 * @brief Aloca nó da fila
 * 
 * @return QueueNode* 
 * @pre Nenhuma
 * @post espaço alocado
 */
QueueNode* allocQueueNode() {
    return (QueueNode *)malloc(sizeof(QueueNode));
}

/**
 * @brief Tamanho da fila
 * 
 * @param queue ponteiro para uma estrutura com os dados da fila
 * @return int 
 * @pre Nenhuma
 * @post Retorna o tamanho da fila
 */
int sizeQueue(Queue *queue) {
    return queue->size;
}

/**
 * @brief Insere um novo elemento na fila
 * 
 * @param queue ponteiro para uma estrutura com os dados da fila
 * @param position inteiro com a nova posição
 * @param tabs 
 * @pre Nenhuma
 * @post Elemento inserido
 */
void insertQueue(Queue *queue, int position, int tabs) {
    QueueNode *newTail = allocQueueNode();
    newTail->position = position;
    newTail->tabs = tabs;
    newTail->prox = NULL;
    if (emptyQueue(queue)) {
        queue->head = newTail;
    }else {
        queue->tail->prox = newTail;
    }
    queue->size++;
    queue->tail = newTail;
}

/**
 * @brief Remove elemento da fila
 * 
 * @param queue ponteiro para uma estrutura com os dados da fila
 * @return int 
 * @pre Nenhuma
 * @post Elemento removido
 */
int removeQueue(Queue * queue) {
    QueueNode *head = queue->head;
    int position = head->position;
    if (head == queue->tail) {
        queue->tail = NULL;
    }
    queue->head = queue->head->prox;
    free(head);
    queue->size--;
    return position;
}

/**
 * @brief Imprime fila
 * 
 * @param queue ponteiro para uma estrutura com os dados da fila
 * @pre Nenhuma
 * @post Fila imprimida no console
 */
void printQueue(Queue *queue) {
    printLine();
    printAlignedRight("Conteudo da Fila");
    printLine();
    if (emptyQueue(queue)) {
        printAlignedRight("[vazia]");
    }else {
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
    if (start == end) {
        printf("|%d", start->position);
    }else {
        printf("|%d ", start->position);
        printQueueTail(start->prox, end);
    }
}
/**
 * @file fila.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Biblioteca responsável por implementar uma fila de inteiros genérica, bem como suas funções
 * @version 0.1
 * @date 03/05/2021
 */

#include "queue.h"

int emptyQueue(Queue *queue) {
    return (queue->head == NULL);
}

Queue* createQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->size = 0;
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

QueueNode* allocQueueNode() {
    return (QueueNode *)malloc(sizeof(QueueNode));
}

int sizeQueue(Queue *queue) {
    return queue->size;
}

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

int removeQueue(Queue * queue) {
    QueueNode *head = queue->head;
    int position = head->position;
    if (head == queue->tail) {
        queue->tail = NULL;
    }
    queue->tail = queue->tail->prox;
    free(head);
    queue->size--;
    return position;
}

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

void printQueueTail(QueueNode *start, QueueNode *end) {
    if (start == end) {
        printf("|%d", start->position);
    }else {
        printf("|%d ", start->position);
        printQueueTail(start->prox, end);
    }
}
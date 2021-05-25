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

Node* allocNode() {
    return (Node *)malloc(sizeof(Node));
}

int sizeQueue(Queue *queue) {
    return queue->size;
}

int removeQueue(Queue * queue) {
    Node *head = queue->head;
    int data = head->data;

    if (head == queue->tail) {
        queue->tail = NULL;
    }
    queue->tail = queue->tail->prox;
    free(head);
    queue->size--;

    return data;
}

void insertQueue(Queue *queue, int data) {
    Node *newTail = allocNode();
    newTail->data = data;
    newTail->prox = NULL;

    if (emptyQueue(queue)) {
        queue->head = newTail;
    }else {
        queue->tail->prox = newTail;
    }

    queue->size++;
    queue->tail = newTail;
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

void printQueueTail(Node *start, Node *end) {
    if (start == end) {
        printf("|%d", start->data);
    }else {
        printf("|%d ", start->data);
        printQueueTail(start->prox, end);
    }
}

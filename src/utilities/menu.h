#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities.h"

typedef int TypeFunct(FILE *dataFile);

typedef struct entryNode {
	char entryMessage[MESSAGE_SIZE];
    TypeFunct *funct;
	struct entryNode * prox;
}EntryNode;

typedef struct entryQueue{
    int size;
    struct entryNode *head;
    struct entryNode *tail;
}EntryQueue;

typedef struct {
    int options;
    int thisOption;
    struct entryQueue *queue;
}Menu;

EntryQueue* createEntryQueue();
EntryNode* allocEntryNode();

int emptyEntryQueue(EntryQueue *queue);
int sizeEntryQueue(EntryQueue *queue);
int removeEntryQueue(EntryQueue *queue);

void insertEntryQueue(EntryQueue *queue, char *message, TypeFunct *funct);

Menu *createMenu();
void addEntryToMenu(Menu *menu, char *message, TypeFunct *funct);
int executeEntry(EntryQueue *queue, int option, FILE *dataFile);
int controlMenu(Menu *menu, FILE *dataFile);
void printMenu(Menu *menu);

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

void printEntryQueueTail(EntryNode *start, EntryNode *end, int i);

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

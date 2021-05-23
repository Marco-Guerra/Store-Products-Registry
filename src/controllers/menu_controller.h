#ifndef MENU_CONTROLLER
#define MENU_CONTROLLER

#include "../utilities/utilities.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../views/main_menu.h"
#include "menu_controller.h"

#define MESSAGE_SIZE 101

typedef int TypeFunct();

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
void controlMenu(Menu *menu);
void printMenu(Menu *menu);

#endif

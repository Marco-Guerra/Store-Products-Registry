#include "menu_controller.h"

EntryQueue* createEntryQueue() {
    EntryQueue *newQueue = (EntryQueue *)malloc(sizeof(EntryQueue));

    newQueue->size = 0;
    newQueue->head = NULL;
    newQueue->tail = NULL;

    return newQueue;
}

EntryNode* allocEntryNode() {
    return (EntryNode *)malloc(sizeof(EntryNode));
}

int emptyEntryQueue(EntryQueue *queue) {
    return (queue->head == NULL);
}

int sizeEntryQueue(EntryQueue *queue) {
    return queue->size;
}

int removeEntryQueue(EntryQueue *queue) {
    EntryNode *head = queue->head;
    if (head == queue->tail) {
        queue->tail = NULL;
    }
    queue->tail = queue->tail->prox;
    free(head);
    queue->size--;

    return queue->size;
}

void insertEntryQueue(EntryQueue *queue, char *message, TypeFunct *funct) {
    EntryNode *newTail = allocEntryNode();
    newTail->funct = funct;
    strcpy(newTail->entryMessage, message);
    newTail->prox = NULL;

    if (emptyEntryQueue(queue)) {
        queue->head = newTail;
    }else {
        queue->tail->prox = newTail;
    }

    queue->size++;
    queue->tail = newTail;
}

void printEntryQueueTail(EntryNode *start, EntryNode *end) {
    printf("|%s", start->entryMessage);
    if (start != end) {
        printEntryQueueTail(start->prox, end);
    }
}

Menu *createMenu() {
    Menu* menu = (Menu *)malloc(sizeof(Menu));
    menu->options = 0;
    menu->thisOption = 0;
    menu->queue = createEntryQueue();
    return menu;
}

void addEntryToMenu(Menu *menu, char *message, TypeFunct *funct) {
    menu->options++;;
    insertEntryQueue(menu->queue, message, funct);
}

void controlMenu(Menu *menu) {
    char c;

    while(1) {
        printMenu(menu);

        c = getChar();
        
        if (c == UP && menu->thisOption > 0) {
            menu->thisOption--;    
        }else if (c == DOWN && menu->thisOption < menu->options) {
            menu->thisOption++;
        }else if(c == ENTER) {

        }else{

        }

    }
}

void printMenu(Menu *menu) {
    printLine();
    printAlignedRight("Conteudo da Fila");
    printLine();
    if (emptyEntryQueue(menu->queue)) {
        printAlignedRight("[vazia]");
    }else {
        printf("|");
        printEntryQueueTail(menu->queue->head, menu->queue->tail);
        printf("|\n");
    }
    printLine();
}

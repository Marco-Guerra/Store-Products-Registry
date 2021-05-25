#include "menu.h"

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

int executeEntry(EntryQueue *queue, int option) {
    int i, ret;
    EntryNode *node = queue->head;
    for(i = 0; i < option; i++)
        node = node->prox;
    return (*(node->funct))();
}

int controlMenu(Menu *menu) {
    char c;

    while(1) {
        system(CLEAR);

        printMenu(menu);

        c = getChar();
        
        if (c == UP && menu->thisOption > 0) {
            menu->thisOption--;    
        }else if (c == DOWN && menu->thisOption < menu->options - 1) {
            menu->thisOption++;
        }else if(c == ENTER) {
            if(executeEntry(menu->queue, menu->thisOption) == 0)
                return 1;
        }else{
            printLine();
            printAlignedRight("Entrada do teclado incorreta");
            printLine();
            printWaitMenu();
        }
    }
}

void printMenu(Menu *menu) {
    printLine();
    printAlignedRight(" Menu Principal");
    printLine();
    if (emptyEntryQueue(menu->queue)) {
        printAlignedRight("[vazia]");
    }else {
        printEntryQueueTail(menu->queue->head, menu->queue->tail, menu->thisOption);
    }
    printLine();
}

void printOption(const char* message, int selected) {
    printf("| [");
    if(selected) {
        printf("x");
    }else {
        printf(" ");
    }
    printf("] %s", message);
    // 6 caracteres antes da mensagem e 1 depois
    printExtended(' ', SIZE_LINE - (strlen(message) + 7));
    printf("|\n");
}

void printEntryQueueTail(EntryNode *start, EntryNode *end, int i) {
    printOption(start->entryMessage, 0 == i);
    if (start != end) {
        printEntryQueueTail(start->prox, end, --i);
    }
}

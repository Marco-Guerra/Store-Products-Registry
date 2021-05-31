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

/**
 * @brief Adiciona mais uma opção ao menu passado por parâmetro
 * 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param message informação impressa no menu, resume o que a função faz
 * @param funct função a ser executada ao selecionar o item
 * @pre Menu carregado
 * @post Mais uma função ao menu
 */
void addEntryToMenu(Menu *menu, char *message, TypeFunct *funct) {
    menu->options++;
    insertEntryQueue(menu->queue, message, funct);
}

int executeEntry(EntryQueue *queue, int option, FILE *dataFile) {
    int i, ret;
    EntryNode *node = queue->head;
    for(i = 0; i < option; i++)
        node = node->prox;
    return (*(node->funct))(dataFile);
}

/**
 * @brief Realiza o controle de um menu previamente criado
 * 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int (ver se não é void)
 * @pre todas as informações do menu previamente carregadas e 
 * ponteiro para arquivo aberto
 * @post o menu chamado será executado, bem como a função selecionada
 */
int controlMenu(Menu *menu, FILE *dataFile) {
    char c;

    while(1) {
        system(CLEAR);

        printMenu(menu);

        c = getChar();
        
        if (c == UP) {
            if(menu->thisOption > 0)
                menu->thisOption--;    
            else
                menu->thisOption = menu->options - 1;
        }else if (c == DOWN) {
            if(menu->thisOption < menu->options - 1)
                menu->thisOption++;    
            else
                menu->thisOption = 0;
        }else if(c == ENTER) {
            if(executeEntry(menu->queue, menu->thisOption, dataFile) == 0)
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
    printAlignedCenter(" Menu Principal");
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

void printWaitMenu() {
    printLine();
    // imprime uma linha em branco
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Pressione [Enter] para continuar");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
    getchar();
}

void printEndMessage() {
    system(CLEAR);
    printLine();
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Programa finalizado com sucesso");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
}

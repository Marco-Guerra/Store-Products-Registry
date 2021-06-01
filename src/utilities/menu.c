/**
 * @file menu.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 31/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "menu.h"

/**
 * @brief Create a Entry Queue object
 * 
 * @return EntryQueue* 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryQueue* createEntryQueue() {
    EntryQueue *newQueue = (EntryQueue *)malloc(sizeof(EntryQueue));
    newQueue->head = newQueue->tail = NULL;
    newQueue->size = 0;
    return newQueue;
}

/**
 * @brief Aloca a estrutura EntryNode
 * 
 * @return EntryNode* 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryNode* allocEntryNode() {
    return (EntryNode *)malloc(sizeof(EntryNode));
}

/**
 * @brief Informa se a lista passada como argumento é vazia
 * 
 * @param queue Uma fila
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int emptyEntryQueue(EntryQueue *queue) {
    return (queue->head == NULL);
}

/**
 * @brief Devolve o tamanho da fila
 * 
 * @param queue ponteiro para uma estrutura que contém as informações de uma fila
 * @return int 
 * @pre Nenhuma
 * @post Retorna o valor do tamanho da fila
 */
int sizeEntryQueue(EntryQueue *queue) {
    return queue->size;
}

/**
 * @brief Remove um dos itens do menu
 * 
 * @param queue ponteiro para uma estrutura que contém as informações de uma fila
 * @return int 
 * @pre Nenhuma
 * @post Retorna o valor do tamanho da fila reduzido
 */
int removeEntryQueue(EntryQueue *queue) {
    EntryNode *head = queue->head;
    if (head == queue->tail)
        queue->tail = NULL;
    queue->tail = queue->tail->prox;
    free(head);
    return --queue->size;
}

/**
 * @brief Insere um novo elemento na fila
 * 
 * @param queue ponteiro para uma estrutura que contém as 
 * informações de uma fila
 * @param message informação impressa no menu, resume o que a função faz
 * @param funct função a ser executada ao selecionar o item
 * @pre Nenhuma
 * @post Nenhuma
 */
void insertEntryQueue(EntryQueue *queue, char *message, TypeFunct *funct) {
    EntryNode *newTail = allocEntryNode();
    newTail->funct = funct;
    strcpy(newTail->entryMessage, message);
    newTail->prox = NULL;
    if (emptyEntryQueue(queue))
        queue->head = newTail;
    else
        queue->tail->prox = newTail;
    queue->size++;
    queue->tail = newTail;
}

/**
 * @brief Create a Menu object
 * 
 * @return Menu* 
 * @pre Nenhuma
 * @post Menu criado
 */
Menu *createMenu() {
    Menu* menu = (Menu *)malloc(sizeof(Menu));
    menu->options = menu->thisOption = 0;
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

/**
 * @brief Executa a opção selecionada
 * 
 * @param queue ponteiro para uma estrutura que contém as 
 * informações de uma fila
 * @param option inteiro com a opcao escolhida
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int 
 * @pre Nenhuma
 * @post retorna funct da opção
 */
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

/**
 * @brief printa o menu principal
 * 
 * @param menu ponteiro para uma estrutura que contém as informações de um menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void printMenu(Menu *menu) {
    printLine();
    printAlignedCenter(" Menu Principal");
    printLine();
    if(emptyEntryQueue(menu->queue))
        printAlignedRight("[vazia]");
    else
        printEntryQueueTail(menu->queue->head, menu->queue->tail, menu->thisOption);
    printLine();
}

/**
 * @brief Selecionar a opção desejada
 * 
 * @param message informação impressa no menu, resume o que a função faz
 * @param selected inteiro que define a opção selecionada ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
void printOption(const char* message, int selected) {
    printf("| [");
    if(selected)
        printf("x");
    else
        printf(" ");
    printf("] %s", message);
    printExtended(' ', SIZE_LINE - (strlen(message) + 7)); // 6 caracteres antes da mensagem e 1 depois
    printf("|\n");
}

/**
 * @brief Printa todas as opçoes 
 * 
 * @param start ponteiro para uma estrutura que contém as informações do nó de entrada 
 * @param end ponteiro para uma estrutura que contém as informações do nó de entrada 
 * @param i inteiro utilizado para passar pela fila
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEntryQueueTail(EntryNode *start, EntryNode *end, int i) {
    printOption(start->entryMessage, 0 == i);
    if (start != end)
        printEntryQueueTail(start->prox, end, --i);
}

/**
 * @brief Imprime um menu para pausar o programa
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printWaitMenu() {
    printLine();
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Pressione [Enter] para continuar");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
    getchar();
}

/**
 * @brief Imprime a mensagem que indica o encerramento do programa
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
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

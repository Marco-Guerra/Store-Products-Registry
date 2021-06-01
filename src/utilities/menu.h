#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities.h"

/**
 * @brief Ponteiro para uma função chamada pelo menu
 */
typedef int TypeFunct(FILE *dataFile);

/**
 * @brief Estrutura nó para os itens da fila entryQueue dentro do Menu
 */
typedef struct entryNode {
	char entryMessage[MESSAGE_SIZE];
    TypeFunct *funct;
	struct entryNode * prox;
}EntryNode;

/**
 * @brief Estrutura para fila, implementada como uma
 * lista encadeada com cabeça e cauda
 */
typedef struct entryQueue{
    int size;
    struct entryNode *head;
    struct entryNode *tail;
}EntryQueue;

/**
 * @brief estrutura para fila de itens do menu
 */
typedef struct {
    int options;
    int thisOption;
    struct entryQueue *queue;
}Menu;

/**
 * @brief Create a Entry Queue object
 * 
 * @return EntryQueue* 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryQueue* createEntryQueue();

/**
 * @brief Aloca a estrutura EntryNode
 * 
 * @return EntryNode* 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryNode* allocEntryNode();

/**
 * @brief Informa se a lista passada como argumento é vazia
 * 
 * @param queue Uma fila
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int emptyEntryQueue(EntryQueue *queue);

/**
 * @brief Devolve o tamanho da fila
 * 
 * @param queue ponteiro para uma estrutura que contém as informações de uma fila
 * @return int 
 * @pre Nenhuma
 * @post Retorna o valor do tamanho da fila
 */
int sizeEntryQueue(EntryQueue *queue);

/**
 * @brief Remove um dos itens do menu
 * 
 * @param queue ponteiro para uma estrutura que contém as informações de uma fila
 * @return int 
 * @pre Nenhuma
 * @post Retorna o valor do tamanho da fila reduzido
 */
int removeEntryQueue(EntryQueue *queue);

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
void insertEntryQueue(EntryQueue *queue, char *message, TypeFunct *funct);

/**
 * @brief Create a Menu object
 * 
 * @return Menu* 
 * @pre Nenhuma
 * @post Menu criado
 */
Menu *createMenu();

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
void addEntryToMenu(Menu *menu, char *message, TypeFunct *funct);


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
int executeEntry(EntryQueue *queue, int option, FILE *dataFile);

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
int controlMenu(Menu *menu, FILE *dataFile);

/**
 * @brief printa o menu principal
 * 
 * @param menu ponteiro para uma estrutura que contém as informações de um menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void printMenu(Menu *menu);

/**
 * @brief Selecionar a opção desejada
 * 
 * @param message informação impressa no menu, resume o que a função faz
 * @param selected inteiro que define a opção selecionada ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
void printOption(const char* message, int selected);

/**
 * @brief Printa todas as opçoes 
 * 
 * @param start ponteiro para uma estrutura que contém as informações do nó de entrada 
 * @param end ponteiro para uma estrutura que contém as informações do nó de entrada 
 * @param i inteiro utilizado para passar pela fila
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEntryQueueTail(EntryNode *start, EntryNode *end, int i);

/**
 * @brief Imprime um menu para pausar o programa
 * 
 * @pre Nenhuma
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

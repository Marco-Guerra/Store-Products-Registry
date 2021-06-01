#ifndef TREE
#define TREE

#include "../utilities/utilities.h"
#include "queue.h"
#include "product.h"

/**
 * @brief Estrutura de cabeçalho de um arquivo
 */
typedef struct {
    int regRoot;
    int regLast;
    int regFree;
}Head;

/**
 * @brief Estrutura que representa um único nó
 * da arvore binária implementada em arquivo
 */
typedef struct node {
    Product product;
    int rChild;
    int lChild;
}Node;

/**
 * @brief Offsets para acessar determinados campos do cabeçaçho
 */
enum headData {OFFSET_REG_ROOT, OFFSET_REG_LAST, OFFSET_REG_FREE};

/**
 * @brief Offsets para acessar determinados campos do nó do Product
 */
enum nodeData {
    OFFSET_NODE_CODE = 0,
    OFFSET_NODE_RIGHT = sizeof(Product),
    OFFSET_NODE_LEFT = OFFSET_NODE_RIGHT + sizeof(int)
};

/**
 * @brief aloca um nó da arvore zerado
 * 
 * @return Node* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Node *allocNode();

/**
 * @brief Verifica se a arvore está vazia
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmpty(FILE *dataFile);

/**
 * @brief Escreve o cabeçalho do arquivo
 * 
 * @param head 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeHead(Head *head, FILE *dataFile);

/**
 * @brief Lê o cabeçalho do arquivo
 * 
 * @param dataFile 
 * @return Head* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Head *readHead(FILE *dataFile);

/**
 * @brief Escreve o um campo do cabeçalho do arquivo
 * 
 * @param value 
 * @param headData 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeHeadField(int value, int headData, FILE *dataFile);

/**
 * @brief Lê o um campo do cabeçalho do arquivo
 * 
 * @param headData 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readHeadField(int headData, FILE *dataFile);

/**
 * @brief Escreve o um campo do nó da arvore no arquivo
 * 
 * @param value 
 * @param nodeData 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeNodeField(int value, int nodeData, int position, FILE *dataFile);

/**
 * @brief Lê o um campo do nó da arvore no arquivo
 * 
 * @param nodeData 
 * @param position 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readNodeField(int nodeData, int position, FILE *dataFile);

/**
 * @brief 
 * @brief Lê o produto de um nó da arvore no arquivo
 * 
 * @param dataFile 
 * @param position 
 * @return Product* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Product* readNodeProduct(FILE *dataFile, int position);

/**
 * @brief Cria o Arquivo binário se ele não existe
 * 
 * @param filePath 
 * @return FILE* 
 * @pre Nenhuma
 * @post Nenhuma
 */
FILE *makeDataFile(char *filePath);

/**
 * @brief Escreve um nó
 * 
 * @param dataFile 
 * @param node 
 * @param position 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int writeNode(FILE *dataFile, Node *node, int position);

/**
 * @brief Cria um nó da arvore a partir de um produto
 * 
 * @param product 
 * @param rChild 
 * @param lChild 
 * @return Node* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Node *makeNode(Product *product, int rChild, int lChild);

/**
 * @brief Lê um nó do arquivo
 * 
 * @param dataFile 
 * @param position 
 * @return Node* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Node *readNode(FILE *dataFile, int position);

/**
 * @brief Insere um nó do arquivo
 * 
 * @param dataFile 
 * @param node 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int insertNode(FILE *dataFile, Node *node);

/**
 * @brief Remove um nó do arquivo
 * 
 * @param dataFile 
 * @param position 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int removeNode(FILE *dataFile, int position);

/**
 * @brief Chama a função que imprime a arvore caso ela não seja vazia
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printInOrder(FILE *dataFile);

/**
 * @brief Imprime em ordem crescende de código a arvore
 * 
 * @param dataFile 
 * @param this 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printInOrderRec(FILE *dataFile, int this);

/**
 * @brief Imprime a arvore em níveis
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printByLevel(FILE *dataFile);

/**
 * @brief Tenta imprimir no menu todas as posições livres
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printFree(FILE *dataFile);

/**
 * @brief Imprime no menu todas as posições livres
 * 
 * @param dataFile 
 * @param this 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printFreeRec(FILE *dataFile, int this);

#endif

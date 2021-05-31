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

Node *allocNode();

int isEmpty(FILE *dataFile);

void writeHead(Head *head, FILE *dataFile);

Head *readHead(FILE *dataFile);

void writeHeadField(int value, int headData, FILE *dataFile);

int readHeadField(int headData, FILE *dataFile);

void writeNodeField(int value, int nodeData, int position, FILE *dataFile);

int readNodeField(int nodeData, int position, FILE *dataFile);

Product* readNodeProduct(FILE *dataFile, int position);

FILE *makeDataFile(char *filePath);

int writeNode(FILE *dataFile, Node *node, int position);

Node *makeNode(Product *product, int rChild, int lChild);

Node* readNode(FILE *dataFile, int position);

int insertNode(FILE *dataFile, Node *node);

int removeNode(FILE *dataFile, int position);

void printInOrder(FILE *dataFile);

void printInOrderRec(FILE *dataFile, int this);

void printByLevel(FILE *dataFile);

void printFree(FILE *dataFile);

void printFreeRec(FILE *dataFile, int this);

#endif

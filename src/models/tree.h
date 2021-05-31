#ifndef TREE
#define TREE

#include "../utilities/utilities.h"
#include "product.h"

typedef struct {
    int regRoot;
    int regLast;
    int regFree;
}Head;

typedef struct node {
    Product product;
    int rChild;
    int lChild;
}Node;

enum headData {OFFSET_REG_ROOT, OFFSET_REG_LAST, OFFSET_REG_FREE};

enum nodeData {
    OFFSET_NODE_CODE = 0,
    OFFSET_NODE_RIGHT = sizeof(Product),
    OFFSET_NODE_LEFT = OFFSET_NODE_RIGHT + sizeof(int)
};

Node *allocNode();

void writeHead(Head *head, FILE *dataFile);

Head *readHead(FILE *dataFile);

void writeHeadField(int value, int headData, FILE *dataFile);

int readHeadField(int headData, FILE *dataFile);

void writeNodeField(int value, int nodeData, int position, FILE *dataFile);

int readNodeField(int nodeData, int position, FILE *dataFile);

FILE *makeDataFile(char *filePath);

int writeNode(FILE *dataFile, Node *node, int position);

Node *makeNode(Product *product, int rChild, int lChild);

Node* readNode(FILE *dataFile, int position);

int insertNode(FILE *dataFile, Node *node);

int removeNode(FILE *dataFile, int position);

#endif

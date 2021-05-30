#include "tree.h"

Node *allocNode() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->product.code = 0;
    reset(node->product.name, MAX_NAME);
    node->product.number = 0;
    node->product.value = 0;
    reset(node->product.local, MAX_LOCAL);
    node->rChild = -1;
    node->lChild = -1;
    return node;
}

void writeHead(Head *head, FILE *dataFile) {
    fseek(dataFile, 0, SEEK_SET);
    fwrite(head, sizeof(Head), 1, dataFile);
}

Head *readHead(FILE *dataFile) {
    Head *head = (Head*) malloc(sizeof(Head));
    fseek(dataFile, 0, SEEK_SET);
    fread(head, sizeof(Head), 1, dataFile);
    return head;
}

void writeHeadField(int regRoot, int headData, FILE *dataFile) {
    fseek(dataFile, sizeof(int) * headData, SEEK_SET);
    fwrite(&regRoot, sizeof(int), 1, dataFile);
}

int readHeadField(int headData, FILE *dataFile) {
    int regRoot;
    fseek(dataFile, sizeof(int) * headData, SEEK_SET);
    fread(&regRoot, sizeof(int), 1, dataFile);
    return regRoot;
}

void writeNodeField(int value, int nodeData, int position, FILE *dataFile) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node) + nodeData, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

int readNodeField(int nodeData, int position, FILE *dataFile) {
    int value;
    fseek(dataFile, sizeof(Head) + position * sizeof(Node) + nodeData, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}

FILE *makeDataFile(char *filePath) {
    FILE *dataFile = fopen(filePath, "w+b");
    setbuf(dataFile, NULL);
    Head head;
    head.regRoot = -1;
    head.regLast = 0;
    head.regFree = -1;
    writeHead(&head, dataFile);
    return dataFile;
}

int writeNode(FILE *dataFile, Node *node, int position) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fwrite(node, sizeof(Node), 1, dataFile);
    return position;
}

Node *makeNode(Product *product, int rChild, int lChild) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->product = (*product);
    node->rChild = rChild;
    node->lChild = lChild;
    return node;
}

Node *readNode(FILE *dataFile, int position) {
    Node *node = (Node*)malloc(sizeof(Node));
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fread(node, sizeof(Node), 1, dataFile);
    return node;
}

int insertNode(FILE *dataFile, Node *node) {
    int position = readHeadField(OFFSET_REG_FREE, dataFile);
    if(position == -1) {
        writeHeadField(
            (position = readHeadField(OFFSET_REG_LAST, dataFile)) + 1, 
            OFFSET_REG_LAST, 
            dataFile
        );
    }else{
        writeHeadField(
            readNodeField(OFFSET_NODE_RIGHT, position, dataFile), 
            OFFSET_REG_FREE, 
            dataFile
        );
    }
    return writeNode(dataFile, node, position);
}

int removeNode(FILE *dataFile, int position) {
    Node *node = allocNode();
    Head *head = readHead(dataFile);
    node->rChild = head->regFree;
    head->regFree = position;
    writeHead(head, dataFile);
    writeNode(dataFile, node, position);
    free(node);
    free(head);
    return 0;
}

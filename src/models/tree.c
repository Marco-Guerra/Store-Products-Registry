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

int isEmpty(FILE *dataFile) {
    return readHeadField(OFFSET_REG_ROOT, dataFile) == -1;
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

void writeHeadField(int value, int headData, FILE *dataFile) {
    fseek(dataFile, sizeof(int) * headData, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

int readHeadField(int headData, FILE *dataFile) {
    int value;
    fseek(dataFile, sizeof(int) * headData, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
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

Product* readNodeProduct(FILE *dataFile, int position) {
    Product *product = (Product *)malloc(sizeof(Product));
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fread(product, sizeof(Product), 1, dataFile);
    return product;
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
    node->rChild = readHeadField(OFFSET_REG_FREE, dataFile);
    writeHeadField(position, OFFSET_REG_FREE, dataFile);
    writeNode(dataFile, node, position);
    free(node);
    return 0;
}

void printInOrder(FILE *dataFile) {
    if (isEmpty(dataFile))
        printf("Arvore vazia.\n");
    else
        printInOrderRec(dataFile, readHeadField(OFFSET_REG_ROOT, dataFile));
}

void printInOrderRec(FILE *dataFile, int this) {
    if (this == -1)
        return;
    printInOrderRec(dataFile, readNodeField(OFFSET_NODE_LEFT, this, dataFile));
    Product *product = readNodeProduct(dataFile, this);
    printBasicProduct(product);
    free(product);
    printInOrderRec(dataFile, readNodeField(OFFSET_NODE_RIGHT, this, dataFile));
}

void printByLevel(FILE *dataFile) {
    if(isEmpty(dataFile)) {
        printf("Arvore vazia.\n");
        return;
    }
    int next = readHeadField(OFFSET_REG_ROOT, dataFile);
    Queue *queue = createQueue();
    insertQueue(queue, next, 1);
    int previous_height = 0;
    int current_height;
    Product *product;
    int read;
    while(!emptyQueue(queue)) {
        current_height = queue->head->tabs;
        next = removeQueue(queue);
        if(previous_height < current_height) {
            previous_height = current_height;
            printf("\n");
        }
        product = readNodeProduct(dataFile, next);
        printBasicProduct(product);
        free(product);
        if((read = readNodeField(OFFSET_NODE_LEFT, next, dataFile)) != -1)
            insertQueue(queue, read, ++current_height);
        if((read = readNodeField(OFFSET_NODE_RIGHT, next, dataFile)) != -1)
            insertQueue(queue, read, ++current_height);
    }
}

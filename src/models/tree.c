/**
 * @file tree.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 31/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "tree.h"

/**
 * @brief 
 * 
 * @return Node* 
 * @pre Nenhuma
 * @post Nenhuma
 */
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

/**
 * @brief 
 * 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmpty(FILE *dataFile) {
    return readHeadField(OFFSET_REG_ROOT, dataFile) == -1;
}

/**
 * @brief 
 * 
 * @param head 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeHead(Head *head, FILE *dataFile) {
    fseek(dataFile, 0, SEEK_SET);
    fwrite(head, sizeof(Head), 1, dataFile);
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @return Head* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Head *readHead(FILE *dataFile) {
    Head *head = (Head*) malloc(sizeof(Head));
    fseek(dataFile, 0, SEEK_SET);
    fread(head, sizeof(Head), 1, dataFile);
    return head;
}

/**
 * @brief 
 * 
 * @param value 
 * @param headData 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeHeadField(int value, int headData, FILE *dataFile) {
    fseek(dataFile, sizeof(int) * headData, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

/**
 * @brief 
 * 
 * @param headData 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readHeadField(int headData, FILE *dataFile) {
    int value;
    fseek(dataFile, sizeof(int) * headData, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}

/**
 * @brief 
 * 
 * @param value 
 * @param nodeData 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeNodeField(int value, int nodeData, int position, FILE *dataFile) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node) + nodeData, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

/**
 * @brief 
 * 
 * @param nodeData 
 * @param position 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readNodeField(int nodeData, int position, FILE *dataFile) {
    int value;
    fseek(dataFile, sizeof(Head) + position * sizeof(Node) + nodeData, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param position 
 * @return Product* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Product* readNodeProduct(FILE *dataFile, int position) {
    Product *product = (Product *)malloc(sizeof(Product));
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fread(product, sizeof(Product), 1, dataFile);
    return product;
}

/**
 * @brief 
 * 
 * @param filePath 
 * @return FILE* 
 * @pre Nenhuma
 * @post Nenhuma
 */
FILE *makeDataFile(char *filePath) {
    FILE *dataFile = fopen(filePath, "w+b");
    setbuf(dataFile, NULL);
    Head head;
    head.regRoot = head.regFree = -1;
    head.regLast = 0;
    writeHead(&head, dataFile);
    return dataFile;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param node 
 * @param position 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int writeNode(FILE *dataFile, Node *node, int position) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fwrite(node, sizeof(Node), 1, dataFile);
    return position;
}

/**
 * @brief 
 * 
 * @param product 
 * @param rChild 
 * @param lChild 
 * @return Node* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Node *makeNode(Product *product, int rChild, int lChild) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->product = (*product);
    node->rChild = rChild;
    node->lChild = lChild;
    return node;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param position 
 * @return Node* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Node *readNode(FILE *dataFile, int position) {
    Node *node = (Node*)malloc(sizeof(Node));
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fread(node, sizeof(Node), 1, dataFile);
    return node;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param node 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
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

/**
 * @brief 
 * 
 * @param dataFile 
 * @param position 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int removeNode(FILE *dataFile, int position) {
    Node *node = allocNode();
    node->rChild = readHeadField(OFFSET_REG_FREE, dataFile);
    writeHeadField(position, OFFSET_REG_FREE, dataFile);
    writeNode(dataFile, node, position);
    free(node);
    return 0;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printInOrder(FILE *dataFile) {
    if (isEmpty(dataFile))
        printAlignedCenter("Arvore vazia.");
    else
        printInOrderRec(dataFile, readHeadField(OFFSET_REG_ROOT, dataFile));
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param this 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printInOrderRec(FILE *dataFile, int this) {
    if (this == -1)
        return;
    printInOrderRec(
        dataFile,
        readNodeField(OFFSET_NODE_LEFT, this, dataFile)
    );
    Product *product;
    printBasicProduct(product = readNodeProduct(dataFile, this));
    free(product);
    printInOrderRec(
        dataFile,
        readNodeField(OFFSET_NODE_RIGHT, this, dataFile)
    );
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printByLevel(FILE *dataFile) {
    if(isEmpty(dataFile)) {
        printAlignedCenter("Arvore vazia.");
        return;
    }
    int next = readHeadField(OFFSET_REG_ROOT, dataFile);
    Queue *queue = createQueue();
    insertQueue(queue, next, 1);
    int previous_height = 0;
    int current_height;
    int read;
    while(!emptyQueue(queue)) {
        current_height = queue->head->tabs;
        next = removeQueue(queue);
        if(previous_height < current_height) {
            previous_height = current_height;
            printf("\n\tNivel %d: ", current_height);
        }
        printf("/t%d", readNodeField(OFFSET_NODE_CODE, next, dataFile));
        if((read = readNodeField(OFFSET_NODE_LEFT, next, dataFile)) != -1)
            insertQueue(queue, read, current_height + 1);
        if((read = readNodeField(OFFSET_NODE_RIGHT, next, dataFile)) != -1)
            insertQueue(queue, read, current_height + 1);
    }
    printf("\n\n");
}

/**
 * @brief Imprime no menu todas as posições livres
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printFree(FILE *dataFile) {
    printFreeRec(
        dataFile,
        readHeadField(OFFSET_REG_FREE, dataFile)
    );
}

void printFreeRec(FILE *dataFile, int this) {
    if (this == -1)
        return ;
    char *buffer = malloc(sizeof(char) * 21); // maior inteiro de 8 bytes
    sprintf(buffer, "%d", this);
    printAlignedLeft(buffer);
    free(buffer);
    printFreeRec(
        dataFile,
        readNodeField(OFFSET_NODE_RIGHT, this, dataFile)
    );
}
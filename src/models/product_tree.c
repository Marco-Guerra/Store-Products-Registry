/**
 * @file produto.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as operações sobre um único produto do estoque
 * @version 0.1
 * @date 03/05/2021
 */
 
#include "product_tree.h"

Product *allocProduct() {
    Product *product = (Product *)malloc(sizeof(Product));
    product->code = 0;
    reset(product->name, MAX_NAME);
    product->number = 0;
    product->value = 0;
    reset(product->local, MAX_LOCAL);
    return product;
}

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

FILE *makeDataFile(char *filePath) {
    FILE *dataFile = fopen(filePath, "wb");
    Head head;
    head.regRoot = -1;
    head.regLast = 0;
    head.regFree = -1;
    writeHead(&head, dataFile);
    return dataFile;
}

void writeNode(FILE *dataFile, Node *node, int position) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fwrite(node, sizeof(Node), 1, dataFile);
}

Node *makeNode(Product *product, int rChild, int lChild) {
    Node *node = (Node*)malloc(sizeof(Node));
    memcpy(product, &(node->product), sizeof(Product));
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
    Head *head = readHead(dataFile);
    int position;
    if(head->regFree == -1) {
        position = head->regLast;
        head->regLast++;
    }else{
        position = head->regFree;
        Node *fileNode = readNode(dataFile, position);
        head->regFree = fileNode->rChild;
        free(fileNode);
    }
    writeNode(dataFile, node, position);
    writeHead(head, dataFile);
    free(head);
    return position;
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

int maximum(FILE *dataFile){
    Head *head = readHead(dataFile);
    int position = head->regRoot;
    free(head);
    if(position == -1)
        return -1;
    Node *node;
    while(position != -1) {
        node = readNode(dataFile, position);
        position = node->rChild;
        free(node);
    }
    return position;
}

int minimum(FILE *dataFile){
    Head *head = readHead(dataFile);
    int position = head->regRoot;
    free(head);
    if(position == -1)
        return -1;
    Node *node;
    while(position != -1) {
        node = readNode(dataFile, position);
        position = node->lChild;
        free(node);
    }
    return position;
}

int insertProduct(FILE *dataFile, Product *product) {
    Head *head = readHead(dataFile);
    int regRoot;
    if(head->regRoot == -1) {
        Node *node = makeNode(product, -1, -1);
        regRoot = head->regRoot = insertNode(dataFile, node);  
        writeHead(head, dataFile);
        free(head);
        free(node);
    }else{
        regRoot = head->regRoot;
        free(head);
        regRoot = insertProductRec(dataFile, regRoot, product);
    }
    return regRoot;
}

int insertProductRec(FILE *dataFile, int this, Product *product) {
    Node *node = readNode(dataFile, this);
    if(product->code < node->product.code) {
        if(node->lChild == -1) {
            Node *newNode = makeNode(product, -1, -1);
            int new = node->lChild = insertNode(dataFile, newNode);
            writeNode(dataFile, node, this);
            free(newNode);
            free(node);
            return new;
        }
        this = node->lChild;
    }else{
        if(node->rChild == -1) {
            Node *newNode = makeNode(product, -1, -1);
            int new = node->rChild = insertNode(dataFile, newNode);
            writeNode(dataFile, node, this);
            free(newNode);
            free(node);
            return new;
        }
        this = node->rChild;
    }
    free(node);
    return insertProductRec(dataFile, this, product);
}

int removeProduct(FILE *dataFile, int code) {
    Head *head = readHead(dataFile);
    int regRoot = 0;
    if(head->regRoot == -1) {
        return -1;
    }else{
        return 0;//removeProductRec(dataFile, this, code);
    }
}

int removeProductRec(FILE *dataFile, int this, int code) {

}

int searchProductByCode(FILE *dataFile, int code) {
    Head *head = readHead(dataFile);
    int regRoot = head->regRoot;
    free(head);
    return searchProductByCodeRec(dataFile, regRoot, code);
}

int searchProductByCodeRec(FILE *dataFile, int this, int code) {
    if(this == -1)
        return -1;
    Node *node = readNode(dataFile, this);
    int thisCode = node->product.code;
    int rChild = node->rChild;
    int lChild = node->lChild;
    free(node);
    if(thisCode > code)
        return searchProductByCodeRec(dataFile, lChild, code);
    if(thisCode < code)
        return searchProductByCodeRec(dataFile, rChild, code);
    return this;
}

int searchProductByName(FILE *dataFile, char *name) {
    Head *head = readHead(dataFile);
    int regRoot = head->regRoot;
    free(head);
    return searchProductByNameRec(dataFile, regRoot, name);
}

int searchProductByNameRec(FILE *dataFile, int this, char *name) {
    if(this == -1)
        return -1;
    Node *node = readNode(dataFile, this);
    int rChild = node->rChild;
    int lChild = node->lChild;
    free(node);
    if(strcmp(name, node->product.name) == 0)
        return this;
    return searchProductByNameRec(dataFile, lChild, name) + searchProductByNameRec(dataFile, rChild, name) + 1;
}

void printProduct(Product *product) {
    printf("\nNome: %s.\n", product->name);
    printf("Code: %d.\n", product->code);
    printf("Number: %d.\n", product->number);
    printf("Value: %f.\n", product->value);
    printf("Local: %s.\n\n", product->local);
}

Product* scanProduct() {
    Product* product = (Product *)malloc(sizeof(Product));
    printf("\nNome: ");
    scanf("%[^\n]%*c", product->name);
    printf("Code: ");
    scanf("%d", &product->code);
    printf("Number: ");
    scanf("%d", &product->number);
    printf("Value: ");
    scanf("%f%*c", &product->value);
    printf("Local: ");
    scanf("%[^\n]%*c", product->local);
    return product;
}

#include "product_tree.h"

int maximum(FILE *dataFile, int this){
    if (this == -1) return -1;
    int position;
    while ((position = readNodeField(OFFSET_NODE_RIGHT, this, dataFile)) != -1)
        this = position;
    return this;
}

int minimum(FILE *dataFile, int this){
    if (this == -1) return -1;
    int position;
    while ((position = readNodeField(OFFSET_NODE_LEFT, this, dataFile)) != -1)
        this = position;
    return this;
}

int insertProduct(FILE *dataFile, Product *product) {
    int regRoot = readHeadField(OFFSET_REG_ROOT, dataFile);
    if(regRoot == -1) {
        Node *node = makeNode(product, -1, -1);
        regRoot = insertNode(dataFile, node);
        writeHeadField(regRoot, OFFSET_REG_ROOT, dataFile);
        free(node);
    }else{
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

int updateProduct(FILE *dataFile, int position, Product *product) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fwrite(product, sizeof(Product), 1, dataFile);
    return position;
}

int removeProduct(FILE *dataFile, int code) {
    if (isEmpty(dataFile))
        return -1;
    return removeProductRec(dataFile,
                            readHeadField(OFFSET_REG_ROOT, dataFile),
                            code);
}

int removeProductRec(FILE *dataFile, int this, int code) {
    if (this == -1) return -1;
    int thisCode = readNodeField(OFFSET_NODE_CODE, this, dataFile);
    int leftChild = readNodeField(OFFSET_NODE_LEFT, this, dataFile);
    int rightChild = readNodeField(OFFSET_NODE_RIGHT, this, dataFile);
    if (code < thisCode) {
        leftChild = removeProductRec(dataFile, leftChild, code);
    } else if (code > thisCode) {
        rightChild = removeProductRec(dataFile, rightChild,  code);
    } else {
        if (leftChild == -1 && rightChild == -1) {
            removeNode(dataFile, this);
            this = leftChild = rightChild = -1;
        } else if (leftChild == -1) {
            thisCode = minimum(dataFile, rightChild);
            rightChild = removeProductRec(dataFile, rightChild, thisCode);
        } else {
            thisCode = maximum(dataFile, leftChild);
            leftChild = removeProductRec(dataFile, leftChild, thisCode);
        }
    }
    if (this != -1) {
        writeNodeField(rightChild, OFFSET_NODE_RIGHT, this, dataFile);
        writeNodeField(leftChild, OFFSET_NODE_LEFT, this, dataFile);
    }
    return this;
}

int searchProductByCode(FILE *dataFile, int code) {
    return searchProductByCodeRec(dataFile, readHeadField(OFFSET_REG_ROOT, dataFile), code);
}

int searchProductByCodeRec(FILE *dataFile, int this, int code) {
    if (this == -1) return -1;
    int thisCode = readNodeField(OFFSET_NODE_CODE, this, dataFile);
    if (thisCode > code) return searchProductByCodeRec(dataFile, readNodeField(OFFSET_NODE_LEFT, this, dataFile), code);
    if (thisCode < code) return searchProductByCodeRec(dataFile, readNodeField(OFFSET_NODE_RIGHT, this, dataFile), code);
    return this;
}

int searchProductByName(FILE *dataFile, char *name) {
    Head *head = readHead(dataFile);
    int regRoot = head->regRoot;
    free(head);
    return searchProductByNameRec(dataFile, regRoot, name);
}

int searchProductByNameRec(FILE *dataFile, int this, char *name) {
    if (this == -1) return -1;
    Node *node = readNode(dataFile, this);
    int rChild = node->rChild;
    int lChild = node->lChild;
    free(node);
    if (strcmp(name, node->product.name) == 0) return this;
    return searchProductByNameRec(dataFile, lChild, name) +
           searchProductByNameRec(dataFile, rChild, name) + 1;
}
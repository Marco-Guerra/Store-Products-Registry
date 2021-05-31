#include "product_tree.h"

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

int minimum(FILE *dataFile){ ////////////////////////////// <- volta aqui
    int position = readHeadField(OFFSET_REG_ROOT, dataFile);
    if(position == -1)
        return -1;
    while(position != -1) {
        position = readNodeField(OFFSET_NODE_LEFT, position, dataFile);
    }
    return position;
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

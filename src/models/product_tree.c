/**
 * @file product_tree.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 31/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "product_tree.h"

/**
 * @brief 
 * 
 * @param dataFile 
 * @param this 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int maximum(FILE *dataFile, int this){
    if (this == -1) return -1;
    int position;
    while ((position = readNodeField(OFFSET_NODE_RIGHT, this, dataFile)) != -1)
        this = position;
    return this;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param this 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int minimum(FILE *dataFile, int this){
    if (this == -1) return -1;
    int position;
    while ((position = readNodeField(OFFSET_NODE_LEFT, this, dataFile)) != -1)
        this = position;
    return this;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param product 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int insertProduct(FILE *dataFile, Product *product) {
    int regRoot = readHeadField(OFFSET_REG_ROOT, dataFile);
    if(regRoot == -1) {
        Node *node = makeNode(product, -1, -1);
        writeHeadField(
            (regRoot = insertNode(dataFile, node)),
            OFFSET_REG_ROOT,
            dataFile
        );
        free(node);
        return regRoot;
    }else{
        return insertProductRec(dataFile, regRoot, product);
    }
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param this 
 * @param product 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int insertProductRec(FILE *dataFile, int this, Product *product) {
    int position;
    if(product->code < readNodeField(OFFSET_NODE_CODE, this, dataFile)) {
        if((position = readNodeField(OFFSET_NODE_LEFT, this, dataFile)) == -1) {
            Node *newNode = makeNode(product, -1, -1);
            writeNodeField(
                (position = insertNode(dataFile, newNode)),
                OFFSET_NODE_LEFT,
                this,
                dataFile
            );
            free(newNode);
            return position;
        }
    }else{
        if((position = readNodeField(OFFSET_NODE_RIGHT, this, dataFile)) == -1) {
            Node *newNode = makeNode(product, -1, -1);
            writeNodeField(
                (position = insertNode(dataFile, newNode)),
                OFFSET_NODE_RIGHT,
                this,
                dataFile
            );
            free(newNode);
            return position;
        }
    }
    return insertProductRec(dataFile, position, product);
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param position 
 * @param product 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int updateProduct(FILE *dataFile, int position, Product *product) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fwrite(product, sizeof(Product), 1, dataFile);
    return position;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param code 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int removeProduct(FILE *dataFile, int code) {
    int ret = removeProductRec(
        dataFile,
        readHeadField(OFFSET_REG_ROOT, dataFile),
        code
    );
    writeHeadField(
        ret,
        OFFSET_REG_ROOT,
        dataFile
    );
    return ret;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param this 
 * @param code 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int removeProductRec(FILE *dataFile, int this, int code) {
    if(this == -1) return -1;
    int thisCode = readNodeField(OFFSET_NODE_CODE, this, dataFile);
    int leftChild = readNodeField(OFFSET_NODE_LEFT, this, dataFile);
    int rightChild = readNodeField(OFFSET_NODE_RIGHT, this, dataFile);
    if(code < thisCode) {
        writeNodeField(
            removeProductRec(dataFile, leftChild, code),
            OFFSET_NODE_LEFT,
            this,
            dataFile
        );
    }else if (code > thisCode) {
        writeNodeField(
            removeProductRec(dataFile, rightChild, code),
            OFFSET_NODE_RIGHT,
            this,
            dataFile
        );
    }else{
        if(leftChild == -1 && rightChild == -1) {
            removeNode(dataFile, this);
            this = -1;
        }else if(leftChild == -1) {
            Product *product;
            updateProduct(
                dataFile,
                this,
                (product = readNodeProduct(
                    dataFile,
                    minimum(dataFile, rightChild)
                ))
            );
            free(product);
            writeNodeField(
                removeProductRec(
                    dataFile,
                    rightChild,
                    readNodeField(OFFSET_NODE_CODE, this, dataFile)
                ),
                OFFSET_NODE_RIGHT,
                this,
                dataFile
            );
        }else{
            Product *product;
            updateProduct(
                dataFile,
                this,
                (product = readNodeProduct(
                    dataFile,
                    maximum(dataFile, leftChild)
                ))
            );
            free(product);
            writeNodeField(
                removeProductRec(
                    dataFile,
                    leftChild,
                    readNodeField(OFFSET_NODE_CODE, this, dataFile)
                ),
                OFFSET_NODE_LEFT,
                this,
                dataFile
            );
        }
    }
    return this;
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param code 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int searchProductByCode(FILE *dataFile, int code) {
    return searchProductByCodeRec(
        dataFile,
        readHeadField(OFFSET_REG_ROOT, dataFile),
        code
    );
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param this 
 * @param code 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int searchProductByCodeRec(FILE *dataFile, int this, int code) {
    if (this == -1) return -1;
    int thisCode = readNodeField(OFFSET_NODE_CODE, this, dataFile);
    if (thisCode > code)
        return searchProductByCodeRec(
            dataFile,
            readNodeField(OFFSET_NODE_LEFT, this, dataFile),
            code
        );
    if (thisCode < code)
        return searchProductByCodeRec(
            dataFile,
            readNodeField(OFFSET_NODE_RIGHT, this, dataFile),
            code
        );
    return this;
}

/**
 * @brief 
 * 
 * deixamos esta funcao em espera
 * ate o dia em que a gente
 * aprenda uma forma eficiente 
 * de buscar uma string entera
 * 
 * @param dataFile 
 * @param name 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int searchProductByName(FILE *dataFile, char *name) {
    return searchProductByNameRec(
        dataFile, 
        readHeadField(OFFSET_REG_ROOT, dataFile),
        name
    );
}

/**
 * @brief 
 * 
 * @param dataFile 
 * @param this 
 * @param name 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
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
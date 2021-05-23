/**
 * @file produto.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as operações sobre um único produto do estoque
 * @version 0.1
 * @date 03/05/2021
 */
 
#include "product.h"

Product* allocProduct() {
    return (Product *)malloc(sizeof(Product));
}

void readCodeProduct(int *code) {
    scanf("%d%*c", code);
}

void readNameProduct(char *name) {
    scanf("%[^\n]%*c", name);
}

void readNumberProduct(int *number) {
    scanf("%d", number);
}

void readValueProduct(float *value) {
    scanf("%f%*c", value);
}

void readLocalProduct(char *local) {
    scanf("%[^\n]%*c", local);
}

void freeProduct(Product *product) {
    free(product);
}
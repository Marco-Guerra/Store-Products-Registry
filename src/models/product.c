/**
 * @file produto.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as operações sobre um único produto do estoque
 * @version 0.1
 * @date 03/05/2021
 */
 
#include "product.h"

Product *allocProduct() {
    Product *product = (Product *)malloc(sizeof(Product));
    product->code = 0;
    reset(product->name, MAX_NAME);
    product->number = 0;
    product->value = 0;
    reset(product->local, MAX_LOCAL);
    return product;
}

void printProduct(Product *product) {
    printf("\nNome: %s.\n", product->name);
    printf("Code: %d.\n", product->code);
    printf("Number: %d.\n", product->number);
    printf("Value: %f.\n", product->value);
    printf("Local: %s.\n\n", product->local);
}

void printBasicProduct(Product *product) {
    // 10 digitos maximos de um int, 19 caracteres a mais da string
    char buffer[19 + 10 + MAX_NAME + 1];
    sprintf(buffer, "    Nome: %s Code: %d", product->name, product->code);
    printAlignedLeft(buffer);
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
/**
 * @file produto.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as operações sobre um único produto do estoque
 * @version 0.1
 * @date 03/05/2021
 */
 
#include "product.h"

/**
 * @brief Aloca estrutura Produto
 * 
 * @return Product* 
 * @pre Nenhuma
 * @post Espaço para um produto alocado
 */
Product *allocProduct() {
    Product *product = (Product *)malloc(sizeof(Product));
    product->code = 0;
    reset(product->name, MAX_NAME);
    product->number = 0;
    product->value = 0;
    reset(product->local, MAX_LOCAL);
    return product;
}

/**
 * @brief Imprime a descrição do produto
 * 
 * @param product ponteiro para uma estrutura com os dados do produto
 * @pre Nenhuma
 * @post Produto descrito no console
 */
void printProduct(Product *product) {
    printLine();
    printf("\n\tNome: ");
    printString(product->name);
    printf("\n\tCode: %d.\n", product->code);
    printf("\tNumber: %d.\n", product->number);
    printf("\tValue: %.2f.\n", product->value);
    printf("\tLocal: ");
    printString(product->local);
    printf("\n\n");
    printLine();
}

/**
 * @brief 
 * 
 * @param product 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBasicProduct(Product *product) {
    // 10 digitos maximos de um int, 19 caracteres a mais da string
    char buffer[19 + 10 + MAX_NAME + 1];
    sprintf(buffer, "    Nome: %s Code: %d", product->name, product->code);
    printAlignedLeft(buffer);
}

/**
 * @brief Lê o produto do teclado
 * 
 * @return Product* 
 * @pre Nenhuma
 * @post Produto lido do teclado
 */
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
#ifndef PRODUCT
#define PRODUCT

/**
 * @file produto.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir o que é um produto, bem como as funções que interagem com o mesmo
 * @version 1.0
 * @date 21/05/2021
 */

#include "../utilities/utilities.h"

/**
 * @brief Indica a quantidade máxima de caracteres possíveis de se guardar em um nome
 */
#define MAX_NAME 51

/**
 * @brief Indica a quantidade máxima de caracteres possíveis de se guardar em um nome
 */
#define MAX_LOCAL 101

/**
 * @brief Indica a quantidade máxima de caracteres possíveis de ocorrer em uma linha do arquivo de entrada
 */
#define MAX_ENTRY_LINE 251

typedef struct {
    int regRoot;
    int regLast;
    int regFree;
}Head;

typedef struct {
    int code;               /// código do produto
    char name[MAX_NAME];    /// nome do produto
    int number;             /// quantidade de produtos em estoque
    float value;            /// preço do produto
    char local[MAX_LOCAL];  /// local em que o produto está no estoque
}Product;

typedef struct node {
    Product product;
    int rChild;
    int lChild;
}Node;

/**
 * @brief Aloca um produto
 *
 * @return Produto*
 * @pre Nenhuma
 * @post Espaço para um produto alocado
 */
Product* allocProduct();

Node *allocNode();

void writeHead(Head *head, FILE *dataFile);

Head *readHead(FILE *dataFile);

FILE *makeDataFile(char *filePath);

void writeNode(FILE *dataFile, Node *node, int position);

Node *makeNode(Product *product, int rChild, int lChild);

Node* readNode(FILE *dataFile, int position);

int insertNode(FILE *dataFile, Node *node);

int removeNode(FILE *dataFile, int position);

int maximum(FILE *dataFile);

int minimum(FILE *dataFile);

int insertProduct(FILE *dataFile, Product *product);

int insertProductRec(FILE *dataFile, int this, Product *product);

int removeProduct(FILE *dataFile, int code);

int removeProductRec(FILE *dataFile, int this, int code);

int searchProductByCode(FILE *dataFile, int code);

int searchProductByCodeRec(FILE *dataFile, int this, int code);

int searchProductByName(FILE *dataFile, char *name);

int searchProductByNameRec(FILE *dataFile, int this, char *name);

void printProduct(Product *product);

Product* scanProduct();

#endif

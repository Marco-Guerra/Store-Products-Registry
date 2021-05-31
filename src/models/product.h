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
    int code;               /// código do produto
    char name[MAX_NAME];    /// nome do produto
    int number;             /// quantidade de produtos em estoque
    float value;            /// preço do produto
    char local[MAX_LOCAL];  /// local em que o produto está no estoque
}Product;

/**
 * @brief Aloca um produto
 *
 * @return Produto*
 * @pre Nenhuma
 * @post Espaço para um produto alocado
 */
Product* allocProduct();

/**
 * @brief Imprime a descrição do produto
 * 
 * @param product ponteiro para uma estrutura com os dados do produto
 * @pre Nenhuma
 * @post Produto descrito no console
 */
void printProduct(Product *product);

/**
 * @brief 
 * 
 * @param product 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBasicProduct(Product *product);

/**
 * @brief Lê o produto do teclado
 * 
 * @return Product* 
 * @pre Nenhuma
 * @post Produto lido do teclado
 */
Product* scanProduct();

#endif

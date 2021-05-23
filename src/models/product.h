#ifndef PRODUTO
#define PRODUTO

/**
 * @file produto.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir o que é um produto, bem como as funções que interagem com o mesmo
 * @version 1.0
 * @date 21/05/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Indica a quantidade máxima de caracteres possíveis de se guardar em um nome
 */
#define MAX_NAME 51

/**
 * @brief Indica a quantidade máxima de caracteres possíveis de se guardar em um nome
 */
#define MAX_LOCAL 101

/**
 * @brief Estrutura que representa um único item no estoque
 */
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
 * @brief Lê do teclado o código de um produto
 *
 * @param code local de memória do código do produto
 * @pre Nenhuma
 * @post Informação lida do teclado
 */
void readCodeProduct(int *code);

/**
 * @brief Lê do teclado o
 *
 * @param name local de memória do nome do produto
 * @pre Nenhuma
 * @post Informação lida do teclado
 */
void readNameProduct(char *name);

/**
 * @brief Lê do teclado o
 *
 * @param number local de memória da quantidade de produtos em estoque
 * @pre Nenhuma
 * @post Informação lida do teclado
 */
void readNumberProduct(int *number);

/**
 * @brief Lê do teclado o
 *
 * @param value local de memória do preço unitário de um único produto
 * @pre Nenhuma
 * @post Informação lida do teclado
 */
void readValueProduct(float *value);

/**
 * @brief Lê do teclado o local em que o produto está no estoque
 *
 * @param local local de memória da localização
 * em que o produto está no estoque
 * @pre Nenhuma
 * @post Informação lida do teclado
 */
void readLocalProduct(char *local);

/**
 * @brief Desaloca o espaço alocado para um único produto
 *
 * @param product Um produto alocado dinamicamente
 * @pre O produto p deve ter sido alocado
 * @post Produto p desalocado
 */
void freeProduct(Product *product);

#endif
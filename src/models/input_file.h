/**
 * @file input_file.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 30/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef INPUT_FILE
#define INPUT_FILE

#include "../utilities/menu.h"
#include "../utilities/utilities.h"
#include "product_tree.h"
#include <ctype.h>

/**
 * @brief Tamanho máximo para o caminho do arquivo
 */
#define FILE_PATH_NAME 100

/**
 * @brief Operações possíveis de serem realizadas no arquivo
 */
enum inputFileOperations {
    INPUT_FILE_INSERT = 'I',
    INPUT_FILE_MODIFY = 'A',
    INPUT_FILE_REMOVE = 'R',
};

/**
 * @brief Carrega todo o arquivo de entrada
 * 
 * @param inputPath caminho para o arquivo de entrada
 * @param dataFile ponteiro para o arquivo binário que contém o estoque
 * @pre linha carregado
 * @post arquivo de entrada lido
 */
void loadInputFile(char *inputPath, FILE *dataFile);

/**
 * @brief formata a linha para que seja possivel obter os dados
 * 
 * Trocando o caractere , por um .
 * @param line uma unica linha lida do arquivo
 * @pre Linha carregado
 * @post Linha formatado
 */
void formatLine(char *line);

/**
 * @brief Insere um novo produto a partir dos dados carregados de uma linha
 * 
 * @param line uma unica linha lida do arquivo
 * @param dataFile ponteiro para o arquivo binário que contém o estoque
 * @pre linha carregado
 * @post Elemento lido da linha inserido
 */
void insertFornLine(char *line, FILE *dataFile);

/**
 * @brief Modifica um elemento do estoque
 * 
 * @param line uma unica linha lida do arquivo
 * @param dataFile ponteiro para o arquivo binário que contém o estoque
 * @pre linha carregado
 * @post Elemento quando encontrado é modificado
 */
void modifyFornLine(char *line, FILE *dataFile);

/**
 * @brief Remove um elemento do estoque
 * 
 * @param line uma unica linha lida do arquivo
 * @param dataFile ponteiro para o arquivo binário que contém o estoque
 * @pre linha carregado
 * @post Elemento quando encontrado é removido
 */
void removeFromLine(char *line, FILE *dataFile);

/**
 * @brief Remove espaços em branco da linha
 * 
 * @param line uma unica linha lida do arquivo
 * @return char* a linha sem espaços desnecessários
 * @pre linha carregado
 * @post linha sem espaços em branco
 */
char *trim(char *line);

void getFromLine(char *line, int *number, float *value, char *local);

char *getInside(char *line);

#endif

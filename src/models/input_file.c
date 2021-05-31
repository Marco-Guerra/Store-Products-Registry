/**
 * @file input_file.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por ler o arquivo de entrada
 * @version 0.1
 * @date 30/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "input_file.h"

/**
 * @brief 
 * 
 * @param inputPath 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void loadInputFile(char *inputPath, FILE *dataFile) {
    FILE *inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }
    char *line = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    while(fgets(line, MAX_ENTRY_LINE, inputFile) != NULL) {
        line = trim(line);
        formatLine(line);
        switch(line[0]) {
            case INPUT_FILE_INSERT: insertFornLine(line, dataFile);
                break;
            case INPUT_FILE_MODIFY: //modifyFornLine(line, dataFile);
                break;
            case INPUT_FILE_REMOVE: removeFromLine(line, dataFile);
                break;
        }
    }
    fclose(inputFile);
}

void formatLine(char *line) {
    for(; *line; line++) {
        if(*line == ',') {
            *line = '.';
        }
    }
}

/**
 * @brief 
 * 
 * @param line 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void insertFornLine(char *line, FILE *dataFile) { //////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ <- volta aqui, e faz certo 
    Product *product = (Product*)malloc(sizeof(Product));
    printf("%s\n", line);
    sscanf(line, "%*c;%d;%[^;];%d;%f;%[^\n]",
        &(product->code),
        product->name,
        &(product->number),
        &(product->value),
        product->local
    );
    printProduct(product);
    printWaitMenu();
    if(searchProductByCode(dataFile, product->code) == -1)
        insertProduct(dataFile, product);
    free(product);
}

/**
 * @brief 
 * 
 * @param line 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void modifyFornLine(char *line, FILE *dataFile) {
    Node *node;
    int code, position;
    sscanf(line, "%*c;%d", &code);
    position = searchProductByCode(dataFile, code);
    if(position == -1)
        return;
    node = readNode(dataFile, position);
    //readField() ////////////////////////////////////// <- volta aqui
    writeNode(dataFile, node, position);
    free(node);
}

/**
 * @brief 
 * 
 * @param line 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void removeFromLine(char *line, FILE *dataFile) {
    int code;
    sscanf(line, "%*c;%d", &code);
    removeProduct(dataFile, code);
}

/**
 * @brief 
 * 
 * @param line 
 * @return char* 
 * @pre Nenhuma
 * @post Nenhuma
 */
char *trim(char *line) {
    char *newLine = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    int i_new;
    int i_old = 0;
    while(isspace(line[i_old])) {
        i_old++;
    }
    for(i_new = 0; line[i_old]; i_old++) {
        if (!((isspace(line[i_old]) && isspace(line[i_old - 1])) ||
              (isspace(line[i_old]) && isspace(line[i_old + 1])) ||
              (line[i_old + 1] == ';' && isspace(line[i_old])) ||
              (line[i_old - 1] == ';' && isspace(line[i_old]))
        )) {
            newLine[i_new++] = line[i_old];
        }
    }
    newLine[i_new] = 0;
    free(line);
    return newLine;
}

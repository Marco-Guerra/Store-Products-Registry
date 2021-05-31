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
#include "product_tree.h"
#include <ctype.h>

#define FILE_PATH_NAME 100

enum inputFileOperations {
    INPUT_FILE_INSERT = 'I',
    INPUT_FILE_MODIFY = 'A',
    INPUT_FILE_REMOVE = 'R',
};

void loadInputFile(char *inputPath, FILE *dataFile);

void insertFornLine(char *line, FILE *dataFile);

void modifyFornLine(char *line, FILE *dataFile);

void removeFromLine(char *line, FILE *dataFile);

char *trim(char *line);

#endif

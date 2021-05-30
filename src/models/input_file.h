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

#include "product_tree.h"

#define WHITE_SPACE ' '

enum inputFileOperations {
    INPUT_FILE_INSERT = 'I',
    INPUT_FILE_MODIFY = 'A',
    INPUT_FILE_REMOVE = 'R',
};

Product * readProductDataFromInputFile(FILE *input);

void loadInputFile(char *inputPath, FILE *dataFile);

#endif

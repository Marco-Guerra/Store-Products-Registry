/**
 * @file input_file.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 30/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "input_file.h"

Product * readProductDataFromInputFile(FILE *input) {
    Product *p = (Product *)malloc(sizeof(Product));
    fscanf(input, "%d%*c", &p->code);
    printf("%d\n", p->code);
    fscanf(input, "%[^;]%*c", p->name);
    fscanf(input, "%d%*c", &p->number);
    fscanf(input, "%f%*c", &p->value);
    fscanf(input, "%[^;]%*[^\n]%*r", p->local);
    printf("Dados do produto\n\n");
    printProduct(p);
    return p;
}

void loadInputFile(char *inputPath, FILE *dataFile) {
    FILE *inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        printf("Falha na abertura do arquivo\n");
        return ;
    }
    
    //char *line[MAX_ENTRY_LINE];
    char c;
    Product read;
    while(fscanf(inputFile, "%c%*c", &c) != EOF) {
        printf("Estou no caractere %c\n", c);

        switch(c) {
            case INPUT_FILE_INSERT: //insertFornFile(line);
                printf("Entrei no insert\n");
                insertProduct(dataFile, readProductDataFromInputFile(dataFile));
                break;
            case INPUT_FILE_MODIFY: //modifyFornFile(line);
                printf("Entrei no modify\n");

                fscanf(inputFile, "%*[^\n]%*r");
                break;
            case INPUT_FILE_REMOVE: //removeFromFile(line);
                printf("Entrei no remove\n");
                int code;
                fscanf(inputFile, "%d%*r", &code);
                removeProduct(dataFile, code);
                break;
            case WHITE_SPACE:
                printf("Estou excluindo espaco\n");
                while (fscanf(inputFile, "%c", &c) == WHITE_SPACE) {
                    ;
                }
                break;
            default:
                printf("Entrei no default\n");
                // a linha será ignorada
                fscanf(inputFile, "%*[^\n]%*r");
                break;
        }
    }
    fclose(inputFile);
}

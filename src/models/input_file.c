#include "input_file.h"

void loadInputFile(char *inputPath, FILE *dataFile) {
    FILE *inputFile = fopen(inputPath, "r");
    char *line[MAX_ENTRY_LINE];
    char c;
    while(0) {
        //fscanf();

        switch(c) {
            case 'I': insertFornFile(line);
                break;
            case 'A': modifyFornFile(line);
                break;
            case 'R': removeFromFile(line);
                break;
            default:
                
        }
    }
    fclose(inputFile);
}

#include "main_controller.h"

int mainController(int argc, char *argv[]) {
    char *filePath;

    if(argc == 2) {
        filePath = (char*)malloc(sizeof(char) * (strlen(argv[1]) + 1));
        strcpy(filePath, argv[1]);
    }else {
        filePath = NULL;
    }

    mainMenuController(&filePath);
    printf("Caminho para o arquivo %s\n", filePath);
    printEndMessage();

    free(filePath);

    return 0;
}

#include "controllers/main_controller.h"
#include "views/main_menu.h"

int main(int argc, char *argv[]) {
    char *filePath;

    if(argc == 2) {
        filePath = (char*)malloc(sizeof(char) * (strlen(argv[1]) + 1));
        strcpy(filePath, argv[1]);
    }else {
        filePath = NULL;
    }

    controlMainMenu(&filePath);
    printf("Caminho para o arquivo %s\n", filePath);
    printEndMessage();

    free(filePath);
    return 0;
}
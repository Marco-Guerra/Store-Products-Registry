#include "./controllers/main_menu_controller.h"
#include "./models/product_tree.h"
#include "./models/input_file.h"

int main(int argc, char *argv[]) {
    char filePath[] = "./data.bin";
    FILE *dataFile = fopen(filePath, "r+b");

    if(dataFile == NULL) {
        printf("Estou aqui\n");
        dataFile = makeDataFile(filePath);
    }
    
    if(argc == 2) {
        loadInputFile(argv[1], dataFile);
    }

    Head *head = readHead(dataFile);
    printf("%d\n", head->regRoot);
    printf("%d\n", head->regFree);
    printf("%d\n", head->regLast);

    mainMenuController(dataFile);
    fclose(dataFile);

    return 0;
}

#include "./controllers/main_menu_controller.h"
#include "./models/product_tree.h"
#include "./models/input_file.h"

int main(int argc, char *argv[]) {
    char filePath[] = "./data.bin";
    FILE *dataFile = fopen(filePath, "r+b");

    if(dataFile == NULL) {
        printf("Estou aqui\n");
        dataFile = makeDataFile(filePath);
    }else{
        setbuf(dataFile, NULL);
    }
    
    if(argc == 2) {
        loadInputFile(argv[1], dataFile);
    }

    mainMenuController(dataFile);

    fclose(dataFile);

    return 0;
}

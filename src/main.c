/**
 * @file main.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 31/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "./controllers/main_menu_controller.h"
#include "./models/product_tree.h"
#include "./models/input_file.h"

/** @mainpage Store Products Registry
 * 
 * ola mundo
 */

int main(int argc, char *argv[]) {
    char filePath[] = "./data.bin";
    FILE *dataFile = fopen(filePath, "r+b");
    if(dataFile == NULL) {
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

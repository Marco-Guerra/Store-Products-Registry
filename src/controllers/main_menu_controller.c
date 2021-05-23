/**
 * @file controle_principal.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as funções que controlam o menu principal, bem como a chamada de todas as funções a partir do mesmo
 * @version 0.1
 * @date 04/05/2021
 */

#include "main_menu_controller.h"

int confirm() {
    printf("Opa chefia quer fazer isso msm? [S/n]\n");
    return getChar() != 'n';
}

void controlInsertMenu() {
    printHead("Inserindo novo produto");
    Product *product = allocProduct();
    printf("\n\n   Insira o codigo do produto: ");
    readCodeProduct(&product->code);
    printf("   Insira o nome do produto: ");
    readNameProduct(product->name);
    printf("   Insira a quantidade produto(s): ");
    readNumberProduct(&product->number);
    printf("   Insira o preco do produto: ");
    readValueProduct(&product->value);
    printf("   Insira o local do produto: ");
    readLocalProduct(product->local);

    printf("\n\n");
    printProduct(*product);

    if (confirm()) {
        printHead("Operacao bem suces");
    }

    printWaitMenu();
}

/*void mainMenuController(char **filePath) {
    int option = 0;
    char c;
    
    printMainMenu(option);

    while(1) {
        c = getChar();
        
        if (c == UP && option > 0) {
            option--;    
        }else if (c == DOWN && option < LAST_OPTION) {
            option++;
        }

        if (c == ENTER) {
            switch(option)
            {
                case 0:
                    controlInsertMenu(); 
                    break;
                case 1:
                    printLine();
                    printAlignedRight("Escolhi o 1");
                    printLine();
                    printWaitMenu();
                    break;
                case 2:
                    printLine();
                    printAlignedRight("Escolhi o 2");
                    printLine();
                    printWaitMenu();
                    break;
                case 3:
                    printLine();
                    printAlignedRight("Escolhi o 2");
                    printLine();
                    printWaitMenu();
                    break;
                case 4:
                    printLine();
                    printAlignedRight("Escolhi o 2");
                    printLine();
                    printWaitMenu();
                    break;
                case 5:
                    printLine();
                    printAlignedRight("Escolhi o 2");
                    printLine();
                    printWaitMenu();
                    break;
                case 6:
                    printLine();
                    printAlignedRight("Escolhi o 2");
                    printLine();
                    printWaitMenu();
                    break;
                case 7:
                    printLine();
                    printAlignedRight("Escolhi o 2");
                    printLine();
                    printWaitMenu();
                    break;
                case 8:
                    printLine();
                    printAlignedRight("Escolhi o 2");
                    printLine();
                    printWaitMenu();
                    break;
                case 9:
                    printLine();
                    printAlignedRight("Escolhi o 2");
                    printLine();
                    printWaitMenu();
                    break;
                default:
                    return;
            }
        }else {
            system(CLEAR);
            printLine();
            printAlignedRight("Entrada do teclado incorreta");
            printLine();
            printWaitMenu();
        }

        printMainMenu(option);
    }
}*/

void mainMenuController(char **filePath) {

    printf("==============================================");

    Menu *mainMenu = createMenu();
    
    addEntryToMenu(mainMenu, "1", actionInsert);
    addEntryToMenu(mainMenu, "2", actionSearch);
    addEntryToMenu(mainMenu, "3", actionChange);
    addEntryToMenu(mainMenu, "4", actionLoad);
    addEntryToMenu(mainMenu, "5", actionRemove);
    addEntryToMenu(mainMenu, "6", actionClose);
    
    controlMenu(mainMenu);
}

int actionInsert() {

}

int actionSearch() {

}

int actionChange() {

}

int actionLoad() {

}

int actionRemove() {

}

int actionClose() {

}

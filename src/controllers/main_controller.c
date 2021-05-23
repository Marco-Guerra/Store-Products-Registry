/**
 * @file controle_principal.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as funções que controlam
 * o menu principal, bem como a chamada de todas as funções a partir do mesmo
 * @version 0.1
 * @date 04/05/2021
 */

#include "main_controller.h"
#include "../utilities/utilities.h"
#include "../views/main_menu.h"

int confirm() {
    printf("Opa chefia quer fazer isso msm? [S/n]\n");
    return getChar() != 'n';
}

void controlMainMenu(char **caminho) {
    int option = 0;
    char c;
    for(printMainMenu(option); 1; printMainMenu(option)) {
        c = getChar();
        if (c == CIMA) {
            if (option > 0) {
                option--;
            }
        }else if (c == BAIXO) {
            if (option < ULTIMA_OPCAO_MENU_PRICIPAL) {
                option++;
            }
        }else if (c == ENTER) {
            if (option == 0) {
                controlInsertMenu();
            }else if (option == 1) {
                printLine();
                printAlignedRight("Escolhi o 1");
                printLine();
                printWaitMenu();
            }else if (option == 2) {
                printLine();
                printAlignedRight("Escolhi o 2");
                printLine();
                printWaitMenu();
            }else if (option == 3) {
                printLine();
                printAlignedRight("Escolhi o 3");
                printLine();
                printWaitMenu();
            }else if (option == 4) {
                printLine();
                printAlignedRight("Escolhi o 4");
                printLine();
                printWaitMenu();
            }else if (option == 5) {
                printLine();
                printAlignedRight("Escolhi o 5");
                printLine();
                printWaitMenu();
            }else if (option == 6) {
                printLine();
                printAlignedRight("Escolhi o 6");
                printLine();
                printWaitMenu();
            }else if (option == 7) {
                printLine();
                printAlignedRight("Escolhi o 7");
                printLine();
                printWaitMenu();
            }else if (option == 8) {
                printLine();
                printAlignedRight("Escolhi o 8");
                printLine();
                printWaitMenu();
            }else if (option == 9) {
                printLine();
                printAlignedRight("Escolhi o 9");
                printLine();
                printWaitMenu();
            }else {
                return;
            }
        }else {
            system(CLEAR);
            printLine();
            printAlignedRight("Entrada do teclado incorreta");
            printLine();
            printWaitMenu();
        }
    }
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
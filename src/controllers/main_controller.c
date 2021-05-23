/**
 * @file controle_principal.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar as funções que controlam
 * o menu principal, bem como a chamada de todas as funções a partir do mesmo
 * @version 0.1
 * @date 04/05/2021
 */

#include "../headers/controle_principal.h"

int confirmacao() {
    printf("Opa chefia quer fazer isso msm? [S/n]\n");
    return getChar() != 'n';
}

void controleMenuPrincipal(char **caminho) {
    int opcao = 0;
    char c;
    for(printMenuPrincipal(opcao); 1; printMenuPrincipal(opcao)) {
        c = getChar();
        if (c == CIMA) {
            if (opcao > 0) {
                opcao--;
            }
        }else if (c == BAIXO) {
            if (opcao < ULTIMA_OPCAO_MENU_PRICIPAL) {
                opcao++;
            }
        }else if (c == ENTER) {
            if (opcao == 0) {
                controleMenuInserir();
            }else if (opcao == 1) {
                printLine();
                printAlinhadoDireita("Escolhi o 1");
                printLine();
                printMenuEspera();
            }else if (opcao == 2) {
                printLine();
                printAlinhadoDireita("Escolhi o 2");
                printLine();
                printMenuEspera();
            }else if (opcao == 3) {
                printLine();
                printAlinhadoDireita("Escolhi o 3");
                printLine();
                printMenuEspera();
            }else if (opcao == 4) {
                printLine();
                printAlinhadoDireita("Escolhi o 4");
                printLine();
                printMenuEspera();
            }else if (opcao == 5) {
                printLine();
                printAlinhadoDireita("Escolhi o 5");
                printLine();
                printMenuEspera();
            }else if (opcao == 6) {
                printLine();
                printAlinhadoDireita("Escolhi o 6");
                printLine();
                printMenuEspera();
            }else if (opcao == 7) {
                printLine();
                printAlinhadoDireita("Escolhi o 7");
                printLine();
                printMenuEspera();
            }else if (opcao == 8) {
                printLine();
                printAlinhadoDireita("Escolhi o 8");
                printLine();
                printMenuEspera();
            }else if (opcao == 9) {
                printLine();
                printAlinhadoDireita("Escolhi o 9");
                printLine();
                printMenuEspera();
            }else {
                return;
            }
        }else {
            system(CLEAR);
            printLine();
            printAlinhadoDireita("Entrada do teclado incorreta");
            printLine();
            printMenuEspera();
        }
    }
}

// =================================================

#include "../headers/controle_operacao.h"

void controleMenuInserir() {
    printHead("Inserindo novo produto");
    Product *product = allocProduct();
    printf("\n\n   Insira o codigo do produto: ");
    readCodeProduct(&p->cod);
    printf("   Insira o nome do produto: ");
    readNameProduct(p->nome);
    printf("   Insira a quantidade produto(s): ");
    readNumberProduct(&p->qnt);
    printf("   Insira o preco do produto: ");
    readValueProduct(&p->preco);
    printf("   Insira o local do produto: ");
    readLocalProduct(p->local);

    printf("\n\n");
    printProduct(*product);

    if (confirm()) {
        printHead("Operacao bem suces");
    }

    printMenuEspera();
}
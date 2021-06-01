/**
 * @file main.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief 
 * @version 1.0
 * @date 31/05/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "./controllers/main_menu_controller.h"
#include "./models/product_tree.h"
#include "./models/input_file.h"

/** @mainpage 
 *
 * Software desenvolvido como segundo trabalho da disciplina de Algorítimos e Estruturas de Dados
 * do curso de Ciência da Computação da UNIOESTE, Universidade Estadual do Oeste do Paraná, Campus de Foz do Iguaçu
 * ministrada no ano de 2021, pelo professor Rômulo César Silva, pelos alunos Marco A. G. Pedroso, Milena L. dos Santos,
 * Victor E. Almeida
 *
 * @section Objetivo Objetivo
 * Desenvolver um software em C que mantém o cadastro de uma loja de materiais utilizando:
 * - Árvore binária;
 * - Leitura e escrita em arquivo binário;
 * - Leitura em arquivo texto;
 *
 * @section uso Instruções para uso
 * Para utilizar o programa o mesmo deve ser compilado, após isso deve-se executá-lo.
 *
 * @subsection compila Instruções para compilação
 * Caso esteja em um sistema operacional Linux, basta executar o shell script /src/compile.sh.
 *
 * Caso contrário é necessário o um sistema com o compilador GCC executando a seguinte linha, dentro da pasta src:
 * gcc main.c controllers/change_menu_controller.c controllers/main_menu_controller.c controllers/search_menu_controller.c  models/input_file.c models/product.c models/product_tree.c models/queue.c models/tree.c  utilities/menu.c utilities/utilities.c  -o ../build/main.exe -lm
 *
 * @subsection roda Instruções para Execução
 * Uma vez executado, será aberto um menu que espera a entrada de um único caractere de entrada do usuário, podendo ser:
 * - w: o item selecionado será o imediatamente acima do atual.
 * - s: o item selecionado será o imediatamente abaixo do atual.
 * - outro: Entrada inválida será descartada
 *
 * Tais definições estão no arquivo utilities.h, podendo ser alteradas caso seja mais conveniente.
 *
 * @section estruturas Principais estruturas de Dados
 * - Menu
 * - Head
 * - Node
 * - Product
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

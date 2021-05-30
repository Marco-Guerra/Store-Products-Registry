#ifndef SEARCH_MENU_CONTROLLER
#define SEARCH_MENU_CONTROLLER

#include "../utilities/menu.h"
#include "../utilities/utilities.h"
#include "../models/product_tree.h"

int searchMenuController(FILE *dataFile);

int actionSearchProductByName(FILE *dataFile);
int actionSearchProductByCode(FILE *dataFile);
int actionListProducts(FILE *dataFile);
int actionPrintTree(FILE *dataFile);
int actionPrintFreeSpaces(FILE *dataFile);
int actionSearchReturn(FILE *dataFile);

#endif

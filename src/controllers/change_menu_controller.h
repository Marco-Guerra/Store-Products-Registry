#ifndef CHANGE_MENU_CONTROLLER
#define CHANGE_MENU_CONTROLLER

#include "../utilities/menu.h"
#include "../utilities/utilities.h"
#include "../models/product_tree.h"

int changeMenuController(FILE *dataFile);

int actionChangeNumber(FILE *dataFile);
int actionChangeValue(FILE *dataFile);
int actionChangeLocal(FILE *dataFile);
int actionChangeReturn(FILE *dataFile);

#endif

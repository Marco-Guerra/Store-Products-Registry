#ifndef PRODUCT_TREE
#define PRODUCT_TREE

#include "tree.h"

#include "../utilities/menu.h" ////////////////////////////////////

int maximum(FILE *dataFile, int this);

int minimum(FILE *dataFile, int this);

int insertProduct(FILE *dataFile, Product *product);

int insertProductRec(FILE *dataFile, int this, Product *product);

int updateProduct(FILE *dataFile, int position, Product *product);

int removeProduct(FILE *dataFile, int code);

int removeProductRec(FILE *dataFile, int this, int code);

int searchProductByCode(FILE *dataFile, int code);

int searchProductByCodeRec(FILE *dataFile, int this, int code);

int searchProductByName(FILE *dataFile, char *name);

int searchProductByNameRec(FILE *dataFile, int this, char *name);

#endif
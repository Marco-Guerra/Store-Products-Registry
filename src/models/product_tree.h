#ifndef PRODUCT_TREE
#define PRODUCT_TREE

#include "tree.h"

int maximum(FILE *dataFile);

int minimum(FILE *dataFile);

int insertProduct(FILE *dataFile, Product *product);

int insertProductRec(FILE *dataFile, int this, Product *product);

int removeProduct(FILE *dataFile, int code);

int removeProductRec(FILE *dataFile, int this, int code);

int searchProductByCode(FILE *dataFile, int code);

int searchProductByCodeRec(FILE *dataFile, int this, int code);

int searchProductByName(FILE *dataFile, char *name);

int searchProductByNameRec(FILE *dataFile, int this, char *name);

#endif
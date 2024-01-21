// CS2211a 2023, Section 1
// Assignment 5
// Dylan Wettlaufer
// 251298849
// dwettla3
// December 5, 2023


#include "bstree.h"

typedef BStree Matrix;
typedef Key1 Index1;
typedef Key2 Index2;
typedef float Value;

Matrix matrix_construction(void);
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2);
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2);
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);


#ifndef ASN5_MATRIX_H
#define ASN5_MATRIX_H

#endif //ASN5_MATRIX_H

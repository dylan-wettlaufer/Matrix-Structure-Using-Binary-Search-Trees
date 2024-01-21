// CS2211a 2023, Section 1
// Assignment 5
// Dylan Wettlaufer
// 251298849
// dwettla3
// December 5, 2023


#include <stdlib.h>
#include "matrix.h"

Matrix matrix_construction(void) {
    Matrix matrix = bstree_ini(); // creates the matrix by creating a bstree
    return matrix;
}

unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2) { // checks if the index is in the matrix
    Key key = key_ini();
    key_set(key, index1, index2); // creates and sets a new key with the given values for the index
    Data data = bstree_search(m, key); // returns the data of the given key
    key_free(key);
    if (data == NULL) return 0; // if the data doesn't exist return 0
    else return 1;
}

const Value *matrix_get(Matrix m, Index1 index1, Index2 index2) { // gets the data from the given index in the matrix
    Key key = key_ini();
    key_set(key, index1, index2); // creates and sets a new key with the given values for the index
    Data data = bstree_search(m, key); // returns the data of the given key
    key_free(key);
    if (data == NULL) return NULL;
    else return data; // if the data exists return data
}

void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value) { // if data is in the matrix its value is updated, if it isn't in the matrix, then add to the matrix
    Key key = key_ini();
    key_set(key, index1, index2); // creates and sets a new key with the given values for the index
    Data data = bstree_search(m, key); // returns the data of the given key
    if (data == NULL) { // if data isn't in the matrix, data is initialized and added to the matrix
        Data newData = data_ini();
        data_set(newData, value);
        bstree_insert(m, key, newData);
    }
    else data_set(data, value); // if it is in the matrix, data's value is updated
}

void matrix_list(Matrix m) { // traverses nd prints out eh key and data of each node in the matrix
    bstree_traverse(m);
}

void matrix_destruction(Matrix m) { // frees all memory in the matrix
    bstree_free(m);
}
// CS2211a 2023, Section 1
// Assignment 5
// Dylan Wettlaufer
// 251298849
// dwettla3
// December 5, 2023


#include <stdio.h>
#include <string.h>
#include "matrix.h"

int main(void) {

    Key key = key_ini();
    key_set(key, "hello", 5);
    Data data = data_ini();
    data_set(data, 1);
    BStree tree = bstree_ini();
    bstree_insert(tree, key, data);
    bstree_traverse(tree);
    bstree_free(tree);



    FILE *file = fopen("list.txt", "r" ); // opens the file for reading
    if (file != NULL) {
        Matrix matrix = matrix_construction(); // creates the matrix
        char key1[1000];
        int key2;
        unsigned char value;


        while (fscanf(file, "%d", &key2) == 1) { // loops until there are no more lines to read in the file, gets the number in the line for key2
            int c;
            while ((c = fgetc(file)) != EOF && (c == ' ' || c == '\t')); // removes any white space in the line containing key1
            ungetc(c, file);

            fgets(key1, sizeof(key1), file); // gets key1 from the line

            size_t len = strlen(key1);
            if (len > 0 && key1[len - 1] == '\n') key1[len - 1] = '\0'; // removes the new line character and adds the null character

            value = matrix_index_in(matrix, key1, key2); // checks if the key is in the matrix
            if (value == 1) { // if the key is in the matrix
                const Value *data = matrix_get(matrix, key1, key2); // get the data of the key
                matrix_set(matrix, key1, key2, *data+1); // increase the data by 1
            }
            else matrix_set(matrix, key1, key2, 1); // if the key isn't in the tree, add the key with data equal to 1

        }
        printf("Number     Street \t\t   Occurrence\n");
        matrix_list(matrix); // print out the matrix
        matrix_destruction(matrix); // free the memory

    }
}

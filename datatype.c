// CS2211a 2023, Section 1
// Assignment 5
// Dylan Wettlaufer
// 251298849
// dwettla3
// December 5, 2023


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

Key key_ini() {
    Key new_key = (Key)malloc(sizeof(Key_struct)); // allocates memory for the key
    new_key -> key1 = NULL; // sets key1 to null
    new_key -> key2 = 0; // sets key2 to 0
    return new_key;
}

void key_set(Key key, Key1 key1, Key2 key2) {
    key->key1 = (Key1) malloc(strlen(key1) + 1); // allocates memory for key1 with the size of the given key1
    if (key->key1 != NULL) strcpy(key->key1, key1); // copies key1 to the given key's key1
    key->key2 = key2;
}

int key_comp(Key key1, Key key2) {
    int compare = strcmp(key1->key1, key2->key1); // compare the key1 chars
    if (compare != 0) return compare;
    else return key1->key2 - key2->key2; // if the key1's are equal return teh difference between the key2s
}

void key_print1(Key key) { // prints the key
    printf("Key string: %s", key->key1);
    printf("Key integer: %d", key->key2);
}

void key_print2(Key key) { // prints the key
    printf("%d \t %s ", key->key2, key->key1);
}

void key_free(Key key) { // frees the key
    free(key->key1);
    free(key);
}

Data data_ini() {
    Data new_data = (Data)malloc(sizeof(float)); // allocates memory for the key
    return new_data;
}

void data_set(Data data, float intdata) { // sets the value of data equal to intdata
    *data = intdata;
}

void data_print(Data data) { // print the data
    printf("\t %f\n", *data);
}

void data_free(Data data) { // free the data
    free(data);
}







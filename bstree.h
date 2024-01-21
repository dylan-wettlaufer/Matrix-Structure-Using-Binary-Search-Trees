// CS2211a 2023, Section 1
// Assignment 5
// Dylan Wettlaufer
// 251298849
// dwettla3
// December 5, 2023


#include "datatype.h"

typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;

BStree bstree_ini(void);
void bstree_insert(BStree bst, Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traverse(BStree bst);
void bstree_free(BStree bst);

void inorder(BStree_node **node);
BStree_node *new_node(Key key, Data data);
void insert(BStree_node **node, Key key, Data data);
void freeNode(BStree_node *node);
Data key_search(BStree_node **node, Key key);


#ifndef ASN5_BSTREE_H
#define ASN5_BSTREE_H

#endif //ASN5_BSTREE_H

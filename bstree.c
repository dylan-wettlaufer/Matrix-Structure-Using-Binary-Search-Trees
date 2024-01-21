// CS2211a 2023, Section 1
// Assignment 5
// Dylan Wettlaufer
// 251298849
// dwettla3
// December 5, 2023


#include "stdlib.h"
#include "bstree.h"

BStree bstree_ini(void) {
    BStree tree = (BStree)malloc(sizeof(BStree_node*)); // allocates memory for the tree
    if (tree != NULL) *tree = NULL; // sets the tree equal to null
    return tree;
}

void bstree_insert(BStree bst, Key key, Data data) {
    insert(bst, key, data); // calls the pointer to the tree with the key and data that will be inserted
}

void insert(BStree_node **node, Key key, Data data) {
    if (*node == NULL) { //  checks if node is null, if it is a new node is created and set to *node
        *node = new_node(key, data);
    }
    else {
        int result = key_comp(key, (*node)->key); // compares the keys
        if (result < 0) { // recursively calls the function given the value of the comparison
            insert(&((*node))->left, key, data); // takes the address of the left pointer and calls insert recursively
        }
        else insert(&((*node))->right, key, data); // takes the address of the right pointer and calls insert recursively
    }
}

BStree_node *new_node(Key key, Data data) {
    BStree_node *node = (BStree_node*)malloc(sizeof(BStree_node)); // allocates memory for a new node
    node->key = key;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Data bstree_search(BStree bst, Key key) {
    return key_search(bst, key); // calls the pointer to the tree and the key that we want the data for
}

Data key_search(BStree_node **node, Key key) {
    if (*node == NULL) return NULL;
    int result = key_comp(key, (*node)->key);
    if (result == 0) return (*node)->data; // returns the data pointer of the current node
    else if (result < 0)  return key_search(&((*node))->left, key); // takes the address of the left pointer and calls search recursively
    else return key_search(&((*node))->right, key); // takes the address of the right pointer and calls search recursively
}

void bstree_traverse(BStree bst) {
    inorder(bst); // calls the pointer to the tree
}

void inorder(BStree_node **node) {
    if (*node == NULL) return;
    else {
        if ((*node)->left != NULL) inorder(&((*node))->left); // if the current nodes pointer to left isn't null, call the address of the left pointer

        key_print2((*node)->key);
        data_print((*node)->data);

        if ((*node)->right != NULL) inorder(&((*node))->right); // if the current nodes pointer to right isn't null, call the address of the right pointer

    }
}

void bstree_free(BStree bst) {
    if (bst != NULL) {
        freeNode(*bst); // calls the pointer to the tree
        free(bst);
    }
}

void freeNode(BStree_node *node) {
    if (node != NULL) {
        freeNode(node->left); // calls the pointer of the left subtree
        freeNode(node->right); // calls the pointer of the right subtree
        key_free(node->key); // frees the key
        data_free(node->data); // frees the data
        free(node); // frees the node
    }
}



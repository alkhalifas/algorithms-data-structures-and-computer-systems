// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    // Create new BST, malloc for size of bst_t
    bst_t* myBST= (bst_t*)malloc(sizeof(bst_t)); 
    // Set root as NULL
    myBST->root = NULL;
    // Set size as 0
    myBST->size = 0;
    return myBST;
}

bstnode_t* create_node(int item) {
    // Instantiate new mode, and malloc size
    bstnode_t* node = (bstnode_t*)malloc(sizeof(bstnode_t));
    // Assign data as item
    node->data = item;
    // Assign NULL for left and right children
    node->rightChild = NULL;
    node->leftChild = NULL;
    // Return the newly created node
    return node;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    // Return the size, which should be either
    // 0 or another number
    return t->size == 0;
}

int bst_recursiveAdder(bstnode_t* t, int item) {
    if(t) {
        if(item <= t->data){
            if(NULL == t->leftChild) {
                t->leftChild = create_node(item);
            } else {
                if(bst_recursiveAdder(t->leftChild, item) == 1) {
                    return 1;
                }
            }
        } else {
            if(NULL == t->rightChild) {
                t->rightChild = create_node(item);
                return 1;
            } else {
                if(bst_recursiveAdder(t->rightChild, item) == 1) {
                    return 1;
                }
            }
        }
    }
        return -1;
}

// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item){
    int state = -1;
    if(t) {
        if(NULL == t->root) {
            t->root = create_node(item);
            state = 1;
        } else {
            state = bst_recursiveAdder(t->root, item);
        }
    } else {
        if(state == 1) {
            t->size++;
        }
    }
    return state;
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
    }else{

    }
}

int recursiveSummer(bstnode_t* node) {
    if(node) {
        node->data = recursiveSummer(node->leftChild) + recursiveSummer(node->rightChild);
        return node->data;
    } else {
        return 0;
    }
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
  return 0;
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
  return 0;
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    if (t) {
        return t->size;
    } else {
        exit(0);
    }
    return 0;
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){

}


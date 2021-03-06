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
    //printf("BST Created!\n");
    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    // Check if NULL
    if(t == NULL) {
        exit(0);
    // Check if size is 0
    } else if(t->size == 0) {
        return 1;
    } else {
    return 0;
    }
}

int recursiveAdder(bstnode_t* curNode, bstnode_t* newNode) {
    // Check data size relative to current
    if(newNode->data <= curNode->data) {
        // Check if left exists, add
        if(curNode->leftChild == NULL) {
            // Add newNode to leftChild
            curNode->leftChild = newNode;
        } else {
            // Recursively call function
            recursiveAdder(curNode->leftChild, newNode);
        }
    // Check data size relative to current
    } else if (newNode->data > curNode->data) {
        // Check if right exists, add
        if(curNode->rightChild == NULL) {
            // Add to rightChild
            curNode->rightChild = newNode;
        } else {
            // Recursively call 
            recursiveAdder(curNode->rightChild, newNode);
        }
    }
    return 1;
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

    // Create new node, malloc as needed
    bstnode_t* newNode = (bstnode_t*)malloc(sizeof(bstnode_t));
    
    // Return -1 if NULL, per specs
    if(newNode == NULL) {
        return -1;
    }

    // Assign data using item, and NULL
    // for left and right children
    newNode->data = item;
    newNode->rightChild = NULL;
    newNode->leftChild = NULL;

    // Assign root as newNode and size if NULL
    if(t->root == NULL) {
        t->root = newNode;
        t->size ++;
        return 1;
    }
    
    // Call recursive adder and increment size
    recursiveAdder(t->root, newNode);
    t->size ++;

    return 1;
}

void print_desc(bstnode_t* node) {
    // Check if NULL
    if(node==NULL){
       return;
    } else {
        // Print starting with rightChild
        print_desc(node->rightChild);
        printf("> %d\n", node->data);
        print_desc(node->leftChild);
    }
}

void print_asc(bstnode_t* node) {
    // Cehck if NULL
    if(node==NULL){
        return;
    } else {
        // Print ASC starting with leftChild
        print_asc(node->leftChild);
        printf("> %d\n", node->data);
        print_asc(node->rightChild);
    }
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    // Check if NULL first
    if(NULL == t){
        printf("(NULL)");
    } else {
        if(order == 0) {
            // If order 0, ASC
            print_asc(t->root);
            // If order not 0, desc
        } else {
            print_desc(t->root);
        }
    }
}

int recursiveSummer(bstnode_t* node) {
 
    // Check if NULL   
    if(node == NULL) {
        return 0;
    } else {

        // Variables to store sum for 
        // left and right children
        int recSumLeft = 0;
        int recSumRight = 0;

        // Check if NULL, otherwise sum recursively
        if(node->leftChild != NULL) {
            recSumLeft = recursiveSummer(node->leftChild);
        }
        // Check if NULL, other sum recursively
        if(node->rightChild != NULL) {
            recSumRight = recursiveSummer(node->rightChild);
        }

        //printf("RecSumLeft: %d\n", recSumLeft);
        //printf("recSumRifght: %d\n", recSumRight);
        //printf("node->data: %d\n", node->data);
    
        int sum = node->data + recSumLeft + recSumRight;

        return sum;
    }
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){

    // Check if NULL
    if(t==NULL) {
        exit(0);
    } else {
        // Call function recursively from root
        return recursiveSummer(t->root);
    }
}


int recursiveFinder(bstnode_t* node, int value) {
    // Check for given value
    if(node->data == value) {
        return 1;
    } else {
        // Check when less than value and not NULL per TAs recommendation
        if(value < node->data && node->leftChild != NULL) {
            recursiveFinder(node->leftChild, value);
        // Check when greater than value and not NULL per TAs recommendation
        } else if(value > node->data && node->rightChild != NULL) {
            recursiveFinder(node->rightChild, value);
        }
    return 0;
    }
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
    // Check of null, exit
    if(t==NULL) {
        exit(0);
    } else {

        //printf("bst_find searching for: %d\n", value);
        // If not null, call recursively
        return recursiveFinder(t->root, value);
    }
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    // Check if null, otherwise return size
    if (t==NULL) {
        exit(0);
    } else {
        return t->size;
    }
}

void recursiveFreeing(bstnode_t* node) {
    // Check if null, otherwise free everything
    if(node != NULL) {
        // Free left, then right, then node
        recursiveFreeing(node->leftChild);
        recursiveFreeing(node->rightChild);
        free(node);
    } else {
        return;
    }
}


// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){

    if(t){
        // Call recursive function, then
        // free t itself
        recursiveFreeing(t->root);
        free(t);

    }
}


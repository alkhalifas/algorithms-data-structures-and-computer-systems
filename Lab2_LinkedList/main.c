// Modify this file
// compile with: gcc main.c linkedlist.c -o prog

#include <stdio.h>

#include "linkedlist.h"

/* Linked list to exercise creating 5 elements */
void unitTest1(){
    // Create our linked list
    linkedlist_t* myList = CreateLinkedListOfFiveItems();
    // Print out our list so we can verify the contents
    PrintLinkedList(myList);
    // Free our list when we are done
    // This frees the 'heap' memory
    FreeLinkedList(myList);
}

/* Linked list to exercise appending to an empty linked list */
void unitTest2(){
    // Create our linked list
    linkedlist_t* myList = CreateLinkedList();
    // Append one item to our list
    AppendToLinkedList(myList,42);
    // Print out our list to verify the contents
    PrintLinkedList(myList);
    // Free our list when we are done
    // This frees the 'heap' memory
    FreeLinkedList(myList);
}

/* Linked list to exercise creating and deleting an empty list*/
void unitTest3(){
    // Create our linked list
    linkedlist_t* myList = CreateLinkedList();
    // Free our list when we are done
    // This frees the 'heap' memory
    FreeLinkedList(myList);
}

void unitTest4() {
    // Create linked list
    linkedlist_t* myList = CreateLinkedList();
    // Store 10 nodes
    AppendToLinkedList(myList, 1);
    AppendToLinkedList(myList, 1);
    AppendToLinkedList(myList, 2);
    AppendToLinkedList(myList, 3);
    AppendToLinkedList(myList, 5);
    AppendToLinkedList(myList, 7);
    AppendToLinkedList(myList, 12);
    AppendToLinkedList(myList, 19);
    AppendToLinkedList(myList, 31);
    AppendToLinkedList(myList, 50);
    // Print the list
    PrintLinkedList(myList);
    // Free memory
    FreeLinkedList(myList);
}

int main(){
  
    // Call our unit Test. A unit test is a test that
    // exercises some functionality in our program, often
    // a feature or short sequence of events.
    unitTest1();
    // Call another unit test
    unitTest2();
    // Call another unit test
    unitTest3();
    // Call another unit test
    unitTest4();
    return 0;
}

// In this file you will implement the 
// 'Function definitions'
// Recall, function definitions are the implementations
// of all of the function 'declarations' in our linkedlist.h

#include <stdlib.h>     // Included for malloc/free
#include "linkedlist.h"
#include <stdio.h>

linkedlist_t* CreateLinkedListOfFiveItems(){
   	
	// Instantiate new empty linked list 
	linkedlist_t* newLinkedList = CreateLinkedList();

	// Create nodes 1 through 5
	node_t* newNode_1 = (node_t*)malloc(sizeof(node_t));	
	newNode_1->data = 4;

	node_t* newNode_2 = (node_t*)malloc(sizeof(node_t));	
	newNode_2->data = 8;

	node_t* newNode_3 = (node_t*)malloc(sizeof(node_t));	
	newNode_3->data = 15;

	node_t* newNode_4 = (node_t*)malloc(sizeof(node_t));	
	newNode_4->data = 16;

	node_t* newNode_5 = (node_t*)malloc(sizeof(node_t));	
	newNode_5->data = 23;

	newLinkedList->head = newNode_1;
	newNode_1->next = newNode_2;
	newNode_2->next = newNode_3;
	newNode_3->next = newNode_4;
	newNode_4->next = newNode_5;
	newNode_5->next = NULL;
	
	return newLinkedList;
}

// A function that creates an empty linked list and initializes
// the head to NULL, and returns the empty list.
linkedlist_t* CreateLinkedList(){

	// Initialize pointer, allocate memory to size of struct
	linkedlist_t* newLinkedList = (linkedlist_t*)malloc(sizeof(linkedlist_t));
	// Set head to NULL
	newLinkedList->head = NULL;
	return newLinkedList;
}

// Function that walks through a linked list and
// prints the data of each node
void PrintLinkedList(linkedlist_t* list){
	// Set iterator to the lists head
	node_t* iterator = list->head;
		// Walk through the list and print data
    		while(iterator != NULL){
			printf("Data: %d\n", iterator->data);
			// Set iterator to next node
			iterator = iterator->next;
    }   
}

void AppendToLinkedList(linkedlist_t* list, int data) {
	// Case1: If list is empty, create new node and
	// add data, set head to NULL
	if(list->head == NULL){
		node_t* newNode = (node_t*)malloc(sizeof(node_t));
		newNode->data = data;
		newNode->next = NULL;

		// Set head of list to newNode
		list->head = newNode;
	// Case2: If list not empty, iterate over nodes to find end
	} else {
		// Create the iterator
		node_t* iterator = list->head;
		// Traverse the list to find the last node
		while(iterator->next != NULL) {
			iterator = iterator->next;
		}
		// Create a new node and assign data, next
		node_t* newNode = (node_t*)malloc(sizeof(node_t));
		newNode->data = data;
		newNode->next = NULL;
		// Set to next 
		iterator->next = newNode;	
	}	
}

// Walk through the nodes in a linked list, first checking for
// if list is NULL, and freeing nodes iteratively, and finally
// freeing the list itself.
void FreeLinkedList(linkedlist_t* list) {    
 	if(list == NULL){
		return;
	}
	
	node_t* current = list->head;
	if(current == NULL){
		free(list);
		return;
	}
	node_t* next = current->next;
	while(current != NULL){
		free(current);
		current = next;
	
		if(current != NULL) {
			next = current->next;
		}	   	
	}
	free(list);
}

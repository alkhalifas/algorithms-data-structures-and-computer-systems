#include <stdlib.h>  // Include for malloc/free and NULL
#include <stdio.h>   // Included for printf for testing purposes
#include "stack_t.h" // Include our function declarations and data types


// Creates a stack
stack_t* create_stack(unsigned int capacity){
	// Creating a new stack and setting size using malloc
	stack_t* my_stack = (stack_t*)malloc(sizeof(stack_t));
	// Set the stacks count, capacity, and head	
	my_stack->count = 0;
	my_stack->capacity = capacity;
	my_stack->head = NULL;
	return my_stack;
}

// Stack Empty
int stack_empty(stack_t* s){
	// Check if count is zero, indicating it is empty
	if(s->count == 0){
		return 1;
	} else {
		return 0;
	}
}

// Stack Full
int stack_full(stack_t* s){
	// Check if the count == the capacity indicating it is full
	if(s->count == s->capacity){
		return 1;
	} else {
		return 0;
	}
}

// Enqueue a new item
int stack_enqueue(stack_t* s, int item){
	//  Check if the stack is full
	if(stack_full(s) == 1){
		return -1;
	// If stack is not full:
	} else {
		// Creaet a new node, allocate memory using malloc
		node_t* newNode = (node_t*)malloc(sizeof(node_t));
		// Set data and next node for the new node
		newNode->data = item;
		newNode->next = s->head;
		s->head = newNode;
		// Increment count by 1
		s->count += 1;
		return 0;
	}
}

// Dequeue an item
int stack_dequeue(stack_t* s){
	// Check if stack is empty
	if(stack_empty(s) == 1) {
		exit(1);
	// If stack is not empty
	} else {
		// Get front node		
		int frontItem = s->head->data;
		// Get previous node
		node_t* prevNode = s->head;
		// Set stack head
		s->head = s->head->next;
		// Free up node (Do NOT remove)
		free(prevNode);
		// Decrement count
		s->count -= 1;
		// Return frontItem
		return frontItem;
	}
}

// Stack Size
unsigned int stack_size(stack_t* s){
	// Check if stack is NULL, use exit(1)
	if(s == NULL) {
		exit(1);
	// If not NULL, return the count
	} else {
		return s->count;
	}
}

// Free stack
void free_stack(stack_t* s){
	// Create a prev node and iterator
	node_t* prev;
	node_t* iterator = s->head;
	// Loop over the stack, and free memory
	// using iterator pattern
	while (iterator != NULL) {
		prev = iterator;
		iterator = iterator->next;
		free(prev);
	}
	free(s);
}

//void PrintStack(stack_t* s){
	// Set iterator to the lists head
//	node_t* iterator = s->head;
	// Walk through the list and print data
//	while(iterator != NULL){
//		printf("Data: %d\n", iterator->data);
//		iterator = iterator->next;
//	}
//}

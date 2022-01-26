#ifndef LINKED_LIST_H
#define LINKED_LIST_H
// NOTE: #ifndef, #define, and #endif are a pattern you'll
//       often see in .h files. These are called 'header guards'
//       and prevent us from accidently including our file twice.

// Create your node_t type here
typedef struct node{
    int data;
    struct node* next;
}node_t;

// Data structure for a linked list
// Holds the first node in our list
typedef struct linkedlist{
    node_t* head;
}linkedlist_t;

// Function declarations provide us a list of functions
// that exist in this header(.h) file.
// You will have to implement the 'declarations' with a 
// 'definition' (i.e. function body) in the corresponding
// '.c' file called linkedlist.c

// The job of this function is to create a linked
// list. The linked list itself will consist of 5 node_t's
// (not including the 'NULL' value at the end).
//
// THE PURPOSE of this function is to have you practice
// connecting individual nodes togther. 
// 
// If you'd like, you could implement this function first, along
// followed by 'PrintLinkedList' to test your understanding of linked
// list.
linkedlist_t* CreateLinkedListOfFiveItems();

// The job of this function is to create a list.
// - malloc for linkedlist_t
// - initialize head to NULL
// - Then return the linked list that you have created.
linkedlist_t* CreateLinkedList();

// PrintLinkedList takes a pointer to a LinkedList as the
// input. This function will iterate through a linked
// list.
// A strategy for implementing this is to create a
// temporary pointer that points to the head of the list (list->head).
// e.g. node_t* iter = list->head
void PrintLinkedList(linkedlist_t* list);

// This function will 'free' the linked list that is
// passed in. The goal is to 'delete' all of the node_t's
// (including the 'head' in the linkedlist_t) data structure.
//
// Note: A strategy is to use two iterator nodes: 
// 1.) 'current' which points to the current node
// 2.) 'next' which points to the following node.
//
// ^ This strategy will help you ensure that you can move to the next node
//   after you delete the current node. (TIP: Draw your pointers and nodes)
//
// You can run a tool like valgrind to determine if you
// have any memory leaks. (e.g. valgrind ./prog)
void FreeLinkedList(linkedlist_t* list);

// The purpose of this function is to append a new node to the end of the linked list.
// NOTE: There are two cases to consider.
// 1 - Append to a list that is empty
// 2 - Append to a list that contains at least 1 node.
void AppendToLinkedList(linkedlist_t* list,int data);

#endif

#include "hashmap_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
hashmap_t* hashmap_create(unsigned int _buckets){
    // Allocate memory for our hashmap
    hashmap_t* hashmap = (hashmap_t*)malloc(sizeof(hashmap_t));
    // Added to avoid error based on TAs recommendation
    if (hashmap == NULL) {
        return NULL;
    }
    // Set the number of buckets
    hashmap->buckets = _buckets;
    // Initialize our array of lists for each bucket
    hashmap->arrayOfLists = (node_t**)malloc(sizeof(node_t*) * _buckets);
    // Added to avoud error based on TAs recommendation
    if (hashmap->arrayOfLists == NULL) {
        return NULL;
    }
    // Setup our hashFunction to point to our
    // stringHash function
    int i;
    for (i = 0; i < _buckets; i++){
        hashmap->arrayOfLists[i] = NULL;
    }
    hashmap->hashFunction = stringHash;
    // Return the new map that we have created
    return hashmap;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap){
    // Check if not NULL
    if(_hashmap != NULL){
        int i;
        // Iterate over the buckets:
        for(i = 0; i < _hashmap->buckets; i++){
            // Iterator pattent to traverse arrayOfLists
            node_t* iterator = _hashmap->arrayOfLists[i];

            while(NULL != iterator) {
                // Set temporary variable
                node_t* tempVar = iterator;
                // Set iterator to next
                iterator = iterator->next;
                // Free the temporary variable (node)
                free(tempVar->kv->key);
                free(tempVar->kv);
                free(tempVar);
            }
        }
        // Free the arrayOfLists
        free(_hashmap->arrayOfLists);
        // Free the actual hashmap
        free(_hashmap);
    }
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t* _hashmap, char* key){
    // Conditional to return -9999 if NULL
    if (_hashmap == NULL) {
        return -9999;
    }
    // Get bucket using hashFunction
    int myBucket;
    myBucket = _hashmap->hashFunction(key, _hashmap->buckets);
    // Iterator pattern to iterative over array
    node_t* iterator = _hashmap->arrayOfLists[myBucket];
    // Check for NULL values to avoid error
    while(NULL != iterator) {
        // Use the strcmp to compare iterator key against KoI
        if(strcmp(iterator->kv->key, key) == 0){
            return 1;
        }
        // Go to next
        iterator = iterator->next;
    }
    return 0;
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value){
    // Check for NULL hashmap
    if (_hashmap == NULL) {
        return;
    }
    // Check for key // TODO: FIX THIS FUNCTION, NOT WORKING
    if (hashmap_hasKey(_hashmap, key) == 1) {
        return;
    }

    // Create and allocate memory for a new pair
    pair_t* myPair = (pair_t*)malloc(sizeof(pair_t));
    // Assign value to the new pair
    myPair->value = value;
    // Assign key to the new pair
    myPair->key = (char*)malloc((strlen(key) * sizeof(char)) + 1);
    strcpy(myPair->key, key);
     
    // Create new node and allocate memory using malloc
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    //Assign the pair, and point next to NULL for the new node
    newNode->kv = myPair;
    newNode->next = NULL;
    
    // Get bucket using hasmaps hashFunction
    int myBucket;
    myBucket = _hashmap->hashFunction(key, _hashmap->buckets);

    // Check if NULL, the add newNode   
    if (_hashmap->arrayOfLists[myBucket] == NULL) {
        _hashmap->arrayOfLists[myBucket] = newNode;
    } else {
        // Otherwise add newNode to next
        newNode->next = _hashmap->arrayOfLists[myBucket];
        _hashmap->arrayOfLists[myBucket] = newNode;
    }

}

// Return a value from a key 
// Returns NULL if the _hashmap is NULL
// Returns NULL if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time
char* hashmap_getValue(hashmap_t* _hashmap, char* key){
    //Check for NULL
    if(_hashmap == NULL) {
        return NULL;
    }

    // Get buckets using hashFunction
    int myBucket;
    myBucket = _hashmap->hashFunction(key, _hashmap->buckets);
    // Check if NULL to avoid error
    if (_hashmap->arrayOfLists[myBucket] == NULL) {
        return NULL;
    }
    // Implement iterator pattern to iterate over pairs
    node_t* iterator = _hashmap->arrayOfLists[myBucket];
    while(NULL != iterator) {
        // Check if the key values are the same
        if(strcmp(iterator->kv->key, key) == 0){
            return iterator->kv->value;
        }
        // Increment iterator
        iterator = iterator->next;
    }
    return NULL;
}

// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key){
    // Check if NULL
    if(_hashmap == NULL) {
        return;
    }
    
    // Get current bucket from hashmap
    int myBucket;
    myBucket = _hashmap->hashFunction(key, _hashmap->buckets);
    
    // Check to see if the key exists in map
    if(hashmap_hasKey(_hashmap, key)) {
        // Check to see if the key is the first item/node in list
        if(strcmp(_hashmap->arrayOfLists[myBucket]->kv->key, key) == 0) {
            // Get node to remove
            node_t* remNode = _hashmap->arrayOfLists[myBucket];
            // Set to next in list
            _hashmap->arrayOfLists[myBucket] = _hashmap->arrayOfLists[myBucket]->next;
            // Free up the memory for keys, kv, and the actual node
            free(remNode->kv->key);
            free(remNode->kv);
            free(remNode);
        
        } else {
            // Use iterator pattern to go through nodes
            node_t* iterator = _hashmap->arrayOfLists[myBucket]->next;
            // Set a counter to get the location number
            int counter;
            counter = 0;
            // Iterate over the list to find key
            while(iterator != NULL) {
                // Conditional for when key is found
                if(strcmp(iterator->kv->key, key) == 0) {
                    counter = counter + 1;
                    break;
                // Conditional to increment to next
                } else {
                    iterator = iterator->next;
                    counter = counter + 1;
                }
            }
            // Identify the previous node, and the next node in the 
            // list and set accordingly
            node_t* lastNode = _hashmap->arrayOfLists[myBucket];
            node_t* nextNode = iterator->next;
            
            // Iterate over the counter to set nodes
            int i;
            for(i = 0; i < counter - 1; i++) {
                lastNode = lastNode->next;
            }
            // Free the momory of the iterator
            free(iterator->kv->key);
            free(iterator->kv->value);
            free(iterator->kv);
            free(iterator);
 
      
        }   
    }
}


// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue){
    // Check if contains key
    if (hashmap_hasKey(_hashmap, key)){
        return;
    }
    
    // Get bucket via hashFunction
    int myBucket;
    myBucket = _hashmap->hashFunction(key, _hashmap->buckets);
    
    // Use iterator pattern
    node_t* iterator = _hashmap->arrayOfLists[myBucket];
     // Iterate over keys
    while(0 != iterator) {
        // If the keys match, return
        if(strcmp(iterator->kv->key, key)) {
                return;
        }
        // Go to next item
        iterator = iterator->next;
    }  
    // Free key from memory
    free(key); 
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap){
    // Check if not null
    if(_hashmap != NULL){
        int i;
        // Iterate over the buckets
        for(i = 0; i < _hashmap->buckets; i++) {
            // Print the number of items (pairs) in a given bucket:
            printf("Number of Items in Bucket = %d\n", i);
            
            // Implement iterator pattern to go through the items
            node_t* iterator = _hashmap->arrayOfLists[i];
            // Traverse using iterator, and print the results
            while(NULL != iterator) {
                printf("            Key = %s ------- Val = %s\n", iterator->kv->key, iterator->kv->value);
                iterator = iterator->next;
            }
        }
    }
}

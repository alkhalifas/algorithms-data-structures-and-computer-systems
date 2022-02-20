#include "hashmap_t.h"
#include <stdio.h>
#include <stdlib.h>
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
    hashmap_t* hashMap = (hashmap_t*)malloc(sizeof(hashmap_t));
    // Set the number of buckets
    hashMap->buckets = _buckets;
    // Initialize our array of lists for each bucket
    hashMap->arrayOfLists = (node_t**)malloc(sizeof(node_t*) * _buckets);
    // Setup our hashFunction to point to our
    // stringHash function.
    hashMap->hashFunction = stringHash;
    // Return the new map that we have created
    return hashMap;
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
            // Set temporary variable
            node_t* tempVar = iterator;
            // Set iterator to next
            iterator = iterator->next;
            // Free the temporary variable (node)
            free(tempVar); 
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
	//TODO
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value){
    // TODO
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
	//TODO
}

// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key){
	//TODO
}

// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue){
	//TODO
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
        for(i = 0; _hashmap->buckets; i++) {
            // Print the number of items (pairs) in a given bucket:
            printf("Number of Items in Bucket = %d\n", i);
            
            // Implement iterator pattern to go through the items
            node_t* iter = _hashmap->arrayOfLists[i];
            //printf("Current Iter = %d\n", iter->kv->key);
            while(NULL != iter) {
                printf("Current = %s ---- %s", iter->kv->key, iter->kv->value);
                iter = iter->next;
            }
        }
    }
}

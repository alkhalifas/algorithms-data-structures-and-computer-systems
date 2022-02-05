#include <stdlib.h> // malloc/free and NULL

// Include the declarations of our string functions
#include "mystring.h"

// search: 'man strlen' to see what function should do
//
//
//
size_t my_strlen(const char* input){
    int length = 0;
    while(input[length] != '\0';
        length++;
    }
    return length;   
}

// search: 'man strcmp' to see what function should do
//
//
//
//
int my_strcmp(const char* src1, const char* src2){
    // IMPLEMENT
    return 0;   
}

// search: 'man strchr' to see what function should do
//
//
//
//
char* my_strchr(const char* src1, int c){
    // IMPLEMENT
    return NULL;   
}

// search: 'man strcat' to see what function should do
// Note: Our 'string append' is going to be slightly different
//       than 'strcat'. 
//       I would like you to return a 'heap allocated' string
//       that appends both of src1 and src2 into a new buffer
char* my_string_append(const char* src1, const char* src2){
    // Compute the lengths of the two strings
    size_t src1Length = StringLength(src1);
    size_t src2Length = StringLength(src2);

    // Set storage for the new string
    char* newString = (char*)malloc(sizeof(char)*(src1Length+src2Length+1));

    // Copy first string into new string
    int i = 0;
    while(i<src1Length){
        newString[i] = src1[i];
        i++;
    }

    // Copy second string into new string
    int j = 0;
    while(j<src2Length){
        newString[src1Length+j] = src2[j];
        j++;
    }

    // Add null terminator
    newString[src1Length+src2Length] = '\0';

    return newString;   
}















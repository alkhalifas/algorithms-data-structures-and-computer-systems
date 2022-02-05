#include <stdlib.h> // malloc/free and NULL

// Include the declarations of our string functions
#include "mystring.h"

// search: 'man strlen' to see what function should do
//
//
//
size_t my_strlen(const char* input){
    int len = 0;
    while(input[len] != '\0'){
        len++;
    }
    return len;   
}

// search: 'man strcmp' to see what function should do
int my_strcmp(const char* src1, const char* src2){
    
    // Compare each and increment
    while(*src1 && (*src1==*src2)) {
        src1++;
        src2++;
    }
    return *(const unsigned char*)src1 - *(const unsigned char*)src2;   
}

// search: 'man strchr' to see what function should do
char* my_strchr(const char* src1, int c){
    
    // Traverse string until we hit character, or null
    // terminator
    while(*src1 != c && *src1 != '\0'){
        src1++;
    }

    // Once we find c, return pointer
    if(*src1 == c) {
        return src1;
    } else {
        return NULL;
    }
}

// search: 'man strcat' to see what function should do
// Note: Our 'string append' is going to be slightly different
//       than 'strcat'. 
//       I would like you to return a 'heap allocated' string
//       that appends both of src1 and src2 into a new buffer
// Note: Taken from Professor's Shah's posted video
char* my_string_append(const char* src1, const char* src2){

    // Compute the lengths of the two strings
    size_t dstLength = my_strlen(src1);
    size_t srcLength = my_strlen(src2);

    // Create home for new string using malloc
    char* newString = (char*)malloc(sizeof(char)*(dstLength+srcLength+1));

    // Copy first source into string
    int i = 0;
    while(i<dstLength){
        newString[i] = src1[i];
	i++;
    }

    // Copy second source into string
    int j = 0;
    while(j<srcLength){
        newString[dstLength+j] = src2[j];
        j++;
    }
    
    // Set null terminator
    newString[dstLength+srcLength] = '\0';

    return newString;
}
















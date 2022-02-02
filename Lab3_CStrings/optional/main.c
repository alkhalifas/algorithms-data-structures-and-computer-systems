#include <stdio.h>
#include <stdlib.h> // For malloc/free and NULL
#include <stddef.h> // Data type for size_t
                    // size_t is essentially an 'unsigned int'
// NOTE:
// You are not allowed to include <string.h> in this file.
// The reason is because the 'dynamicstring_t' that you are
// creating, should serve as a replacement for the 'string' functions


typedef struct dynamicstring{
    char* buf;  // 'buf' short for 'buffer'
                // Holds the individual characters of the string.
    size_t capacity; // How 'big' the buffer is, including the '\0' character
    size_t length;   // The length of the string, NOT including the '\0' character
                     // 

}dynamicstring_t;

// Input is a NULL terminated string
dynamicstring_t* CreateDynamicString(const char* input){
    // Create a new string
    dynamicstring_t* newstring = (dynamicstring_t*)malloc(sizeof(dynamicstring_t));
    newstring->buf      = NULL;
    newstring->capacity = 0;
    newstring->length   = 0;
    // Count the characters in input
    int i= 0;
    while(input[i]!='\0'){
        i++;
    }
    // Allocate the newstring->buf
    newstring->buf      = (char*)malloc(sizeof(char)*i+sizeof(char)); // Add one character for NULL Terminator
    newstring->capacity = i+1;        
    newstring->length   = i;        
    // Copy each character one at a time
    i=0;
    while(input[i]!='\0'){
        newstring->buf[i] = input[i];
        i++;
    }
    // Place NULL terminator chracter at the end
    newstring->buf[i] = '\0';
    // Finally return our string
    return newstring;
}

// Retrieve the string length
size_t DynamicStringLength(dynamicstring_t* str){
    return str->length;
};
// Retrieve the string capacity
size_t DynamicStringCapacity(dynamicstring_t* str){
    return str->capacity;
};
// Retrieve the string buffer
const char* DynamicStringCString(dynamicstring_t* str){
    return str->buf;
}

// Set the string to a specific new string
void DynamicStringSet(dynamicstring_t* str, char* input){
    // Compute length of input string
    // Count the characters in input
    int length= 0;
    while(input[length]!='\0'){
        length++;
    }
    // reallocate the buffer size
    str->buf = realloc(str->buf,length);
    str->length = length-1;
    str->capacity = length;
    // Set the string to the new contents
    while(length>-1){
        str->buf[length] = input[length];
        length--;
    }
}

// Append a c-style string to our dynamic string
dynamicstring_t* DynamicStringAppend(dynamicstring_t* str, const char* input){
    // Count the characters in input
    int length= 0;
    while(input[length]!='\0'){
        length++;
    }
    // Reallocate memory
    // This grows the size of the string
    str->buf = (char*)realloc(str->buf, sizeof(char)* (length + str->length));
    // Append to end of string
    int i=0;
    while(i < length){
        // Careful--we need to overwrite the last character
        str->buf[i+str->length] = input[i]; 
        i++;
    }
    // Update capacity and length
    str->length     = length + str->length;
    str->capacity   = length + str->capacity; 
    // Set the last character to the NULL Terminator
    str->buf[str->capacity-1] = '\0';
    return str;
}

int main(){

    // Test with a 'C string literal'
    dynamicstring_t* test = CreateDynamicString("Some string here");
    printf("test buf     : %s\n"   , DynamicStringCString(test));
    printf("test capacity: %ld\n"  , DynamicStringCapacity(test));
    printf("test length  : %ld\n\n", DynamicStringLength(test));

    // Test with a C-style string
    char sample[] = {'5','0','0','8','\0'};
    dynamicstring_t* test2 = CreateDynamicString(sample);
    printf("test2 buf     : %s\n"   , DynamicStringCString(test2));
    printf("test2 capacity: %ld\n"  , DynamicStringCapacity(test2));
    printf("test2 length  : %ld\n\n", DynamicStringLength(test2));

    // Test with a C-style string
    char sample2[] = {'H','e','l','l','o','\0'};
    dynamicstring_t* test3 = CreateDynamicString(sample2);
    DynamicStringAppend(test3," world");    
    DynamicStringAppend(test3," (world 2)");    
    DynamicStringAppend(test3," (world 3)");    
    printf("test3 buf     : %s\n"   , DynamicStringCString(test3));
    printf("test3 capacity: %ld\n"  , DynamicStringCapacity(test3));
    printf("test3 length  : %ld\n\n", DynamicStringLength(test3));

    // Test our Set function
    char sample3[] = {'t','e','s','t','\0'};
    dynamicstring_t* test4 = CreateDynamicString(sample2);
    DynamicStringSet(test4,"A whole new string");

    printf("test4 buf     : %s\n"   , DynamicStringCString(test4));
    printf("test4 capacity: %ld\n"  , DynamicStringCapacity(test4));
    printf("test4 length  : %ld\n\n", DynamicStringLength(test4));

    return 0;
}

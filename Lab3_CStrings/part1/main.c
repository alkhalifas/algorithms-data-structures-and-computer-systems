#include <stdio.h>  // For printf/scanf
#include <string.h> // For string functions to compare against
#include <stdlib.h> // For 'free'
#include "mystring.h"

// Declarations for some tests of our functions
// You can find the implementations at the end of the file
int len_test();
int cmp_test();
int chr_test();
int append_test();

// Entry point of our program
int main(){

    char inputBuffer[80];
    int operationNumber=-1;

    while(operationNumber!=5){
        // Reset input
        operationNumber=-1;
        printf("==========================================================\n");
        printf("\t[1] Print the length of a string\n");
        printf("\t[2] Compare two strings\n");
        printf("\t[3] Find the first occurance of a character in a string\n");
        printf("\t[4] Append two strings\n");
        printf("\t[5] QUIT\n");
        printf("What operation would you like to try? (Enter 1,2,3,4,5)\n");
        printf("==========================================================\n");

        // Retrieve the user input
        int returnvalue = scanf("%d",&operationNumber);
        // 'Some' handling of illegal input
        if(returnvalue !=1){
            // scanf is okay for this example, we'll learn some other functions later
            // http://c-faq.com/stdio/scanfprobs.html
            fflush(stdin);
            scanf("%*[^\n]");
            operationNumber=-1;
            continue;
        }

        if(1==operationNumber){
            len_test();           
        }
        else if(2==operationNumber){
            cmp_test(); 
        }
        else if(3==operationNumber){
            chr_test();
        }
        else if(4==operationNumber){
            append_test();
        }    
    }


    printf("Good bye!\n");

    return 0;
}

int len_test(){
    // s1 is short for 'string1'
    const char* s1="hello world!";

    if(strlen(s1)==my_strlen(s1)){
        printf("Test passed\n");
    }else{
        printf("Test Failed\n");
    }
    printf("\t   strlen(\"%s\")= %ld\n",s1,   strlen(s1));
    printf("\tmy_strlen(\"%s\")= %ld\n",s1,my_strlen(s1)); 
}

int cmp_test(){
    // s1 is short for 'string1'
    const char* s1="hello world!";
    const char* s2="hello world!";

    if(strcmp(s1,s2) == my_strcmp(s1,s2)){
        printf("Test passed\n");
    }else{
        printf("Test Failed\n");
    }
    printf("\t   strcmp(\"%s\",\"%s\")= %d\n",s1,s2,   strcmp(s1,s2));
    printf("\tmy_strcmp(\"%s\",\"%s\")= %d\n",s1,s2,my_strcmp(s1,s2)); 
}

// NOTE: This test is likely to segfault until you
//       implement my_strchr :)
int chr_test(){
    // s1 is short for 'string1'
    const char* s1="hello world!";
    char w = 'w';

    if(strcmp(my_strchr(s1,w),"world!")==0){
        printf("Test passed\n");
    }else{
        printf("Test Failed\n");
    }
    printf("\t   strchr(\"%s\",'%c')= %s\n",s1,w,   strchr(s1,w));
    printf("\tmy_strchr(\"%s\",'%c')= %s\n",s1,w,my_strchr(s1,w)); 

}

// NOTE: This function will likely segfault until you
//       implement 'my_string_append'
int append_test(){
    // s1 is short for 'string1'
    const char* s1="hello ";
    const char* s2="folks!";
    char* heap_string = my_string_append(s1,s2);

    char destination_buffer[13]; // Big enough buffer for two strings
    // Copy a string into the destination_buffer
    strcpy(destination_buffer,"hello ");
    strcat(destination_buffer,"folks!");
    // Set the last character expicitly to NULL
    destination_buffer[12]='\0';

    if(strcmp(destination_buffer,heap_string)==0){
        printf("Test passed\n");
    }else{
        printf("Test Failed\n");
    }
    printf("\t   destination_buffer= %s\n",destination_buffer);
    printf("\t   heap_string       = %s\n",heap_string); 

    // Don't forget to free your heap allocated string
    free(heap_string);
}

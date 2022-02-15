#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char *sent = "ASDDK SOMETHING TO KADSD SOMETHING ELSE WITH REGUSTERS";
    char *word = "ADD";

    if(strstr(sent, word) !=NULL) {
        printf("MATCH! \n");
        
    }

    return 0;
}

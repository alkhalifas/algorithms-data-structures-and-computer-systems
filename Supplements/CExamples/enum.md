> Return 1 or 0 for successful operations?
>
> I'm getting confused with returning 1 or 0 for a successful operation throughout this course. Sometimes I see 0 used for successful operations, and other times I see 1 in lecture videos and supplied code. I'm referring to success/fail and not to Boolean operations (where 1 is true and 0 is false). I think 0 is the standard for successful and 1 for fail in C?
> 

Agreed, this is sometimes inconsistent. Sometimes it varies based on the library (standard c versus a user library), and sometimes we may have used 0 or 1. For example, strcmp returns 0 on a match, we return 0 from main to indicate success, and then sometimes we use 1 to mean 'successful', '0' some other thing, and '-1' as failure. It can indeed be confusing. This is an unfortunate side effect of the C language relying on integers.

There is a way we can make things a bit better though, and this is what we will sometimes see in C code. We could simply use #define to be consistent.
Then we don't care or need to worry about the value.

```c
#define SUCCESS 1
#define ERROR 0
#define ERROR_NULL -1
#define ERROR_FULL -2
```

This solves the problem for a bit, unless some other developer redefines the symbol however! (which could happen with a common name like 'SUCCESS'.

So instead we could solve the problem again with 'enums'. Enums are simple integer values, that enumerate an integer in C. This gives us a 'type' and we thus cannot accidentally redefine it in the preprocessor.

```c
#include <stdio.h>

// Define our enum, we can specify values here
// or otherwise the compiler will automatically enumerate them.
enum status_flag{FAILURE = -1,SUCCESS=0} ;

// The return type is 'enum status_flag' meaning we will
// return any of our status_flag's (FAILURE or SUCCESS)
enum status_flag returnFailure(){
    return FAILURE;
}

int main(){

    // Compare enum status_flag with FAILURE to see if
    // a failure did in fact occcur.
    if(returnFailure() == FAILURE){
        printf("Yes, the function did something bad\n");
    }
    
    //
    if(returnFailure() != SUCCESS){
        printf("The function is not SUCCESS\n");
    }


    return 0;
}
```

So yup, good catch for the folks who wanted the code to be a bit tighter!


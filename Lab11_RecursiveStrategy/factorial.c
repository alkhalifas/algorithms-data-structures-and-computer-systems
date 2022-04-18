// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
long long int factorial(int n){

    //printf("Factorial of %d\n", n);

    // Initialize a cumulative total
    long long int total = 1;

    // Iterate over loop and decrement
    int i;
    for(i = n;i > 0; i--) {
    
        // For each element, 
        total = total * i;
        //printf("total: %d\n", total);
  
    } 
  
  return total;
};

// TODO: Implement recursive solution here
long long int factorial_rec(int n){

    // Check of n is 0 or 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // If not 0 or 1, then return
        // function with n-1
        return n * factorial_rec(n-1);
    }
}

int main(){

  // Both of these should print the same result!
  printf("factorial(10) = %lld\n",factorial(10));
  printf("factorial_rec(10) = %lld\n",factorial_rec(10));


  return 0;
}

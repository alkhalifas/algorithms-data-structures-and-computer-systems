// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) {

    printf(">>> Reached merge\n");

    // Get the left and right lengths
    // based on input values l, m, and r
    int rightLength;
    rightLength = m - l + 1;

    int leftLength;
    leftLength = r - m;

    int left[rightLength];
    int right[leftLength];

    // Populate the left and right subarrays
    int i;
    i = 0;

    // Iterate over left side and populate
    for (i = 0; i < rightLength; i++) {
        left[i] = arr[l + 1];
    }
  
    // Iterate over right side and populate
    i = 0;
    for (i = 0; i < leftLength; i++) {
        right[i] = arr[m + 1 + i];
    }

    // Iterate over the subarrays in order to compare
    // the elements of each
    i = 0;
    int j = 0;
    int n = l;
    // Compare elements to assemble array
    while (i < rightLength && j < leftLength) {
        // Set conditional of left is less than right
        if (left[i] <= right[j]) {
            arr[n] = left[i];
            i++;
        } else {
            // Set inverse logic for when greater than
            arr[n] = right[j];
            j++;
        }
        // Increment n
        n++;
    }

    // Work through the conditinoal logic for when the subarray is empty
    while (j < rightLength) {
        arr[n] = left[j];
        j++;
        n++;
    }


    while (i < leftLength) {
        arr[n] = right[j];
        j++;
        n++;
    }
  
}

// Implement your mergeSort function here
void mergeSort(int array[], int left, int right) {

    printf(">>> Reached mergeSort\n");
    // Check if left less than right
    if (left < right) {

        // Get middle pivot
        int mid = (left + right) / 2;

        // Call mergeSort recursively on each side
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Merge results
        merge(array, left, mid, right);
    }
}

// Provided below is a sort function. We have also
// provided a template for how to document functions
// to help organize your code.
// Name: sortIntegers
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size){

    printf(">>> Reached sortIntegers\n");
    mergeSort(array, 0, size - 1);
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array

  printf("|------------- 1 ------------|\n");
  sortIntegers(dataset1, 11);
  printf("|------------- 2 ------------|\n");
  sortIntegers(dataset2, 11);
  printf("|------------- 3 ------------|\n");
  sortIntegers(dataset3, 11);
  printf("|------------- 4 ------------|\n");
  sortIntegers(dataset4, 11);
  printf("|------------- 5 ------------|\n");
  sortIntegers(dataset5, 11);
  printf("|------------- 6 ------------|\n");
  sortIntegers(dataset6, 11);
  printf("|------------- 7 ------------|\n");
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);
  
  return 0;
}

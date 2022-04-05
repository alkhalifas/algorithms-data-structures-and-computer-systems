// Compile with 'make' or manually with
//                        gcc -g radio.c music.c -o radio
// Run with: ./radio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Look in the music.h file to see
// the structure of the music database.
// The .h file also includes the forward
// declarations of each of the functions made
// available.
//
// The music.c file includes the implementations
#include "music.h"

// @Name    swapStrings
// @Brief   Swaps two strings.
//          The lower string is put first
void swapStrings(char** s1, char** s2){
  if( strcmp(*s1,*s2)==0 ){
    // Strings are identical, do nothing
    return;
  }else if( strcmp(*s1,*s2) < 0 ){
    // Do nothing--we are already sorted
    return;
  }else{
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
  }
}

// @Name    bruteForceSort
// @Brief   A simple O(N*N) sorting algorithm.
void bruteForceSort(char** array, unsigned int start, unsigned int end){
    int i,j;
    for(i =start; i < end-1; i++){
        for(j =start; j < end-1; j++){
            // Note the swap here.
            swapStrings(&array[j],&array[j+1]);
        }
    }

}

// @Name    partition
// @Brief   Helper funcion for quicksort
//          char** can be acquired form musicDB_t->database
int partition(char** array, unsigned int low, unsigned int high){
    // TODO:
}

// @Name    quicksort 
// @Brief   Performs that actual sort of quicksort
//          char** can be acquired form musicDB_t->database
void quicksort(char** array, unsigned int low, unsigned int high){
    // TODO:
}



int main(){
  // Load our unsorted music file
  // We load two copies, as we will compare two sorting algorithms.

  musicDB_t* musicDatabase1 = musicDB_createDatabase("./musicdatabase.txt");
  musicDB_t* musicDatabase2 = musicDB_createDatabase("./musicdatabase.txt");
  // Print out a portion of the music database.
  printf("The first 10 entries of %d unsorted are...\n",musicDatabase1->size); 
  musicDB_printDatabase(musicDatabase1,0,10);
  printf("\n");
  
  // ===========================================
  // ===== Experiment 1 - Using Brute Force Sort ====
  // Create a clock to measure the elapsed time
  clock_t start1,end1;
  start1 = clock();
  // perform bruteForceSort after starting your timer
  bruteForceSort(musicDatabase1->database,0,musicDatabase1->size);
  end1 = clock(); 
  double experiment1 = ((double)(end1-start1)/CLOCKS_PER_SEC);
   // ===========================================
   
  // ===========================================
  // ===== Experiment 2 - Using Quick Sort ====
  //printArrayOfCharStrings(musicDatabase2,0,13593);
  // Create a clock to measure the elapsed tim
  clock_t start2,end2;
  start2 = clock();
  // perform quicksort after starting your timer
  quicksort(musicDatabase2->database,0,musicDatabase2->size);  
  end2 = clock();
  double experiment2 = ((double)(end2-start2)/CLOCKS_PER_SEC);
  // ===========================================
 
  // check correctness
  // by printing out the first few items
  const int items = 20; // change this to up to 13593
  printf("O(N*N) sort produces\n"); 
  musicDB_printDatabase(musicDatabase1,0,items);
  printf("\n quick sort produces\n"); 
  musicDB_printDatabase(musicDatabase2,0,items);  
  // ============ Results ============== 
  printf("\nResults of sorting:\n");
  printf("%f time taking for brute force\n", experiment1);
  printf("%f time taking for quick sort\n", experiment2);
  
  // Reclaim memory
  musicDB_freeDatabase(musicDatabase1);
  musicDB_freeDatabase(musicDatabase2);

  return 0;
}

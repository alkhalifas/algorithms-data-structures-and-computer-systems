#include <stdio.h>



int findMinimum(int* array, int start, int stop) {

    int minIdx = start;

    int i;

    printf("|-----------------------------------|\n");
    printf("Before - minIdx = %d\n", minIdx);
    printf("Before -    i   = %d\n", i);

    printf("Start: %d - Stop: %d\n", start, stop);

    for(i = start; i < stop; i++) {


    printf("Comparing current( %d ) with next val ( %d ) \n", array[minIdx], array[i]);

        
        if(array[i] < array[minIdx]) {
            
            minIdx = i;
            printf("New Lower Value found: %d at position %d\n", array[minIdx], minIdx);
        }

        i = i + 1;
    

    }

    printf("Dataset Minimum = %d at position %d\n", array[minIdx], minIdx);
    return 0;
}

int main() {

    int dataset1[] = {10, 1, 5, 2, 7, 9, 0, 3, 8, 6 };
    int dataset2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
    int dataset3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int dataset4[] = {55, 10, 9, 8, 3, 4, 7, 6, 5 };

    findMinimum(dataset1, 0, sizeof(dataset1)/sizeof(int));
    findMinimum(dataset2, 0, sizeof(dataset2)/sizeof(int));
    findMinimum(dataset3, 0, sizeof(dataset3)/sizeof(int));
    findMinimum(dataset4, 5, sizeof(dataset4)/sizeof(int));

    return 0;
}

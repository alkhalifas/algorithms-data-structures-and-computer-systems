# Exercises

1. What do you think the Big-O (worst-case) complexity of this algorithm is? 
2. What do you think the best-case complexity of this algorithm is? 
	- Note-- assume you do not have any information about if the array is already sorted or not.
3. Does selection sort require any additional storage beyond the original array? 
	- i.e. Did you have to allocate any extra memory to perform the sort?
5. Would the Big-O complexity change if we used a linked list instead of an array?

## Answers:

1. *The Selection Sort algorithm perfoms at O(n^2) complexity for both average and worst case scenarios. The main idea behind this algorithm is that it finds the smallest element in an unsorted array and adds it to the front of thee array. This algorithm is relatively less efficient on larger lists, and lists in reverse order, especially relative to some of its other counterparts such as Quick Sort.*
2. *The best case complexity for Selection Sort is O(n^2) since one would need to iterate over the the list, and run all comparisons to identify the minimum value regardless of whether the minimum value is already the first element to begin with.*
3. *No, Selection Sort is known as an 'in-place' sorting algorithm and does not require any additional storage.*
4. *Although LinkedLists and Arrays have different complexities for their various operations, within the confines of Selection Sort, they would still be the same because the shifting of elements is done in parallel to searching of the index locations, and would remain as O(n^2) for average and worst case.*

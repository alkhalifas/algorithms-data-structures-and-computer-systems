# Exercises

1. What do you think the Big-O (worst-case) complexity of this algorithm is? 
2. What do you think the best-case complexity of this algorithm is? 
	- Note-- assume you do not have any information about if the array is already sorted or not.
3. Does selection sort require any additional storage beyond the original array? 
	- i.e. Did you have to allocate any extra memory to perform the sort?
5. Would the Big-O complexity change if we used a linked list instead of an array?

## Answers:

1. *The Insertion Sort algorithm perfoms at O(n^2) complexity for both average and worst case scenarios because it builds the final sorted array one item at a time. This algorithm is relatively less efficient on larger lists, and lists in reverse order, especially relative to some of its other counterparts such as Quick Sort.*
2. *The best case complexity for Insertion Sort is O(n) assuming the array has already been sorted since the algorithm will only need to iterative over the array once. Without knowledge of the sorted nature, we will often find that the most common complexity will be the averge case which is O(n^2).*
3. *No, Selection Sort is known as an 'in-place' sorting algorithm and does not require any additional storage.*
4. *Although LinkedLists and Arrays have different complexities for their various operations, within the confines of Insertion Sort, they would still be the same because the shifting of elements is done in parallel to searching of the index locations, and would remain as O(n^2) for average and worst case.*

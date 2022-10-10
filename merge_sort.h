/*11/10/2020 JT header for merge_sort.

/* Merge sort to handle an unsorted DB as input.*/

#include <stdio.h>  
#include <stdlib.h>  


// Merges two subarrays of arr[].  
// First subarray is arr[l..m]  
// Second subarray is arr[m+1..r]  
void merge(struct employee_node arr[], int l, int m, int r);
  
/* l is for left index and r is right index of the  
sub-array of arr to be sorted */
void mergeSort(struct employee_node arr[], int l, int r);
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(struct employee_node A[], int size) ;


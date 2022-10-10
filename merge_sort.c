/*11/10/2020 JT Merge sort adapted from https://www.geeksforgeeks.org/merge-sort/
  /* Re arrange so we sort custom structs rather than integers ;)

/* Merge sort to handle an unsorted DB as input.*/

#include <stdio.h>  
#include <stdlib.h>
#include "main.h"

// Merges two subarrays of arr[].  
// First subarray is arr[l..m]  
// Second subarray is arr[m+1..r]  
void merge(struct employee_node  arr[], int l, int m, int r)  
{  
    int i, j, k;  
    int n1 = m - l + 1;  
    int n2 = r - m;  
  
    /* create temp arrays */
    struct employee_node L[n1], R[n2];  
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)  
        L[i] = arr[l + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[m + 1 + j];  
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray  
    j = 0; // Initial index of second subarray  
    k = l; // Initial index of merged subarray  
    while (i < n1 && j < n2) {  
        if (L[i].id_number <= R[j].id_number) {  
            arr[k] = L[i];  
            i++;  
        }  
        else {  
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  
  
    /* Copy the remaining elements of L[], if there  
    are any */
    while (i < n1) {  
        arr[k] = L[i];  
        i++;  
        k++;  
    }  
  
    /* Copy the remaining elements of R[], if there  
    are any */
    while (j < n2) {  
        arr[k] = R[j];  
        j++;  
        k++;  
    }  
}  
  
/* l is for left index and r is right index of the  
sub-array of arr to be sorted */
void mergeSort(struct employee_node  arr[], int l, int r)  
{  
    if (l < r) {  
        // Same as (l+r)/2, but avoids overflow for  
        // large l and h  
        int m = l + (r - l) / 2;  
  
        // Sort first and second halves  
        mergeSort(arr, l, m);  
        mergeSort(arr, m + 1, r);  
  
        merge(arr, l, m, r);  
    }  
}  
  
/* UTILITY FUNCTIONS for debugging*/
/* Function to print an array */
void printArray(struct employee_node  A[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", A[i].id_number);  
    printf("\n");  
}  
  

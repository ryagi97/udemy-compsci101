/*
 * Name: binarySearch.c
 * Purpose: binary search on a sorted int array
 * Author: Ryan Agius <ryagius17@gmail.com>
 */

#include <stdio.h>
#include <time.h>

#define ARR_SIZE 4096

/* returns position of item n in array, -1 if doesn't exist */
int binary_search(int array[], int array_len, int n)
{
    int pos = -1;
    int L=0, R=array_len, X, Xval;

    do
    {
        X = (L+R)/2;
        Xval = array[X];
        if (Xval == n)
            return X;
        if (Xval < n)
            L = X+1;
        else
            R = X-1;      
    } while (L != R);
    
    return -1;
}

int main(void)
{
    int arr[ARR_SIZE], i;
    int n = 5, p;

    /* populate array */
    for (i=0; i<ARR_SIZE; i++) {
        arr[i] = i;
    }

    clock_t t;
    t = clock();
    p = binary_search(arr, ARR_SIZE, n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("binary_search() with an array of size %d took %f seconds to execute \n", ARR_SIZE, time_taken);
    printf("Item %d located at position %d\n", n, binary_search(arr, ARR_SIZE, n));

    return 0;
}
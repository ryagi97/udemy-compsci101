/*
 * Name: circularArray.c
 * Purpose: Implementation of a circular array
 * Author: Ryan Agius <ryagius17@gmail.com>
 */

#include <stdio.h>

#define ARRAY_LENGTH 10

/* zero all members of an integer array */
void zero_array(int array[], int array_length)
{
    for (int i = 0; i < array_length; i++)
        array[i] = 0;
}

void insert_array_front(int array[], int value, int array_length, int *idx_front)
{
    *idx_front = (*idx_front + array_length - 1)%array_length;
    array[*idx_front] = value;
}

void insert_array_back(int array[], int value, int array_length, int *idx_back)
{
    array[*idx_back] = value;
    *idx_back = (*idx_back + 1)%array_length;
}

int main(void)
{
    int array[ARRAY_LENGTH], i;
    int idx_front, idx_back;
    zero_array(array, ARRAY_LENGTH);

    idx_front = 0;
    idx_back = 0;

    insert_array_back(array, 42, ARRAY_LENGTH, &idx_back);
    insert_array_back(array, 46, ARRAY_LENGTH, &idx_back);
    insert_array_back(array, 58, ARRAY_LENGTH, &idx_back);

    insert_array_front(array, 24, ARRAY_LENGTH, &idx_front);
    insert_array_front(array, 12, ARRAY_LENGTH, &idx_front);
    insert_array_front(array, 8, ARRAY_LENGTH, &idx_front);

    for (i=0; i<ARRAY_LENGTH; i++) {

        printf("%d ", array[(idx_front + i)%ARRAY_LENGTH ]);
    }
    printf("\n");

    return 0;
}
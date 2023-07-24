#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * selection_sort - Sorts an array of integers in
 * ascending order using Selection sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
size_t x, y, min_index;
int temp;    

if (array == NULL || size < 2)
        return;

    for (x = 0; x < size - 1; x++)
    {
        min_index = x;

        for (y = x + 1; y < size; y++)
        {
            if (array[y] < array[min_index])
                min_index = y;
        }

        if (min_index != x)
        {
            /* Swap elements */
            temp = array[x];
            array[x] = array[min_index];
            array[min_index] = temp;

            /* Print the array after each swap */
            print_array(array, size);
        }
    }
}


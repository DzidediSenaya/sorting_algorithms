#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * counting sort algorithm.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    size_t i;
    int max_val;
    int *counting_array, *output_array;

    if (array == NULL || size < 2)
        return;

    max_val = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max_val)
            max_val = array[i];
    }

    counting_array = malloc((max_val + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    for (i = 0; i <= (size_t)max_val; i++)
        counting_array[i] = 0;

    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    for (i = 1; i <= (size_t)max_val; i++)
        counting_array[i] += counting_array[i - 1];

    output_array = malloc(size * sizeof(int));
    if (output_array == NULL)
    {
        free(counting_array);
        return;
    }

    for (i = size - 1; i > 0; i--)
    {
        output_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    free(counting_array);
    free(output_array);
}


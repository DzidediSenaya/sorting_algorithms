#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Returns the maximum element from the array
 * @array: The array to be checked
 * @size: Size of the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * countingSort - Sorts the array using counting sort
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: Current exponent
 * @output: The output array to store the sorted elements
 */
void countingSort(int *array, ssize_t size, int exp, int *output)
{
    int count[10] = {0};
    ssize_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * the Radix sort algorithm (Least Significant Digit)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
    int exp;
    int max;
    int *output;

    if (array == NULL || size < 2)
        return;

    max = getMax(array, size);
    output = malloc(sizeof(int) * size);

    if (output == NULL)
        return;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp, output);
        print_array(array, size);
    }

    free(output);
}


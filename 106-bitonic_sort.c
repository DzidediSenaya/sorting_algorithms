#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bitonic_sort_recursive(int *array, size_t size, int dir, size_t length);
void bitonic_merge(int *array, size_t size, int dir, size_t length);
void swap(int *a, int *b, size_t length);

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, size, 1, size);
}

/**
 * bitonic_sort_recursive - Recursive helper function for Bitonic sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Direction (1 for ascending, 0 for descending)
 * @length: The current length of the sequence being processed
 */
void bitonic_sort_recursive(int *array, size_t size, int dir, size_t length)
{
    size_t half;
    if (size > 1)
    {
        half = size / 2;
        bitonic_sort_recursive(array, half, 1, length);
        bitonic_sort_recursive(array + half, half, 0, length);
        bitonic_merge(array, size, dir, length);
    }
}

/**
 * bitonic_merge - Merges two halves of an array in a bitonic sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Direction (1 for ascending, 0 for descending)
 * @length: The current length of the sequence being processed
 */
void bitonic_merge(int *array, size_t size, int dir, size_t length)
{
    size_t half;
    size_t i;

    if (size > 1)
    {
        half = size / 2;
        for (i = 0; i < half; i++)
        {
            if (dir == (array[i] > array[i + half]))
                swap(&array[i], &array[i + half], length);
        }
        bitonic_merge(array, half, dir, length);
        bitonic_merge(array + half, half, dir, length);
    }
}

/**
 * swap - Swaps two elements in the array and prints the array after swapping
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 * @length: The current length of the sequence being processed
 */
void swap(int *a, int *b, size_t length)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    print_array(a, length);
}


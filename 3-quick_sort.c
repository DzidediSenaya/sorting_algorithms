#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * lomuto_partition - Partitions the array using
 * Lomuto scheme
 * @array: The array to be sorted
 * @low: Lower index of the partition to be sorted
 * @high: Higher index of the partition to be sorted
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high)
{
int pivot = array[high];
int x = low - 1;
int y;

for (y = low; y <= high - 1; y++)
{
if (array[y] <= pivot)
{
x++;
swap(&array[x], &array[y]);
}
}
swap(&array[x + 1], &array[high]);

return (x + 1);
}


/**
 * quick_sort_helper - Recursive function to
 * perform Quick sort
 * @array: The array to be sorted
 * @low: Lower index of the partition to be sorted
 * @high: Higher index of the partition to be sorted
 */
void quick_sort_helper(int *array, int low, int high)
{
if (low < high)
{
int pivot_index = lomuto_partition(array, low, high);

quick_sort_helper(array, low, pivot_index - 1);
quick_sort_helper(array, pivot_index + 1, high);
}
}

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_helper(array, 0, size - 1);
}


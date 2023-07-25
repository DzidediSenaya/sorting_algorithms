#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void quick_sort_recursive_hoare(int *array, int low, int high);
int hoare_partition(int *array, int low, int high);
void swap_elements(int *a, int *b);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 * order using Quick sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive_hoare(array, 0, size - 1);
}

/**
 * quick_sort_recursive_hoare - Recursive function to perform
 * Quick sort using Hoare partition
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_recursive_hoare(int *array, int low, int high)
{
if (low < high)
{
int pivot = hoare_partition(array, low, high);
quick_sort_recursive_hoare(array, low, pivot);
quick_sort_recursive_hoare(array, pivot + 1, high);
}
}

/**
 * hoare_partition - Performs the Hoare partition for Quick sort
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element after partition
 */
int hoare_partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1;
int j = high + 1;

while (1)
{
do
{
i++;
}
while (array[i] < pivot);

do
{
j--;
}
while (array[j] > pivot);

if (i >= j)
return (j);

swap_elements(&array[i], &array[j]);
}
}

/**
 * swap_elements - Swaps two integer elements
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_elements(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}


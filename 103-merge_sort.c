#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of an array
 * @array: The original array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
size_t i, j, k;
i = j = k = 0;

while (i < left_size && j < right_size)
{
if (left[i] <= right[j])
array[k++] = left[i++];
else
array[k++] = right[j++];
}
while (i < left_size)
array[k++] = left[i++];

while (j < right_size)
array[k++] = right[j++];
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * Merge sort algorithm (Top-Down)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
size_t mid, left_size, right_size, i;
int *temp_array, *left, *right;

if (array == NULL || size < 2)
return;

mid = size / 2;
left_size = mid;
right_size = size - mid;
left = array;
right = array + mid;

merge_sort(left, left_size);
merge_sort(right, right_size);

printf("Merging...\n[left]: ");
print_array(left, left_size);
printf("[right]: ");
print_array(right, right_size);

temp_array = malloc(size * sizeof(int));
if (temp_array == NULL)
return;

merge(temp_array, left, left_size, right, right_size);

for (i = 0; i < size; i++)
array[i] = temp_array[i];

printf("[Done]: ");
print_array(array, size);

free(temp_array);
}


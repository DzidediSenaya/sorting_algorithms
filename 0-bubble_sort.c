#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
int temp;
size_t x, y;

if (array == NULL || size < 2)
return;

for (x = 0; x < size - 1; x++)
{
for (y = 0; y < size - x - 1; y++)
{
if (array[y] > array[y + 1])
{
/* Swap elements */
temp = array[y];
array[y] = array[y + 1];
array[y + 1] = temp;
/* Print the array after each swap */
print_array(array, size);
}
}
}
}


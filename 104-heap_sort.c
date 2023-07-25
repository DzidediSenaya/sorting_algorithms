#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * sift_down - Restores the max heap property by sifting down
 * @array: The array to be sorted
 * @size: Size of the array
 * @idx: Index of the element to sift down
 * @len: Length of the heap (excluding the sorted elements)
 */
void sift_down(int *array, size_t size, size_t idx, size_t len)
{
size_t left, right, max;

while ((left = 2 * idx + 1) < len)
{
right = left + 1;
max = left;

if (right < len && array[left] < array[right])
max = right;

if (array[idx] >= array[max])
break;

swap(&array[idx], &array[max]);
print_array(array, size);

idx = max;
}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm (Sift-Down Heap Sort)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size < 2)
return;

for (i = (size / 2) - 1; i >= 0; i--)
sift_down(array, size, i, size);

for (i = size - 1; i > 0; i--)
{
swap(&array[0], &array[i]);
print_array(array, size);
sift_down(array, size, 0, i);
}
}


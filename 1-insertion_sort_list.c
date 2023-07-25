#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current = (*list)->next;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (current != NULL)
{
listint_t *insertion_point = current->prev;
listint_t *next_node = current->next;

while (insertion_point != NULL &&
	insertion_point->n > current->n)
{
insertion_point->next = current->next;
if (current->next != NULL)
current->next->prev = insertion_point;

current->next = insertion_point;
current->prev = insertion_point->prev;

if (insertion_point->prev != NULL)
insertion_point->prev->next = current;
insertion_point->prev = current;

if (current->prev == NULL)
*list = current;

insertion_point = current->prev;
print_list(*list);
}
current = next_node;
}
}


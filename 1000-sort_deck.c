#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_nodes(deck_node_t *node1, deck_node_t *node2);
size_t list_length(const deck_node_t *list);
int compare_cards(const void *card1, const void *card2);
int get_value_index(const char *value);

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(deck_node_t *node1, deck_node_t *node2)
{
if (node1->prev)
node1->prev->next = node2;
if (node2->next)
node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;
node1->prev = node2;
node2->next = node1;
}

/**
 * list_length - Returns the length of a doubly linked list
 * @list: Pointer to the head of the list
 * Return: Length of the list
 */
size_t list_length(const deck_node_t *list)
{
size_t len = 0;
while (list)
{
len++;
list = list->next;
}
return len;
}

/**
 * compare_cards - Helper function to compare two cards
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 * Return: Positive number if card1 > card2,
 *         Negative number if card1 < card2,
 *         Zero if card1 == card2
 */
int compare_cards(const void *card1, const void *card2)
{
const card_t *c1 = (const card_t *)card1;
const card_t *c2 = (const card_t *)card2;
int value_diff = get_value_index(c1->value) - get_value_index(c2->value);

if (value_diff != 0)
return value_diff;

return c1->kind - c2->kind;
}

/**
 * get_value_index - Helper function to get the index of a card value
 * @value: Value of the card
 * Return: Index of the card value
 */
int get_value_index(const char *value)
{
int (i);
static const char *values[] = {
"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
};

for (i = 0; i < 13; i++)
{
if (strcmp(value, values[i]) == 0)
return (i);
}

return (-1);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double pointer to the head of the deck
 *
 * This function sorts a deck of cards in ascending order according to the
 * values and kinds of the cards. The sorting is done in-place by swapping
 * the nodes of the doubly linked list that represents the deck.
 */
void sort_deck(deck_node_t **deck)
{
size_t len;
size_t i;
deck_node_t *current;
const card_t **cards;

if (deck == NULL || *deck == NULL)
return;

len = list_length(*deck);
cards = malloc(len * sizeof(const card_t *));
if (!cards)
return;

current = *deck;
for (i = 0; i < len; i++)
{
cards[i] = current->card;
current = current->next;
}
qsort(cards, len, sizeof(card_t *), compare_cards);
current = *deck;
for (i = 0; i < len; i++)
{
current->card = cards[i];
current = current->next;
}
free(cards);
}

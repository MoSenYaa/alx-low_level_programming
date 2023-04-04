#include "lists.h"
#include <stdio.h>

/**
 * listint_len - Returns the number of elements in a linked list of integers.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t listint_len(const listint_t *h)
{
    // Initialize a variable to count the number of nodes in the list
    size_t nodes = 0;

    // Iterate through the linked list using a while loop
    while (h)
    {
        // Increment the node count and update the pointer to the next node in the list
        nodes++;
        h = h->next;
    }

    // Return the number of nodes in the list
    return (nodes);
}

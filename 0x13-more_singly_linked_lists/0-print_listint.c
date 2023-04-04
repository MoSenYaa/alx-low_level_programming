#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a linked list of integers.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
    // Initialize a variable to count the number of nodes in the list
    size_t nodes = 0;

    // Iterate through the linked list using a while loop
    while (h)
    {
        // Increment the node count and print the value of the current node
        nodes++;
        printf("%d\n", h->n);
        
        // Update the pointer to the next node in the list
        h = h->next;
    }

    // Return the number of nodes in the list
    return (nodes);
}

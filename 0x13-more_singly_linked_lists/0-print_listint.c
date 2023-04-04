#include "lists.h"     /* Include the header file that defines the listint_t type and other functions */
#include <stdio.h>      /* Include the standard input/output library */

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: A pointer to the head of the list_t list.
 *
 * Return: The number of nodes in the list_t list.
 */
size_t print_listint(const listint_t *h)
{
	size_t nodes = 0;   /* Initialize the count of nodes to 0 */

	/* Loop through the list until the end is reached (h is NULL) */
	while (h)
	{
		nodes++;        /* Increment the count of nodes */
		printf("%d\n", h->n);   /* Print the value of the current node */
		h = h->next;    /* Move to the next node in the list */
	}

	return (nodes);     /* Return the count of nodes in the list */
}


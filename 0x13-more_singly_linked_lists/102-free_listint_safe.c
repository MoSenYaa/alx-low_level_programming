#include "lists.h"

/**
 * looped_listint_count - Counts the number of unique nodes in a looped listint_t linked list
 * @head: A pointer to the head of the listint_t to check
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_count(listint_t *head)
{
    /* Declare two pointers to traverse the list */
	listint_t *tortoise, *hare;
    /* Declare variable to count number of unique nodes in the list */
	size_t nodes = 1;

    /* Check if the head or next node is NULL */
	if (head == NULL || head->next == NULL)
		return (0);

    /* Initialize tortoise and hare to head and the node after head */
	tortoise = head->next;
	hare = (head->next)->next;

    /* Traverse the list until hare reaches the end (NULL) */
	while (hare)
	{
        /* If tortoise and hare meet, the list is looped */
		if (tortoise == hare)
		{
            /* Return to the head and traverse the list to count the number of nodes before the loop */
			tortoise = head;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

            /* Traverse the loop to count the number of nodes within the loop */
			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			}

            /* Return the total number of unique nodes in the looped list */
			return (nodes);
		}

        /* Traverse the list with the tortoise pointer moving one node at a time and the hare pointer moving two nodes at a time */
		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

    /* If the list is not looped, return 0 */
	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely (i.e., can free lists containing loops)
 * @h: A pointer to the address of the head of the listint_t list
 *
 * Return: The size of the list that was freed
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t nodes, index;

    /* Get the number of unique nodes in the looped list */
	nodes = looped_listint_count(*h);

    /* If the list is not looped */
	if (nodes == 0)
	{
        /* Traverse the list and free each node */
		for (; h != NULL && *h != NULL; nodes++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
	}

    /* If the list is looped */
	else
	{
        /* Traverse the list and free each node within the loop */
		for (index = 0; index < nodes; index++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}

        /* Set the head of the list to NULL */
		*h = NULL;
	}

    /* Set the h pointer to NULL */
	h = NULL;

    /* Return the number of nodes freed */
	return (nodes);
}

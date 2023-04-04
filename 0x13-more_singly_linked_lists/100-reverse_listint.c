#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t list.
 * @head: A pointer to the address of the head of the list_t list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	/* Declare two pointers to track nodes during reversal */
	listint_t *ahead, *behind;

	/* Check if the list is empty or head is NULL */
	if (head == NULL || *head == NULL)
		return (NULL);

	/* Set behind to NULL to initialize the reversal */
	behind = NULL;

	/* Traverse the list and reverse the pointers */
	while ((*head)->next != NULL)
	{
		ahead = (*head)->next;  /* Save the next node in ahead */
		(*head)->next = behind; /* Point the current node to behind */
		behind = *head;         /* Move behind pointer forward */
		*head = ahead;          /* Move head pointer forward */
	}

	/* Point the last node to behind to complete reversal */
	(*head)->next = behind;

	return (*head);
}

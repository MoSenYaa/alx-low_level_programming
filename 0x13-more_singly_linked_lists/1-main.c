#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    // Declare variables to hold the head of the list, a new node, and the number of nodes in the list
    listint_t *head;
    listint_t *new;
    listint_t hello = {8, NULL};
    size_t n;

    // Initialize the head of the list to the first node in the list
    head = &hello;

    // Create a new node using malloc
    new = malloc(sizeof(listint_t));

    // Check if malloc failed to allocate memory for the new node
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }

    // Set the value of the new node and make it the new head of the list
    new->n = 9;
    new->next = head;
    head = new;

    // Count the number of nodes in the list using listint_len
    n = listint_len(head);

    // Print the number of nodes in the list
    printf("-> %lu elements\n", n);

    // Free the memory allocated to the new node
    free(new);

    // Return 0 to indicate successful execution of the program
    return (0);
}

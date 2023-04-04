#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Entry point of the program
 * 
 * Return: Always 0
 */
int main(void)
{
    // Define a new list node and initialize it with a value of 8 and a NULL pointer to the next node
    listint_t hello = {8, NULL};
    
    // Initialize the head pointer to point to the first node of the list
    listint_t *head = &hello;
    
    // Allocate memory for a new node and initialize it with a value of 9
    listint_t *new = malloc(sizeof(listint_t));
    if (new == NULL)
    {
        printf("Error: Unable to allocate memory\n");
        return (1);
    }
    new->n = 9;
    
    // Insert the new node at the beginning of the list by updating the head pointer
    new->next = head;
    head = new;
    
    // Print the elements of the list using the print_listint function
    size_t n = print_listint(head);
    printf("-> %lu elements\n", n);
    
    // Free the memory allocated for the new node to prevent a memory leak
    free(new);
    
    return (0);
}

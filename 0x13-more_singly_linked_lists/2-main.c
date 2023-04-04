#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - Test function for add_nodeint() and print_listint()
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *head = NULL;
    int nums[] = {0, 1, 2, 3, 4, 98, 402, 1024};
    size_t num_count = sizeof(nums) / sizeof(int);
    size_t i;

    for (i = 0; i < num_count; i++)
        add_nodeint(&head, nums[i]);

    print_listint(head);

    return (0);
}

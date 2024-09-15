#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp = *head;
    unsigned int i = 0;

    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    while (i < index && tmp != NULL)
    {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)
        return (-1);

    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;

    free(tmp);
    return (1);
}
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current;
    listint_t *new;
    int i
    
    current = *head;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);
    new->n = number;
    i = 0;
    while (current != NULL) {
        i++;
        if (current->next == NULL) {
            current->next == new;
            new->next == NULL;
        }
        if (current->next->n > number) {
            new->next = current->next;
            current->next = new;
        }
    } 

}
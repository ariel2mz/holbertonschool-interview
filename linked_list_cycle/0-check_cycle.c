#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - prints all elements of a listint_t list
 * @list: pointer to head of list
 * Return: number of nodes
 */
int check_cycle(listint_t *list)
{
listint_t *uno = list;
listint_t *dos = list;

while (dos != NULL && dos->next != NULL)
{
uno = uno->next;
dos = dos->next->next;
if (dos == uno)
return 1;
}
return 0;
}

#include "lists.h"

/**
 * find_listint_loop - aaaaa
 * @head: aaaaaaaa
 *
 * Return: aaaaaaa
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *antes, *dsps;

if (!head || !head->next)
return (NULL);

antes = head;
dsps = head;
while (dsps && dsps->next)
{
antes = antes->next;
dsps = dsps->next->next;

if (antes == dsps)
{
antes = head;
while (antes != dsps)
{
antes = antes->next;
dsps = dsps->next;
}
return (antes);
}
}
return (NULL);
}

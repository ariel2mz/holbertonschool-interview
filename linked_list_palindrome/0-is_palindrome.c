#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int is_palindrome(listint_t **head)
{
if (head == NULL || *head == NULL)
return 1;
listint_t *current = *head;
int length = 0;
while (current != NULL)
{
length++;
current = current->next;
}

int *values = malloc(sizeof(int) * length);
if (values == NULL)
return 0;

current = *head;
for (int i = 0; i < length; i++)
{
values[i] = current->n;
current = current->next;
}

for (int i = 0, j = length - 1; i < j; i++, j--)
{
if (values[i] != values[j])
{
free(values);
return 0;
}
}
   
free(values);
return 1;
}

#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - sadasdasdas
 * @list: asdasdasdas
 * @str: sadasdasdas
 *
 * Return: sadsdsadas
 */
List *add_node_end(List **list, char *str)
{
List *nuevo, *last;

if (!list || !str)
return (NULL);

nuevo = malloc(sizeof(List));
if (!nuevo)
return (NULL);

nuevo->str = strdup(str);
if (!new_node->str)
{
free(nuevo);
return (NULL);
}

if (!*list)
{
nuevo->prev = nuevo;
nuevo->next = nuevo;
*list = nuevo;
}
else
{
last = (*list)->prev;

nuevo->next = *list;
nuevo->prev = last;

last->next = nuevo;
(*list)->prev = nuevo;
}

return (nuevo);
}

/**
 * add_node_begin - asdsa
 * @list: sadasdsdsa
 * @str: asdasdsadsa
 *
 * Return: asdsads
 */
List *add_node_begin(List **list, char *str)
{
List *nuevo, *last;

if (!list || !str)
return (NULL);

nuevo = malloc(sizeof(List));
if (!nuevo)
return (NULL);

nuevo->str = strdup(str);
if (!nuevo->str)
{
free(nuevo);
return (NULL);
}

if (!*list)
{
nuevo->prev = nuevo;
nuevo->next = nuevo;
*list = nuevo;
}
else
{
last = (*list)->prev;

nuevo->next = *list;
nuevo->prev = last;

last->next = nuevo;
(*list)->prev = nuevo;

*list = nuevo;
}

return (nuevo);
}

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
    List *new_node, *last;

    if (!list || !str)
        return (NULL);

    new_node = malloc(sizeof(List));
    if (!new_node)
        return (NULL);

    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return (NULL);
    }

    if (!*list)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        *list = new_node;
    }
    else
    {
        last = (*list)->prev;

        new_node->next = *list;
        new_node->prev = last;

        last->next = new_node;
        (*list)->prev = new_node;
    }

    return (new_node);
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
    List *new_node, *last;

    if (!list || !str)
        return (NULL);

    new_node = malloc(sizeof(List));
    if (!new_node)
        return (NULL);

    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return (NULL);
    }

    if (!*list)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        *list = new_node;
    }
    else
    {
        last = (*list)->prev;

        new_node->next = *list;
        new_node->prev = last;

        last->next = new_node;
        (*list)->prev = new_node;

        *list = new_node;
    }

    return (new_node);
}

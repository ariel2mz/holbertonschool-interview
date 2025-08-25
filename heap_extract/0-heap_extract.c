#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - dfghjkl
 * @root: dfghjkl
 *
 * Return: sdfghjkl
 */
int heap_extract(heap_t **root)
{
    int value, last_val;
    heap_t *last_node, *current;

    if (!root || !*root)
        return (0);

    current = *root;
    value = current->n;

    if (!current->left && !current->right)
    {
        free(current);
        *root = NULL;
        return (value);
    }

    last_node = *root;
    while (last_node->right)
        last_node = last_node->right;
    while (last_node->left)
        last_node = last_node->left;
    if (last_node->parent && last_node->parent->right == last_node)
        last_node->parent->right = NULL;
    else if (last_node->parent)
        last_node->parent->left = NULL;

    last_val = last_node->n;
    free(last_node);
    (*root)->n = last_val;

    current = *root;
    while (1)
    {
        heap_t *left = current->left;
        heap_t *right = current->right;
        heap_t *largest = current;

        if (left && left->n > largest->n)
            largest = left;
        if (right && right->n > largest->n)
            largest = right;

        if (largest == current)
            break;

        int temp = current->n;
        current->n = largest->n;
        largest->n = temp;

        current = largest;
    }

    return (value);
}

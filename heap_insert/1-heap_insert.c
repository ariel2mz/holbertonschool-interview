#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * binary_tree_size aa
 * @tree: aa
 *
 * Return: aa
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/*
 * get_parent_by_index - aa
 * @root: aa
 * @index: aa
 * Return: aa
 */
binary_tree_t *get_parent_by_index(binary_tree_t *root, size_t index)
{
if (index == 1)
return (NULL);

binary_tree_t *parent = root;
size_t path[64];
int i = 0;

index = index >> 1;
while (index > 1)
{
path[i++] = index % 2;
index >>= 1;
}

while (i--)
{
if (path[i] == 0)
parent = parent->left;
else
parent = parent->right;
}

return (parent);
}

/*
 * swap_up - aa
 * @node: aa
 */
void swap_up(heap_t **node)
{
heap_t *current = *node;
int temp;

while (current->parent && current->n > current->parent->n)
{
temp = current->n;
current->n = current->parent->n;
current->parent->n = temp;

current = current->parent;
}
*node = current;
}

/*
 * heap_insert - aa
 * @root: aa
 * @value: aa
 * Return: aa
 */
heap_t *heap_insert(heap_t **root, int value)
{
if (!root)
return (NULL);

if (*root == NULL)
{
*root = binary_tree_node(NULL, value);
return (*root);
}

size_t size = binary_tree_size(*root) + 1;
binary_tree_t *parent = get_parent_by_index(*root, size);
heap_t *new_node = NULL;

if (!parent)
return (NULL);

new_node = binary_tree_node(parent, value);
if (!new_node)
return (NULL);

if (!parent->left)
parent->left = new_node;
else
parent->right = new_node;

swap_up(&new_node);
return (new_node);
}

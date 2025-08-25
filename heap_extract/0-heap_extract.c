#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>


/**
 * tree_height - adsdas
 * @tree: asdasdsa
 *
 * Return: asdasdas
 */
size_t tree_height(const heap_t *tree)
{
size_t hl = 0;
size_t hr = 0;

if (!tree)
return (0);

hl = tree->left ? 1 + tree_height(tree->left) : 0;
hr = tree->right ? 1 + tree_height(tree->right) : 0;

return (hl > hr ? hl : hr);
}

/**
 * tree_size_h - sadasdsadsa
 * @tree: asdasdasdass
 *
 * Return: asdasdas
 */
size_t tree_size_h(const binary_tree_t *tree)
{
if (!tree)
return (0);

return (1 + tree_size_h(tree->left) + tree_size_h(tree->right));
}

/**
 * _preorder - asdasdasdas
 * @tree: sadadsadsa
 * @node: sadasdasdas
 * @height: asdasdas
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
if (!tree)
return;

if (!height)
*node = tree;

_preorder(tree->left, node, height - 1);
_preorder(tree->right, node, height - 1);
}

/**
 * heapify - asdasdas
 * @root: asdasda
 */
void heapify(heap_t *root)
{
heap_t *largest = NULL;
int temp;

if (!root)
return;

largest = root;

if (root->left && root->left->n > largest->n)
largest = root->left;

if (root->right && root->right->n > largest->n)
largest = root->right;

if (largest != root)
{
temp = root->n;
root->n = largest->n;
largest->n = temp;
heapify(largest);
}
}

/**
 * heap_extract - kkkk
 * @root: kkkk
 *
 * Return: kkk
 */
int heap_extract(heap_t **root)
{
int value;
heap_t *last_node = NULL;
size_t height;

if (!root || !*root)
return (0);

value = (*root)->n;
height = tree_height(*root);

_preorder(*root, &last_node, height);

if (last_node == *root)
{
free(*root);
*root = NULL;
return (value);
}

(*root)->n = last_node->n;

if (last_node->parent->left == last_node)
last_node->parent->left = NULL;
else
last_node->parent->right = NULL;

free(last_node);
heapify(*root);

return (value);
}

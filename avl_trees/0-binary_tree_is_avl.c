#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
#include <limits.h>

/**
* height - asdasdas
* @tree: asdasdasdas
*
* Return: asdadsadas
*/
int height(const binary_tree_t *tree)
{
int lefth, righth;

if (tree == NULL)
return (0);

lefth = height(tree->left);
righth = height(tree->right);

return ((lefth > righth ? lefth : righth) +1);
}

/**
* is_bst - asdasdsa
* @tree: asdasdasdsads
* @min: sadasdasdassdas
* @max: asdasdasdsa
*
* Return: dasdasdas
*/
int is_bst(const binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);

if (tree->n <= min || tree->n >= max)
return (0);

return (is_bst(tree->left, min, tree->n) &&
is_bst(tree->right, tree->n, max));
}

/**
* is_avl_helper - sadasdas
* @tree: asdasdsa
* @min: asdasdas
* @max: sadasdas
*
* Return: sadasdas
*/
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
int lefth, righth, balance;

if (tree == NULL)
return (1);

if (tree->n <= min || tree->n >= max)
return (0);

lefth = height(tree->left);
righth = height(tree->right);
balance = lefth - righth;
if (balance < -1 || balance > 1)
return (0);

return (is_avl_helper(tree->left, min, tree->n) &&
is_avl_helper(tree->right, tree->n, max));
}

/**
* binary_tree_is_avl - asdsadsa
* @tree: asdasdsadas
*
* Return: asdasdasadas
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

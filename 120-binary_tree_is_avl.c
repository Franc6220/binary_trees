#include <stdlib.h>
#include "binary_trees.h"

/**
 * max - finds the maximum of two integers
 * @a: first integer
 * @b: second integer
 * Return: maximum of a and b
 */
static int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: height of the tree, or 0 if tree is NULL
 */
static int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (abs(left_height - right_height) > 1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}


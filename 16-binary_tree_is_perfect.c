#include "binary_trees.h"

/**
 * tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Depth of the node
 */
size_t tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree)
    {
        depth++;
        tree = tree->left;
    }
    return (depth);
}

/**
 * is_perfect_recursive - Recursively checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @depth: Depth of the tree
 * @level: Level of the current node
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
        return (depth == level + 1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (is_perfect_recursive(tree->left, depth, level + 1) &&
            is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t depth;

    if (tree == NULL)
        return (0);

    depth = tree_depth(tree);
    return (is_perfect_recursive(tree, depth, 0));
}


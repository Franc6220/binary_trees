#include "binary_trees.h"

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the binary tree
 * @index: The index of the current node
 * @node_count: The number of nodes in the binary tree
 * Return: 1 if the binary tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
    /* If tree is NULL, it's complete */
    if (tree == NULL)
        return (1);

    /* If the current index is greater than or equal to the number of nodes */
    if (index >= node_count)
        return (0);

    /* Recursively check if left and right subtrees are complete */
    return (is_complete(tree->left, 2 * index + 1, node_count) &&
            is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the binary tree
 * Return: 1 if the binary tree is a valid Max Binary Heap, otherwise 0
 */
int is_heap(const binary_tree_t *tree)
{
    /* If tree is NULL, it's not a valid Max Binary Heap */
    if (tree == NULL)
        return (0);

    /* If the left child exists and its value is greater than the root's value */
    if (tree->left && tree->left->n > tree->n)
        return (0);

    /* If the right child exists and its value is greater than the root's value */
    if (tree->right && tree->right->n > tree->n)
        return (0);

    /* Recursively check if left and right subtrees are valid Max Binary Heaps */
    if (!is_heap(tree->left) || !is_heap(tree->right))
        return (0);

    return (1);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the binary tree
 * Return: 1 if the binary tree is a valid Max Binary Heap, otherwise 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    size_t node_count = binary_tree_size(tree);

    /* Check if the binary tree is complete and a valid Max Binary Heap */
    return (is_complete(tree, 0, node_count) && is_heap(tree));
}


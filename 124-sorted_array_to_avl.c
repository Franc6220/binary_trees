#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (create_avl_tree(array, 0, size - 1, NULL));
}

/**
 * create_avl_tree - Recursively creates an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the subarray
 * @end: Index of the last element of the subarray
 * @parent: Pointer to the parent node
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *create_avl_tree(int *array, int start, int end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;

    avl_t *new_node = binary_tree_node(parent, array[mid]);
    if (new_node == NULL)
        return (NULL);

    new_node->left = create_avl_tree(array, start, mid - 1, new_node);
    new_node->right = create_avl_tree(array, mid + 1, end, new_node);

    return (new_node);
}


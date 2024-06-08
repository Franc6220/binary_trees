#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: A pointer to the first element of the array
 * @size: The number of elements in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root = NULL;
    size_t i;

    if (array == NULL || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        if (bst_insert(&root, array[i]) == NULL)
            return (NULL); // If insertion fails, return NULL
    }

    return (root);
}


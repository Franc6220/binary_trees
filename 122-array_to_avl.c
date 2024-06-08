#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: A pointer to the first element of the array
 * @size: The number of elements in the array
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        if (avl_insert(&root, array[i]) == NULL)
        {
            /* Cleanup on failure */
            binary_tree_delete(root);
            return (NULL);
        }
    }

    return (root);
}


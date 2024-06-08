#include <stdlib.h>
#include "binary_trees.h"

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to insert into the AVL tree
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (!*tree)
            return (NULL);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
        if ((*tree)->left == NULL)
            return (NULL);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
        if ((*tree)->right == NULL)
            return (NULL);
    }
    else
        return (NULL);

    *tree = binary_tree_balance(*tree);
    return (*tree);
}


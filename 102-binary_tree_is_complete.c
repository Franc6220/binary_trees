#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    int complete = 1;
    const binary_tree_t **queue;
    const binary_tree_t *node;
    size_t head = 0, tail = 0, size = 1024, i = 0;

    queue = malloc(size * sizeof(*queue));
    if (queue == NULL)
        return (0);

    queue[tail++] = tree;

    while (head < tail && complete)
    {
        node = queue[head++];

        if (node->left)
        {
            if (!complete)
            {
                complete = 0;
                break;
            }
            queue[tail++] = node->left;
        }
        else
        {
            complete = 0;
        }

        if (node->right)
        {
            if (!complete)
            {
                complete = 0;
                break;
            }
            queue[tail++] = node->right;
        }
        else
        {
            complete = 0;
        }
    }

    free(queue);
    return (complete);
}


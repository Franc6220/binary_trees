#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node, *temp;
    
    /* Return 0 if heap is empty */
    if (*root == NULL)
        return (0);

    /* Extract the value stored in the root node */
    value = (*root)->n;

    /* If the heap has only one node */
    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    /* Find the last level-order node (the rightmost node in the last level) */
    last_node = find_last_node(*root);

    /* Replace the value of the root node with the value of the last level-order node */
    (*root)->n = last_node->n;

    /* If the last node is the left child of its parent, remove the last node from its parent */
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    /* Otherwise, the last node is the right child of its parent, so remove it */
    else
        last_node->parent->right = NULL;

    /* Free the last node */
    free(last_node);

    /* Rebuild the heap if necessary */
    if (*root != NULL)
        heapify_down(*root);

    return (value);
}

/**
 * find_last_node - Finds the last level-order node of a Max Binary Heap
 * @root: Pointer to the root node of the heap
 * Return: Pointer to the last level-order node
 */
heap_t *find_last_node(heap_t *root)
{
    /* Traverse the heap level by level until the last level is reached */
    while (root->left != NULL || root->right != NULL)
    {
        /* If there is a right child, move to the right */
        if (root->right != NULL)
            root = root->right;
        /* Otherwise, move to the left */
        else
            root = root->left;
    }
    return (root);
}

/**
 * heapify_down - Rebuilds the heap downward after extracting the root node
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *max = root, *left_child, *right_child, *temp;

    /* While the root has at least one child */
    while (max->left != NULL)
    {
        left_child = max->left;
        right_child = max->right;

        /* Find the maximum child */
        if (right_child != NULL && right_child->n > left_child->n)
            max = right_child;
        else
            max = left_child;

        /* If the maximum child is greater than the root, swap them */
        if (max->n > root->n)
        {
            temp = max->n;
            max->n = root->n;
            root->n = temp;
        }
        else
            break;

        /* Move to the next level */
        root = max;
    }
}


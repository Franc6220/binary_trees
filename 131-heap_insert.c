#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify_up - Moves a node up the tree to restore the heap property
 * @heap: A pointer to the root node of the heap
 * @node: A pointer to the node to heapify up
 */
void heapify_up(heap_t **heap, heap_t *node)
{
    int temp;

    while (node->parent != NULL && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }

    if (node->parent == NULL)
        *heap = node;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the heap
 * @value: The value to insert
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent, *current;
    size_t size;

    /* Create a new node with the given value */
    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    /* If the root is NULL, make the new node the root */
    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    /* Find the parent of the new node */
    size = binary_tree_size(*root) + 1;
    parent = *root;
    while (size / 2 != 1)
    {
        if (size % 2 == 0)
            parent = parent->right;
        else
            parent = parent->left;
        size /= 2;
    }

    /* Insert the new node at the found position */
    if (size % 2 == 0)
        parent->right = new_node;
    else
        parent->left = new_node;
    new_node->parent = parent;

    /* Heapify up the new node */
    heapify_up(root, new_node);

    return (new_node);
}


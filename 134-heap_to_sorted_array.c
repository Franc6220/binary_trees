#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t heap_size, i;

    if (heap == NULL || size == NULL)
        return (NULL);

    heap_size = binary_tree_size(heap);
    *size = heap_size;

    array = malloc(heap_size * sizeof(int));
    if (array == NULL)
        return (NULL);

    for (i = 0; i < heap_size; i++)
        array[i] = heap_extract(&heap);

    return (array);
}


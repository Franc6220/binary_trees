#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Enqueues a node to the queue.
 * @queue: The queue to enqueue to.
 * @node: The node to enqueue.
 * @rear: The index of the rear of the queue.
 * Return: New rear index.
 */
size_t enqueue(binary_tree_t **queue, binary_tree_t *node, size_t rear)
{
    queue[rear] = node;
    return rear + 1;
}

/**
 * dequeue - Dequeues a node from the queue.
 * @queue: The queue to dequeue from.
 * @front: The index of the front of the queue.
 * Return: New front index.
 */
size_t dequeue(binary_tree_t **queue, size_t front)
{
    return front + 1;
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    size_t front = 0, rear = 0;
    binary_tree_t *node;
    binary_tree_t *queue[1024];  /* Assumed maximum size for simplicity */

    rear = enqueue(queue, (binary_tree_t *)tree, rear);

    while (front < rear)
    {
        node = queue[front];
        front = dequeue(queue, front);

        func(node->n);

        if (node->left)
            rear = enqueue(queue, node->left, rear);
        if (node->right)
            rear = enqueue(queue, node->right, rear);
    }
}


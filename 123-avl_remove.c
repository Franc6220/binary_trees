#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: A pointer to the root node of the tree
 * @value: The value to remove from the tree
 * Return: A pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    /* Search for the value to remove */
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        /* Node with only one child or no child */
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;

            /* No child case */
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else /* One child case */
                *root = *temp; /* Copy the contents of the non-empty child */

            free(temp);
        }
        else
        {
            /* Node with two children: Get the in-order successor (smallest
               in the right subtree) */
            avl_t *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            /* Copy the in-order successor's data to this node */
            root->n = temp->n;

            /* Delete the in-order successor */
            root->right = avl_remove(root->right, temp->n);
        }
    }

    /* If the tree had only one node then return */
    if (root == NULL)
        return root;

    /* Update the height of the current node */
    root->height = 1 + max(height(root->left), height(root->right));

    /* Get the balance factor */
    int balance = get_balance(root);

    /* If the node becomes unbalanced, then there are 4 cases */
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left =  left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}


#include "binary_trees.h"
#include <stdio.h>
/**
 * brother_empty - checks if the brother node is empty
 * @root: parent node of the brothers nodes to check
 * Return: left if has empty nodes or right if left is full
 */
heap_t **brother_empty(heap_t **root)
{
	if ((*root)->left->left == NULL || (*root)->left->right == NULL)
		return (&(*root)->left);

	if ((*root)->right->left == NULL || (*root)->right->right == NULL)
		return (&(*root)->right);

	return (&(*root)->left);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value to store in the node to be inserted
 * Return:  pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int temp = 0;

	if (*root && value > (*root)->n)
	{
		temp = (*root)->n;
		(*root)->n = value;
		value = temp;
	}

	new_node = binary_tree_node(*root, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	if ((*root)->left == NULL)
	{
		heap_insert(&((*root)->left), value);
		(*root)->left = new_node;
		return (new_node);
	}
	else if ((*root)->right == NULL)
	{
		heap_insert(&((*root)->right), value);
		(*root)->right = new_node;
		return (new_node);
	}
	heap_insert(brother_empty(root), value);

	return (new_node);
}


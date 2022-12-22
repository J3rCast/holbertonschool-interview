#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer tto the parent node of the node to create
 * @value: value of the new node
 * Return: pointer to the new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent == NULL)
	{
		parent = new_node;
		new_node->parent = NULL;
		return (new_node);
	}

	return (new_node);
}

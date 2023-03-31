#include "binary_trees.h"

/**
 * create_node - create a new node.
 *
 * @parent: parent of the node.
 * @value: value of the new node.
 *
 * Return: the new created node.
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node = NULL;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	node->n = value;

	return (node);
}
/**
 * sorted_array_to_avl - builds an AVL tree from an array.
 *
 * @array: array to convert.
 * @size: size of the array.
 *
 * Return: a pointer to the root node of the tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL)
		return (NULL);

	return (avl_tree(NULL, array, 0, size - 1));
}
/**
 * avl_tree - create a new avl tree.
 *
 * @head: head of the tree.
 * @array: array to convert into the new tree.
 * @start: start of the array(recursively pourposes).
 * @end: end of the array(recursively pourposes).
 *
 * Return: root of the new tree.
 */
avl_t *avl_tree(avl_t *head, int *array, int start, int end)
{
	avl_t *node = NULL;
	int mid = 0;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	node = create_node(head, array[mid]);
	if (node == NULL)
		return (NULL);

	if (mid != start)
		node->left = avl_tree(node, array, start, mid - 1);
	if (mid != end)
		node->right = avl_tree(node, array, mid + 1, end);

	return (node);
}

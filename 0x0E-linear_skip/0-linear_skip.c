#include "search.h"
/**
 * find_in_part - find a value in a specific part of the list.
 *
 * @list: list to search in.
 * @value: value to look for.
 *
 * Return: Node where value was find.
 */
skiplist_t *find_in_part(skiplist_t *list, int value)
{
	skiplist_t *temp = NULL;

	temp = list;

	while (temp != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n", temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
/**
 * last_index - find the last index
 *
 * @list: head of the list.
 *
 * Return: last index of the list.
 */
size_t last_index(skiplist_t *list)
{
	skiplist_t *temp = NULL;
	size_t count = 0;

	temp = list;

	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count - 1);
}
/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: Head of the sorted list to find the value.
 * @value: Value to find in the list.
 *
 * Return: A pointer on the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = NULL;
	skiplist_t *curr = NULL;
	size_t last = 0;

	if (list == NULL)
		return (NULL);
	if (list->n == value)
		return (list);

	curr = list;
	prev = list;
	last = last_index(list);

	while (curr->n < value && curr->express != NULL)
	{
		prev = curr;
		curr = curr->express;
		printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);
	}

	if (curr->express == NULL && curr->n < value)
	{
		printf("Value found between indexes [%ld] and [%ld]\n", curr->index, last);
		return (find_in_part(curr, value));
	}

	printf("Value found between indexes [%ld] and [%ld]\n", prev->index, curr->index);
	return (find_in_part(prev, value));
}

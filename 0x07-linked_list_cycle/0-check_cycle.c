#include "lists.h"
/**
 * check_cycle - check if a linked list has a cycle.
 *
 * @list: linked list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *temp = NULL;

	temp = list;
	if (temp == NULL || temp->next == NULL)
		return (0);

	temp = temp->next;

	while (temp != NULL && temp != list)
		temp = temp->next;

	if (temp == list && temp)
		return (1);

	return (0);
}

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
	listint_t *head = NULL;
	listint_t *temp = NULL;

	if (list == NULL || list->next == NULL)
		return (0);

	head = list;
	temp = list->next;

	while (temp && temp->next)
	{
		if (temp == head && temp)
			return (1);

		head = head->next;
		temp = temp->next->next;
	}

	return (0);
}

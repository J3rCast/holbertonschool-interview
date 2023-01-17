#include "lists.h"
/**
 * linked_list_len - check the length of the linked list
 * @head: head of the linked list
 *
 * Return: the length of the linked list
 */
int linked_list_len(listint_t **head)
{
	listint_t *temp = *head;
	int count = 0;

	if (*head == NULL)
		return (0);

	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	return (count);
}
/**
 * to_list - turn a linked list into a array
 * @head: head of the linked list
 * @len: length of the linked list
 *
 * Return: reversed list
 */
int *to_list(listint_t **head, int len)
{
	listint_t *temp = NULL;
	int *list;
	int i = 0;

	temp = *head;

	list = malloc(sizeof(int) * len);
	if (list == NULL)
		return (NULL);

	while (i < len)
	{
		list[i] = temp->n;
		temp = temp->next;
		i++;
	}

	return (list);
}
/**
 * is_palindrome - check if a linked list is palindrome
 * @head: head of the linked list
 *
 * Return: 1 if is palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	int len = 0;
	int *list;

	listint_t *temp = NULL;

	len = linked_list_len(head);

	list = to_list(head, len);

	temp = *head;

	len--;

	while (temp != NULL)
	{
		if (temp->n != list[len])
			return (0);

		temp = temp->next;
		len--;
	}

	free(list);
	return (1);
}

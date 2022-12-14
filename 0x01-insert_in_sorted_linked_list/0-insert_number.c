#include "lists.h"
#include <stdio.h>
/**
 * insert_node - insert a new node into the linked list
 *
 * @head: head of the linked list
 * @number: number to insert into the list
 *
 * Return: new inserted node
 */
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *new = NULL;
	listint_t *temp = NULL;
	listint_t *current = NULL;

	temp = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	if (temp->n > number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (temp != NULL && temp->n < number)
	{
		current = temp;
		temp = temp->next;
	}

	current->next = new;
	new->next = temp;
	return (new);
}

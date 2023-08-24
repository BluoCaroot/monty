#include "main.h"
/**
 * add_nodeint - adds a new node at the beginning of list
 * @head: pointer to head of list
 * @n: integer to add to list
 * Return: NULL if fail - address of new element
 */
stack_t *add_nodeint(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{

                fprintf(stderr, "Error: malloc failed\n");
                freeall(*head, info);
                exit(EXIT_FAILURE);
	}

	new->next = *head;
	new->n = n;
	(*head)->prev = new;
	new->prev = NULL;
	*head = new;

	return (new);
}

void freelist(info_t *info)
{
	int i;

	for (i = 0; i < 3; ++i)
	{
		if (info->parsed[i])
			free(info->parsed[i]);
	}
	if (info->parsed)
		free(info->parsed);
}

void freeall(stack_t *stack, info_t *info)
{
	stack_t *tmp;

	if (info)
		freelist(info);
	fclose(info->fd);
	if (stack)
		tmp = stack->next;
	if (stack)
		free(stack);
	while (tmp)
	{
		stack = tmp;
		tmp = tmp->next;
		free(stack);
	}
}

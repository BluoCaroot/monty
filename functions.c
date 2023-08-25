#include "main.h"

void _push(stack_t **st, unsigned int line_number)
{
	int j = 0, n;

	if (info->parsed[1])
	{
		if (info->parsed[1][0] == '-')
			j++;
		for (; info->parsed[1][j]; ++j)
		{
			if (!isdigit(info->parsed[1][j]))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				/*freeall(*st, info);
				*/exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
                freeall(*st, info);
                exit(EXIT_FAILURE);
	}
	n = atoi(info->parsed[1]);
	add_nodeint(st, n);
}
void _pall(stack_t **st, unsigned int line_number)
{
	stack_t *tmp = *st;

	(void) line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

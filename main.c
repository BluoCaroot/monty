#include "main.h"
#define _POSIX_C_SOURCE 200809L
/**
 * main - the start of the program
 * @argc: count of args
 * @argv: the args
 * Return: 1 on fail 0 on success
 */
info_t info[] = {{0, 0, NULL, NULL, NULL, NULL}};
int main(int argc, char **argv)
{
	size_t n = 0;
	stack_t *st;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info->fd = fopen(argv[1], "r");
	if (!info->fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while (getline(&info->opcode, &n, info->fd) != -1)
	{
		info->c++;
		parse(&st, info);
	/*	if (!info-> parsed || !info->parsed[0] || info->parsed[0][0] == '$')
			continue;
		findcmd(info);
		if (!info->f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", info->c, info->parsed[0]);
			freeall(st, info);
			exit(EXIT_FAILURE);
		}
		info->f(&st, info->c);
		freelist(info);
*/
		printf("%s", info->opcode);
	}
	printf("%d\n", info->c);
	/*freeall(st, info);
	*/return (EXIT_SUCCESS);
}

void parse(stack_t **st, info_t *info)
{
	char **tmp, *t;

	if (!info->opcode)
		return;
	tmp = malloc(sizeof(char *) * 3);
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeall(*st, info);
		exit(EXIT_FAILURE);
	}

	t = strtok(info->opcode, " ");
	strcpy(tmp[0], t);
	t = strtok(NULL, " \n\t");
	strcpy(tmp[1], t);
	tmp[2] = NULL;
	info->parsed = tmp;

}
void findcmd(info_t *info)
{
	int i, n;
	instruction_t find[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	n = sizeof(find) / sizeof(find[0]);
	for (i = 0; i < n; ++i)
	{
		if (!strcmp(info->parsed[0], find[i].opcode))
		{
			info->f = find[i].f;
			return;
		}
	}

}



#include "main.h"
/**
 * main - the start of the program
 * @argc: count of args
 * @argv: the args
 * Return: 1 on fail 0 on success
 */
info_t = {{0, 0, NULL, NULL, NULL, NULL}};
int main(int argc, char **argv)
{
	int r;
	size_t n = 0;
	stack_t *st;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	info->fd = fopen(argv[1], "r");
	if (!info->fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	
	while (r = getline(&info->opcode, &n, fd) != -1)
	{
		info->c++;
		parse(info)
		if (!info->parsed || info->parsed[0] == '$')
			continue;
		findcmd(info);
		if (!info->f)
		{
			fprintf(stderr, "L%d: unknown instruction %s", info->c, info->parsed[0]);
			freeall(st, info);
			return (EXIT_FAILURE);
		}
		handle(st, info);
		freelist(info);


	}
	freeall(st, info);
}

void parse(info_t *info)
{
	int i, cnt = 0;
	char **tmp, *t;

	if (!info->opcode)
		return;
	tmp = malloc(sizeof(char *) * 2);
	t = strtok(info->opcode, " \n\t");
	tmp[0] = strdup(t);
	t = strtok(NULL, " \n\t");
	tmp[1] = strdup(t);
	info->parsed = tmp;

}

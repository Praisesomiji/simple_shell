#include "main.h"

char *promptu(void);
size_t noarg(char **av);
size_t avlen(char **av);

/**
 * main - run commands with full path without any argument
 *
 * Return: Always (0).
 */
int main(void)
{
	char *line;
	char **av;
	pid_t cpid;
	int wstatus;

	while (1)
	{
		line = promptu();
		av = get_av(line, " ");

		/* enforce no args feature */
		noarg(av);

		cpid = creatcproc();
		if (cpid == 0)
		{
			excom(av);
		}
		else
		{
			wait(&wstatus);
			free(av);
		}
	}
	return (0);
}
/**
 * promptu - prompt user
 *
 * Return: A line of strings
 */
char *promptu(void)
{
	char *line = NULL;
	size_t len = 0;

	write(STDOUT_FILENO, "#cisfun$ ", 10);
	if (getline(&line, &len, stdin) < 0)
	{
		free(line);
		exit(98);
	}
	return (line);
}
/**
 * noarg - exits program where args are inputted with command
 * @av: argument vector - null terminated array of strings
 *
 * Return: Always 0.
 */
size_t noarg(char **av)
{
	if (avlen(av) != 1)
	{
		av[0] = "\0";
	}
	return (0);
}
/**
 * avlen - find how many strings are in an array of strings
 * @av: array of strings
 *
 * Return: Length of array.
 */
size_t avlen(char **av)
{
	size_t len = 0;

	if (av)
	{
		while (av[len])
			len++;
	}
	return (len);
}

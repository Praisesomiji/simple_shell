#include "main.h"

char *promptu(void);

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

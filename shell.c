#include "main.h"

/*char *promptu(void);*/
int _promptu(char **line_ptr);
int usepath(char *prgrm, char *cmd);
size_t noarg(char **av);

/**
 * main - run commands with full path without any argument
 *
 * Return: Always (0).
 */
int main(void)
{
	char *line = NULL;
	char **av;
	pid_t cpid;
	int wstatus;

	while (1)
	{
		if (_promptu(&line) == -1)
		{
			/* EOF */
			break;
		}

		if (*line == '\n')
		{
			free(line);
			continue;
		}
		av = splitstr(line, " ");
		free(line);
		
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
			free_av(av);
		}
	}
	return (0);
}
/**
 * usepath - use path
 * @cmd: a command
 *
 * Return: Always 0.
 */
int usepath(char *prgrm, char *cmd)
{
	int fd = open(cmd, O_RDONLY);
	if (fd == -1)
	{
		printf("%s: %s: not found\n", prgrm, cmd);
		return (1);
	}
	return (0);
}
/**
 * _promptu - prompt user
 * @line: a pointer to a string
 *
 * Return: 0 or -1.
 */
int _promptu(char **line_ptr)
{
	size_t len = 0;

	/* if interactive shell */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);

	if (getline(line_ptr, &len, stdin) == -1)
	{
		free(*line_ptr);
		write(STDOUT_FILENO, "\n", 1);
		return (-1);
	}
	return (0);
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

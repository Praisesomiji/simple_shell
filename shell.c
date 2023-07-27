#include "main.h"

char *promptu(void);
int usepath(char *prgrm, char *cmd);
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
		/*do
		{*/
		line = promptu();

		/* EOF situation */
		if (!line)
		{
			write(STDIN_FILENO, "\n", 1);
			break;
		}
		av = get_av(line, " ");
		/* enforce no args feature */
		/*noarg(av);*/
		/*}
		while (usepath(argv[0], av[0]) != 0);*/

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
 * promptu - prompt user
 *
 * Return: A line of strings
 */
char *promptu(void)
{
	char *line = NULL;
	size_t len = 0;

	write(STDOUT_FILENO, "$ ", 0);
	if (getline(&line, &len, stdin) < 0)
	{
		free(line);
		return (NULL);
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

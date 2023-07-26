#include "main.h"

int getav(size_t len, char *delim, char **av_ptr[]);
char *dupstr(char *str);

/**
 * creatcproc - create child process
 *
 * Return: Always (0);
 */
pid_t creatcproc(void)
{
	pid_t cpid = fork();

	if (cpid == -1)
	{
		perror("Error");
		exit(98);
	}
	return (cpid);
}
/**
 * excom - execute command.
 * @av: a null terminated array of arguments
 *
 * Return: Always 0;
 */
int excom(char **av)
{
	if (execve(av[0], av, environ) == -1)
		perror("Error");
	return (0);
}
/**
 * get_av - splits a string
 * @str: a string
 * @delim: delimiter
 *
 * Return: array of each word of the string
 */
char **get_av(char *str, char *delim)
{
	size_t len = 0;
	char *token, *s;
	char **av = NULL;

	s = dupstr(str);
	if (!s)
		exit(98);
	token = strtok(s, delim);
	if (token)
		if (getav(len, delim, &av) == -1)
		{
			free(s);
			exit(98);
		}

	/* Place token in the first index position in av */
	av[len] = dupstr(token);
	if (av[len] == NULL)
	{
		free(s);
		exit(98);
	}
	free(s);
	return (av);
}
/**
 * getav - splits a string
 * @len: strings count
 * @delim: delimiter
 * @av_ptr: pointer to argument vector
 *
 * Return: array of each word of the string
 */
int getav(size_t len, char *delim, char **av_ptr[])
{
	char *token = strtok(NULL, delim);

	/* Keep counting until end of array */
	len++;
	if (token)
	{
		if (getav(len, delim, av_ptr) == -1)
			return (-1);

		/* in av: put this token in its position */
		(*av_ptr)[len] = dupstr(token);
		/*(*av_ptr)[len] = NULL;*/
		if ((*av_ptr)[len] == NULL)
		{
			free_av(*av_ptr);
			return (-1);
		}
	}
	else
	{
		/* End of array: Allocate memory for av */
		*av_ptr = malloc(sizeof(**av_ptr) * (len + 1));
		if (*av_ptr == NULL)
			return (-1);

		/* Add NULL after the final string to terminate the array */
		(*av_ptr)[len] = NULL;
	}
	return (0);
}
/**
 * print_av - print argument vector without argument count
 * @av: a null terminated array of strings
 *
 * Return: Always (0);
 */
int print_av(char *av[])
{
	int c = 0;

	while (*(av + c))
	{
		printf("%s ", av[c]);
		c++;
	}
	printf("\n");
	return (0);
}
/**
 * free_av - free av and all items in it
 * @av: a null terminated array of strings
 *
 * Return: Always (0);
 */
int free_av(char *av[])
{
	int c = 0;

	while (*(av + c))
	{
		free(av[c]);
		c++;
	}
	free(av);
	return (0);
}
/**
 * dupstr - duplicate string excluding newline char
 * @str: string
 *
 * Return: String duplicate.
 */
char *dupstr(char *str)
{
	char *dup;
	size_t n = _strlen(str) - 1;

	if (str[n] == '\n')
		dup = _strndup(str, n);
	else
		dup = _strdup(str);

	return (dup);
}
/**
 * _strdup - duplicate string
 * @s: a string
 *
 * Return: String duplicate.
 */
char *_strdup(char *s)
{
	size_t n = _strlen(s);
	char *dup = _strndup(s, n);

	return (dup);
}
/**
 * _strndup - duplicate string up until n
 * @str: a string
 * @n: the length of string to be duplicated
 *
 * Return: String duplicate.
 */
char *_strndup(char *str, size_t n)
{
	char *dup;
	size_t count;

	if (!str)
		return (NULL);

	dup = malloc(sizeof(*dup) * (n + 1));
	if (!dup)
		return (NULL);

	count = 0;
	while (count < n && str[count])
	{
		dup[count] = str[count];
		count++;
	}
	dup[n] = '\0';
	return (dup);
}
/**
 * _strlen - finf the length of a string
 * @str: a string
 *
 * Return: String length.
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	if (str)
	{
		while (str[len])
		len++;
	}
	return (len);
}

#include "../main.h"

int test_strlen(void);
int test_strdup(void);
int test_splitstr(void);

/**
 * main - test util functions
 *
 * Return: ALways 0.
 */
int main(void)
{
	/*test_strlen();
	test_strdup();*/
	test_splitstr();

	return (0);
}
/**
 * test_splitstr - test splitstr
 *
 * Return: Always 0.
 */
int test_splitstr(void)
{
	char **fc = splitstr("man united fc\0", " ");
	char **_fc = splitstr("manchester\nunited\0", " ");
	char **fc_ = splitstr("manchester \nunited\0", " ");

	printf("splitstr: man united fc is %s %s %s\n", fc[0], fc[1], fc[2]);
	printf("splitstr: manchester is %s; avlen: 1 is %zu\n", _fc[0], avlen(_fc));
	printf("splitstr: manchester  is %s; avlen: 1 is %zu\n", fc_[0], avlen(fc_));

	free_av(fc);
	free_av(_fc);
	free_av(fc_);

	return (0);
}
/**
 * test_strdup - test strdup
 *
 * Return: Always 0.
 */
int test_strdup(void)
{
	char *fc = "manchester united\0";
	size_t n = _strlen(fc);
	char *dfc = _strndup(fc, 12);
	char *sfc = _strndup(fc, n);
	char *cfc = dupstr(fc);

	printf("strndup: manchester u is %s\n", dfc);
	printf("strdup: %s is %s\n", fc, sfc);
	printf("strdup: %s is %s\n", fc, cfc);

	free(dfc);
	free(sfc);
	free(cfc);

	return (0);
}
/**
 * test_strlen - test strlen
 *
 * Return: Always 0.
 */
int test_strlen(void)
{
	char *fc = "manchester united\0";
	size_t n = _strlen(fc);
	char *name = "Praise\0";
	size_t m = _strlen(name);

	printf("strlen: 17 is %lu\n", n);
	printf("strlen: 6 is %lu\n", m);
	return (0);
}

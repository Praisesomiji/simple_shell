#include "main.h"

int test_strlen(void);
int test_strdup(void);

/**
 * main - test util functions
 *
 * Return: ALways 0.
 */
int main(void)
{
	test_strlen();
	test_strdup();

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
	char *cfc = _strdup(fc);

	printf("strndup: manchester u is %s\n", dfc);
	printf("strdup: %s is %s\n", fc, sfc);
	printf("strdup: %s is %s\n", fc, cfc);

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

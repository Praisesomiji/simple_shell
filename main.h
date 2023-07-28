#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

pid_t creatcproc(void);
int excom(char **av);
char **get_av(char *str, char *delim);
int print_av(char *av[]);
int free_av(char *av[]);
size_t avlen(char **av);
char **splitstr(char *s, char *delim);
char *dupstr(char *str);
char *_strndup(char *str, size_t n);
char *_strdup(char *str);
size_t _strlen(char *str);

#endif /* MAIN_H_ */

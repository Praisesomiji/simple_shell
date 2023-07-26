#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t creatcproc(void);
int excom(char **av);
char **get_av(char *str, char *delim);
int print_av(char *av[]);
int free_av(char *av[]);

#endif /* MAIN_H_ */

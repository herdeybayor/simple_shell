#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int _putchar(char c);
void prompt(char *c);
int str_len(char *s);
void shell_error(char *program_path);
int str_cmp(char *s1, char *s2);
#endif

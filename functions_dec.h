#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int shellprintenv(void);
char *shellstrdup(char *string);
int shellreadcmd(char *s, size_t __attribute__((unused))file_stream);
char *shellcreatepath(char *cmd);
char *shellstrcat(char *dest, char *src);
int shellstrcmp(char *str1, char *str2);
char *shellstrcpy(char *dest, char *src);
int shellstrlen(char *s);
void cant_see_print(char *cmd);
int shellvoke_call(char *cmd_arr[]);
char *shellgetenv(char *var);
int shellstr_n_cmp(char *a1, char *a2, int n);
int shellsetenv(char *variable, char *value, int overwrite);
int shellunsetenv(char *variable);
#endif


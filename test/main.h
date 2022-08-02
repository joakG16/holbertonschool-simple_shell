#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;
int main(void);
int vexec(char **args);
char **token(char *buffer);
void catchsig(int sig);
int shprompt();

#endif
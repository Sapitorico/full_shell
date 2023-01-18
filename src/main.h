#ifndef MANI_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#define DELIM " \t\n"
char *path_maker();
int not_found();
int str_cat();

extern char **tokenize_input;
extern char *input;

#endif
#ifndef MANI_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define DELIM " \t\n"
int pathmaker();
int not_found();

extern char **tokenize_input;
extern char *input;

#endif
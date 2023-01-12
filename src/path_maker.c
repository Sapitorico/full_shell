#include "main.h"

int pathmaker()
{
	return 1;
}

int not_found()
{
	write(1, tokenize_input[0], strlen(tokenize_input[0]));
	write(1, ": command not found\n", 20);
	return 1;
}
#include "main.h"
int argument_counter(char *input);
void tokenize(int counter);
void free_tokens();
int print_prompt(int isat);

char *input = NULL;
char **tokenize_input = NULL;

int main(void)
{
	size_t size_input = 0;
	int counter = 0;
	int isat = isatty(STDIN_FILENO);
	
	while (print_prompt(isat) && getline(&input, &size_input, stdin) >= 0)
	{
		if ((counter = argument_counter(strdup(input))) == 0) continue;
		tokenize(counter);
		pathmaker() && not_found();
		free_tokens();
	}
	if (input) free(input);
	return (0);
}
int argument_counter(char *copy_input)
{
	int counter = 0;
	char *tok = strtok(copy_input, DELIM);
	while (tok)
	{
		counter++;
		tok = strtok(NULL, DELIM);
	}
	free(copy_input);
	return counter;
}

void tokenize(int counter)
{
	char *token = strtok(input, DELIM);
	tokenize_input = malloc(sizeof(char*) * (counter + 1));
	if (!tokenize_input) exit(98);
	int i = 0;
	while(token)
	{
		tokenize_input[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	tokenize_input[i] = NULL;
}
void free_tokens()
{
	if (!tokenize_input) return;
	free(tokenize_input);
}


int print_prompt(int isat)
{
	isat && write(1, "$ ", 2);
	return 1;
}
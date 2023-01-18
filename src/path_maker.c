#include "main.h"
char *token = NULL;
char *path = NULL;
char *concat = NULL;

char *path_maker()
{
    int i = 0;

    path = getenv("PATH");
    token = strtok(path, ":");
    while (token)
    {
        if (str_cat(tokenize_input[0]) == 1)
            return (concat);\
		free(concat);
        token = strtok(NULL, ":");
        i++;
	}
	return NULL;
}

int str_cat()
{
	int size_token = strlen(token);
    int len = (size_token + strlen(tokenize_input[0]) + 2);
    struct stat stats;

    concat = malloc(sizeof(char) * len);
    strcpy(concat, token);
    concat[size_token] = '/';
	size_token += 1;
	path = tokenize_input[0];
    for (size_token; size_token < len; size_token++ && path++)
        concat[size_token] = *path;
    if (!stat(concat, &stats))
    {
        return 1;
    }
}

int not_found()
{
	write(1, tokenize_input[0], strlen(tokenize_input[0]));
	write(1, ": command not found\n", 20);
	return 127;
}
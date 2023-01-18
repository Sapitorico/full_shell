#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
int str_cat();
char *token = NULL;
char *concat = NULL;

void make_path()
{
    char *path = getenv("PATH");
    int i = 0;

    token = strtok(path, ":");
    while (token)
    {
        if (str_cat() == 1)
            return;
        token = strtok(NULL, ":");
        i++;
    }
}
int str_cat()
{
    char *command = "ls";
    int len = (strlen(token) + strlen(command) + 2);
    struct stat stats;

    concat = malloc(sizeof(char) * len);
    strcpy(concat, token);
    concat[strlen(token)] = '/';
    for (int i = strlen(token) + 1, j = 0; i < len; i++ && j++)
        concat[i] = command[j];
    if (!stat(concat, &stats))
    {
        return 1;
    }
}
int main()
{

    make_path();
    printf("%s\n", concat);
    return 0;
}
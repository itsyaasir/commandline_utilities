// PWD module
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "pwd.h"

// Get current working directory no arguments
int get_pwd()
{
    char *cwd = getcwd(NULL, 0);
    if (cwd == NULL)
    {
        return -1;
    }
    write(STDOUT_FILENO, cwd, strlen(cwd));
    write(STDOUT_FILENO, "\n", 1);
    free(cwd);
    return 0;
}

// Test function for pwd module
int main()
{
    get_pwd();
    return 0;
}
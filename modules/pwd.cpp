// PWD module
#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include <stdlib.h>
#include "pwd.h"

// Get current working directory
int get_cwd(char *path)
{
    if (path == NULL)
    {
        return -1;
    }

    return syscall(__NR_getcwd, path, PATH_MAX);
}
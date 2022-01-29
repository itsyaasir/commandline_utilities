// GREP module
#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include <stdlib.h>
#include "grep.h"

// Filter contents of a file based on a pattern string
int grep_file(char *path, char *pattern)
{
#define BUFFER_SIZE 1024;
    if (path == NULL || pattern == NULL)
    {
        return -1;
    }

    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = 0;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (strstr(buffer, pattern) != NULL)
        {
            write(STDOUT_FILENO, buffer, bytes_read);
        }
    }

    close(fd);
    return 0;
}
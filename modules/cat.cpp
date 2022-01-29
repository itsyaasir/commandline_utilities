// Cat module

#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include <stdlib.h>
#include "cat.h"
// Read contents of a file
int read_file(char *path)
{
    #define BUFFER_SIZE 1024;
    if (path == NULL)
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
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
    return 0;
}
// Head Module
#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include <stdlib.h>
#include "head.h"

// Read only 10 top contents of a file
int head_file(char *path)
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
    int count = 0;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (count < 10)
        {
            write(STDOUT_FILENO, buffer, bytes_read);
            count++;
        }
    }

    close(fd);
    return 0;
}
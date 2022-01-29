// Tail Module
#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include <stdlib.h>
#include "tail.h"

// Read the bottom 10 contents of a file
int tail_file(char *path)
{
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
    int offset = 0;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        offset += bytes_read;
        if (offset > BUFFER_SIZE)
        {
            offset -= BUFFER_SIZE;
            lseek(fd, offset, SEEK_SET);
        }
    }

    close(fd);
    return 0;
}
// Write into a file
#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "modules/write.h"

// Write into a file from the argument
int write_file(char *filename, char *text)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }
    int n = write(fd, text, strlen(text));
    if (n == -1)
    {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }
    close(fd);
    return 0;
}
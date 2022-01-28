// Source code for the module ls.cpp
#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include <stdlib.h>

#include "ls.h"

// Function: ls
int list_dir(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        return -1;
    }
    char buf[1024];
    int n;
    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        write(1, buf, n);
    }
    close(fd);
    return 0;
}
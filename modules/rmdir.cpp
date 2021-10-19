//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <syscall.h>
#include "rmdir.h"
// SYSCALL REMOVE DIRECTORY
int remove_directory(char *path)
{
    if (path == NULL)
    {
        return -1;
    }
    return syscall(__NR_rmdir, path); // syscall(__NR_rmdir, path); is for removing directory
}
// MKDIR MODULES
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
#include "mkdir.h"
// SYSCALL CREATE DIRECTORY
int create_directory(char *path)
{
    if (path == NULL)
    {
        return -1;
    }
    return syscall(__NR_mkdir, path, 0777); // 0777 is the permission
    // __NR_mkdir is the number of the syscall
}
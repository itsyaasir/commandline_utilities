// Source file for the rm module
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
#include "rm.h"

int delete_file(char *pathname)
{

    if (pathname == NULL)
    {
        return -1;
    }
    else
    {
        return syscall(SYS_unlink, pathname); 
        // unlink is a system call for deleting a file
    }
}
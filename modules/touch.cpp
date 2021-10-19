// TOUCH MODULE
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
#include <nspr/prlink.h>
#include "touch.h"

//* CREATE FILE SYSCALL
int create_file(char *pathname)
{
    if (pathname == NULL)

    {
        return -1;
        // -1 means error and is returned  when pathname is null
    }
    else
    {
        return syscall(SYS_open, pathname, O_CREAT | O_WRONLY | O_TRUNC, 0666);
        // SYS_open is the system call number for open
        // O_CREAT is used to create a file if it does not exist
        // O_WRONLY is used to write to the file
        // O_TRUNC is used to truncate the file if it already exists
        // 0666 is the permissions of the file -rw-rw-rw- 	0666 	read & write
    }
}
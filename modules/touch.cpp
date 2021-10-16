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
    }
    else
    {
        return syscall(SYS_open, pathname, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    }
}
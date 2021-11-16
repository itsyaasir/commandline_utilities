// Source file for the rm module
#include <unistd.h>
#include <fcntl.h>
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
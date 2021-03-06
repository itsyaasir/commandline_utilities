// TOUCH MODULE
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <stdlib.h>
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
        // 0666 is the permisOrsions of the file -rw-rw-rw- 	0666 	read & write
    }
}
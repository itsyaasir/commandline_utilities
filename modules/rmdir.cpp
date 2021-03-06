//Source code for rmdir module
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <stdlib.h>

#include "rmdir.h"
// SYSCALL REMOVE DIRECTORY
int remove_directory(char *path)
{
    if (path == NULL)
    {
        return -1;
    }
    return syscall(SYS_rmdir, path); // syscall(__NR_rmdir, path); is for removing directory
}
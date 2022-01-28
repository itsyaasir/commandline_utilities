// Rename Module
#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include <stdlib.h>

#include "mv.h"

// Rename file
int rename_file(char *old_pathname, char *new_pathname)
{
    if (old_pathname == NULL || new_pathname == NULL)
    {
        return -1;
    }

    return syscall(SYS_rename, old_pathname, new_pathname);
}
// Move Directory
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <stdlib.h>

#include "mvdir.h"
// Move direc

int move_dir(char *old_pathname, char *new_pathname)
{
    if (old_pathname == NULL || new_pathname == NULL)
    {
        return -1;
    }
    return syscall(SYS_renameat, AT_FDCWD, old_pathname, AT_FDCWD, new_pathname);
}
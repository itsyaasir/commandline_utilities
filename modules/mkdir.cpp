// MKDIR MODULES
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <stdlib.h>

#include "mkdir.h"
// SYSCALL CREATE DIRECTORY
int create_directory(char *path)
{
    if (path == NULL)
    {
        return -1;
    }

    return syscall(SYS_mkdir, path, 0777);

    // 0777 is the permission -rwxrwxrwx 	0777 	read, write, & execute for owner, group and others
    // SYS_mkdir is the number of the syscall which is used to create a directory
}

// Test for this module
int main()
{
    create_directory("test");
    // check if the directory was created by running ls -l
    if (access("test", F_OK) == 0)
    {
        write(STDOUT_FILENO, "Directory created\n", 1);
    }
    else
    {
        write(STDOUT_FILENO, "Directory not created\n", 1);
    }
    return 0;
}
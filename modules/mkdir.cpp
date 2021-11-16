// MKDIR MODULES
#include <unistd.h>
#include <fcntl.h>
#include <syscall.h>
#include "mkdir.h"
// SYSCALL CREATE DIRECTORY
int create_directory(char *path)
{
    if (path == NULL)
    {
        return -1;
    }
    return syscall(__NR_mkdir, path, 0777);
    
    // 0777 is the permission -rwxrwxrwx 	0777 	read, write, & execute for owner, group and others
    // __NR_mkdir is the number of the syscall which is used to create a directory
}
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
#include "modules/mkdir.h"
#include "modules/rmdir.h"
#include "modules/touch.h"
#include "modules/rm.h"

int main(int argc, char *argv[])
{

    // CREATE DIRECTORY
    if (argc == 3 && strcmp(argv[1], "mkdir") == 0)
    {
        if (create_directory(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return -1;
        }
        printf("Directory created\n");
        return 0;
    }
    // Remove Directory
    else if (argc == 3 && strcmp(argv[1], "rmdir") == 0)
    {
        if (remove_directory(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return -1;
        }
        printf("Directory removed\n");
        return 0;
    }
    // CREATE FILE
    else if (argc == 3 && strcmp(argv[1], "touch") == 0)
    {
        if (create_file(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return -1;
        }
        printf("File created\n");
        return 0;
    }
    // Delete file
    else if (argc == 3 && strcmp(argv[1], "rm") == 0)
    {
        if (delete_file(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return -1;
        }
        printf("File removed\n");
        return 0;
    }
    else
    {
        printf("Error: Invalid arguments\n");
        return -1;
    }
}
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

int main(int argc, char *argv[]) // argv[0] = name of program
{
    if (argc < 2)
    {
        printf("Usage: %s <command> [<args>]\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "mkdir") == 0)
    {
        if (argc < 3)
        {
            printf("Usage: %s mkdir <dirname>\n", argv[0]);
            return 1;
        }
        else if (create_directory(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return 1;
        }
        create_directory(argv[2]);
        printf("Directory created\n");
    }
    else if (strcmp(argv[1], "rmdir") == 0)
    {
        if (argc < 3)
        {
            printf("Usage: %s rmdir <dirname>\n", argv[0]);
            return 1;
        }
        else if (remove_directory(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return 1;
        }
        remove_directory(argv[2]);
        printf("Directory removed\n");
    }
    else if (strcmp(argv[1], "touch") == 0)
    {
        if (argc < 3)
        {
            printf("Usage: %s touch <filename>\n", argv[0]);
            return 1;
        }
        else if (create_file(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return 1;
        }
        create_file(argv[2]);
        printf("File created\n");
    }
    else if (strcmp(argv[1], "rm") == 0)
    {
        if (argc < 3)
        {
            printf("Usage: %s rm <filename>\n", argv[0]); // Print usage of the program
            return 1;
        }
        else if (delete_file(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno)); // error message
        }
        delete_file(argv[2]);
        printf("File removed\n");
    }
    else if (strcmp(argv[1], "help") == 0) // HELP
    {
        printf("Usage: %s <command> [<args>]\n", argv[0]);
        printf("Commands:\n");
        printf("\tmkdir <dirname>\n");
        printf("\trmdir <dirname>\n");
        printf("\ttouch <filename>\n");
        printf("\trm <filename>\n");
        printf("\thelp\n");
    }
    else
    {
        printf("Unknown command: %s\n", argv[1]); // Unknown command
        return 1;
    }
    return 0;
}

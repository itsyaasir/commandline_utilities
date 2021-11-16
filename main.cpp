#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "modules/mkdir.h"
#include "modules/rmdir.h"
#include "modules/touch.h"
#include "modules/rm.h"
#include "modules/ls.h"
#include "modules/mv.h"
#include "modules/mvdir.h"

int main(int argc, char *argv[]) // argv[0] = name of program
{
    if (argc < 2)
    {
        printf("Usage: %s <command> [<args>]\n", argv[0]);
        return 1;
    }
    // Create directory
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
    // Remove directory
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
    // Create a file
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
    // Delete a file
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
    // List dirs
    else if (strcmp(argv[1], "ls") == 0)
    {
        if (argc < 3)
        {
            printf("Usage: %s ls <dirname>\n", argv[0]);
            return 1;
        }
        else if (list_dir(argv[2]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return 1;
        }
        list_dir(argv[2]);
    }
    // Rename file
    else if (strcmp(argv[1], "mv") == 0)
    {
        if (argc < 4)
        {
            printf("Usage: %s mv <oldname> <newname>\n", argv[0]);
            return 1;
        }
        else if (rename_file(argv[2], argv[3]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return 1;
        }
        rename_file(argv[2], argv[3]);

        printf("File renamed\n");
    }
    // Move directory
    else if (strcmp(argv[1], "mvdir") == 0)
    {
        if (argc < 4)
        {
            printf("Usage: %s mvdir <oldname> <newname>\n", argv[0]);
            return 1;
        }
        else if (move_dir(argv[2], argv[3]) == -1)
        {
            printf("Error: %s\n", strerror(errno));
            return 1;
        }
        move_dir(argv[2], argv[3]);

        printf("Directory renamed\n");
    }

    // Help Command
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

// GREP module
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "grep.h"

// /Check if pattern is in the file and print the line number and the line and occurences , if not found print "Not found"
int grep_file(char *filename, char *pattern)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }
    char buffer[1024];
    int line_number = 1;
    int occurences = 0;
    while (read(fd, buffer, 1024) > 0)
    {
        if (strstr(buffer, pattern) != NULL)
        {
            printf("%d: %s\n", line_number, buffer);
            occurences++;
        }
        line_number++;
    }
    if (occurences == 0)
    {
        printf("Not found\n");
    }
    close(fd);
    return 0;
}

// Test function for grep module
int test_grep_file()
{
    // First create a file and write some text to it
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        return -1;
    }
    write(fd, "This is a test file\n", 1); // This is a test file
    char *pattern = "is";
    char *path = "test.txt";
    grep_file(pattern, path);
    return 0;
}

// How to run the test
// $ gcc -o grep grep.c

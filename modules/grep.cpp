// GREP module
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "grep.h"

// Check if the pattern is in the file and return print number of matches and the line number , if not return 0
int grep(char *pattern, char *path)
{
    if (pattern == NULL || path == NULL)
    {
        return -1;
    }

    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        return -1;
    }

    char buffer[1024];
    int bytes_read = 0;
    int line_number = 1;
    while ((bytes_read = read(fd, buffer, 1024)) > 0)
    {
        if (strstr(buffer, pattern) != NULL)
        {
            printf("%d: %s", line_number, buffer);
        }
        line_number++;
    }

    close(fd);
    return 0;
}

// Test function for grep module
int main()
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
    grep(pattern, path);
    return 0;
}

// How to run the test
// $ gcc -o grep grep.c

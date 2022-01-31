// Cat module

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "cat.h"
// Read contents of a file
int read_file(char *path)
{
    int BUFFER_SIZE = 1024;
    if (path == NULL)
    {
        return -1;
    }

    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = 0;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
    return 0;
}

// test function for cat module
int test_cat()
{
    // First create a file and write some text to it
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        return -1;
    }
    write(fd, "This is a test file\n", 1); // This is a test file
    char *path = "test.txt";
    read_file(path);
    return 0;
}
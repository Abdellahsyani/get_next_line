#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // for open()
#include <unistd.h> // for close()


int main() {
    int fd;
    char *line;

    // Open the file to test
    fd = open("text.txt", O_RDONLY); // Make sure you have a file called test_file.txt
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Read and print lines until the end of the file
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s\n", line);
        //free(line); // Free memory allocated for each line
    }

    close(fd); // Close the file
    return 0;
}


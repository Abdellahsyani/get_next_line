#include "get_next_line.h"

int main()
{
    char *line;
    int fd1 = open("file1", O_RDONLY);
    int fd2 = open("file2", O_RDONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("Error opening files");
        return -1;
    }

    while ((line = get_next_line(fd1)) != NULL) {
        printf("From file1: %s", line);
        free(line);
    }

    while ((line = get_next_line(fd2)) != NULL) {
        printf("From file2: %s", line);
        free(line);
    }

    close(fd1);
    close(fd2);
    return 0;
}



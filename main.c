#include "get_next_line.h"

int main()
{
    char *line;
    int fd1 = 6; 

    while ((line = get_next_line(fd1)) != NULL) {
        printf("From file1: %s", line);
        free(line);
    }
    close(fd1);
    return 0;
}



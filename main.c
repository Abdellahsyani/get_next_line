#include "get_next_line_bonus.h"

int main()
{
    char *line;
    int fd1 = open("file1", O_RDONLY); 
    printf("------\n");
    printf("-----\n");
    while ((line = get_next_line(fd1)) != NULL) {
        printf("From file1: %s", line);
        free(line);
    }
    close(fd1);
    return 0;
}



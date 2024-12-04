#include "get_next_line_bonus.h"

int main()
{
    char *line1, *line2;
    int fd = open("file1", O_RDONLY); 
    int fd1 = open("file2", O_RDONLY);

    if (fd == -1 || fd1 == -1) {
        perror("Error opening files");
        return 1;
    }

    printf("-----\n");
    while (1) {
        line1 = get_next_line(fd);
        if (line1 == NULL) break;
        
        printf("From file1: %s", line1);
        free(line1);

        line2 = get_next_line(fd1);
        if (line2 == NULL) break;
        
        printf("From file2: %s", line2);
        free(line2);
    }

    while ((line1 = get_next_line(fd)) != NULL) {
        printf("From file1: %s", line1);
        free(line1);
    }

    while ((line2 = get_next_line(fd1)) != NULL) {
        printf("From file2: %s", line2);
        free(line2);
    }

    close(fd);
    close(fd1);
    return 0;
}

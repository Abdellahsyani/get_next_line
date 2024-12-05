#include "get_next_line_bonus.h"

int main()
{
    char *line1, *line2;
    int fd = open("file1", O_RDONLY); 
    int fd1 = open("file2", O_RDONLY);

    if (fd == -1 || fd1 == -1) {
        return 1;
    }

    printf("-----\n");
    while (1) {
        line1 = get_next_line(0);
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
    close(0);
    return 0;
}

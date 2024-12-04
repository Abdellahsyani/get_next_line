#include "get_next_line_bonus.h"

int main()
{
	char *line;
	int fd = open("file1", O_RDONLY); 
	int fd1 = open("file2", O_RDONLY);
	printf("-----\n");
	while ((line = get_next_line(fd)) != NULL) {
		printf("From file1: %s", line);
		line = get_next_line(fd1);
		printf("From file2: %s", line);
		free(line);
	}
	close(fd);
	close(fd1);
	return 0;
}



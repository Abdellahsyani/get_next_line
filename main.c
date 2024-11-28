#include "get_next_line.h"

int main() {
	int fd;
	char *line;
	char *line1;



	fd = open("text.txt", O_RDONLY); 
	int fj = open("test.txt", O_RDONLY);
	if (fd == -1) {
		perror("Failed to open file");
		return 1;
	}
	
	 while ((line = ft_get_next_line(fd)) != NULL) {
        	printf("%s", line);
        	free(line);
	}

	close(fd);
	return 0;
}

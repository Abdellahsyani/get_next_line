#include "get_next_line_bonus.h"

int main()
{
	//char *line;
	int fd = open("file1", O_RDONLY); 
	printf("------\n");
	printf("-----\n");
	/*while ((line = get_next_line(fd)) != NULL) {
		printf("From file1: %s", line);
		free(line);
	}*/
	//close(fd1);
	if (BUFFER_SIZE > 100)
	{
		char *temp;
		do {
			temp = get_next_line(fd);
			printf("%s", temp);
			free(temp);
		} while (temp != NULL);
	}
	/* 3 */ //test_gnl(fd, NULL);
	//next_read_error = 0;
	close(fd);
	return 0;
}



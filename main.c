#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h> 
#define BUFFER 10

char *get(int fd)
{
	char buffer[BUFFER];
	ssize_t readbytes;
	char *dup;
	int i = 0;
	int cpacity = BUFFER;

	dup = malloc(sizeof(char) * (cpacity + 1));
	if (!dup)
		return (NULL);
	readbytes = read(fd, buffer, BUFFER);
	if (readbytes <= 0)
		return (NULL);
	int j = 0;
	while (j < readbytes)
	{
		if (i >= cpacity)
		{
			cpacity *= 2;
			char *temp = realloc(dup, cpacity + 1);
			if (!temp)
			{
				free(dup);
				return NULL; 
			}
			dup = temp;
		}
		dup[i] = buffer[j];
		i++;
		j++;
	}
	if (buffer[j - 1] == '\n')
		return (NULL);
	dup[i] = '\0';
	return (dup);
}

int main() {
	int fd;
	char *line;


	fd = open("text.txt", O_RDONLY); 
	if (fd == -1) {
		perror("Failed to open file");
		return 1;
	}
	line = get(fd);
	printf("%s", line);

	close(fd);
	return 0;
}

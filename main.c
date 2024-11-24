#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // for open()
#include <unistd.h> // for close()
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
	while (1)
	{
		readbytes = read(fd, buffer, BUFFER);
		if (readbytes <= 0)
			break;

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
                    			return NULL; // Realloc failed
                		}
                	dup = temp;
			}
			dup[i] = buffer[j];
			i++;
			j++;
		}
		if (buffer[j - 1] == '\n')
			break;
	}
	dup[i] = '\0';
	return (dup);
}

int main() {
    int fd;
    char *line;

    // Open the file to test
    fd = open("text.txt", O_RDONLY); // Make sure you have a 
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }
	line = get(fd);
	printf("%s", line);

    close(fd);
    return 0;
}


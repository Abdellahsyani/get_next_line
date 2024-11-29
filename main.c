#include "get_next_line.h"

int main()
{
	char *line;


	int fd = open("file1", O_RDONLY);
	if (fd == -1)
		return -1;

	line = ft_get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
	}
	return 0;
}

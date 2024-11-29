#include "get_next_line.h"


int main()
{
	char *line;

	int fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
		return -1;
	while ((line = ft_get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}

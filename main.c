#include "get_next_line_bonus.h"

int main()
{
	char *line;


	int fd = open("file1", O_RDONLY);
	if (fd == -1)
		return -1;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return 0;
}

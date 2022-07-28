#include "get_next_line.h"

int main (int argc, char **argv)
{
	ssize_t reader;
	int fd;
	char *buffer;

	(void)argc;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	fd = open(argv[1], O_RDONLY);
	reader = read(fd, buffer, BUFFER_SIZE);
	printf("%ld\n", reader);
	return 0;
}

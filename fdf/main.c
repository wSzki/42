#include "./includes/fdf.h"
#include "externals/ft_gnl/get_next_line.h"


















int main(int ac, char **av)
{
	int fd;
	char *buffer;

	fd = open("./test_maps/basictest.fdf", O_RDONLY);
	while (get_next_line(fd, &buffer))
	{
		printf("%s", buffer);
		free(buffer);

	}
}

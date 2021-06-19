#include "../includes/fdf.h"

void fdf_open(t_global *g, int ac, const char *path)
{
	int fd;
	char *buffer;

	if (ac != 2)
		p_exit("ERROR: One argument allowed : map path");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		p_exit("ERROR: Cannot open file");
	while (get_next_line(fd, &buffer) && *buffer == '\0')
		free(buffer);
	if (*buffer == 0)
	{
		free(buffer);
		p_exit("ERROR: Empty file");
	}
	g->tmp_map = fdf_dual_realloc(g->tmp_map, buffer);
	free(buffer);
	while (get_next_line(fd, &buffer))
	{
		if (*buffer == '\0')
			break;
		g->tmp_map = fdf_dual_realloc(g->tmp_map, buffer);
		free(buffer);
	}
	free(buffer);
	while (get_next_line(fd, &buffer))
	{
		if (*buffer != '\0')
		{
			free(buffer);
			p_exit("ERROR: Map must be a solid block");
		}
		free(buffer);
	}
	free(buffer);
}

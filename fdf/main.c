#include "./includes/fdf.h"
#include "externals/ft_printf/includes/ft_printf.h"
#include "externals/libft/libft.h"


void fdf_print_map(t_global *g)
{
	int i = 0;
	while (g->map[i])
		printf("%s\n", g->map[i++]);
}

// ===========================================================
t_global *fdf_init(void)
{
	t_global *g;
	g = malloc(sizeof(t_global *));
	if (!g)
		p_exit("ERROR: t_global *g malloc failed");
	g->map = malloc(sizeof(char *));
	if (!g->map)
	{
		free(g);
		p_exit("ERROR: g->map malloc failed");
	}
	g->map[0] = NULL;
	return (g);
}

void	fdf_free_all(t_global *g)
{
	int i;

	i = 0;
	while (g->map[i])
		free(g->map[i++]);
	free(g->map);
	free(g);
}

// ===========================================================

char	**fdf_dual_realloc(char **double_ptr, char *line)
{
	int		i;
	int		j;
	char	**res;
	int		line_count;

	i = 0;
	j = 0;
	line_count = count_lines((void**)double_ptr);
	res = malloc(sizeof(char *) * (line_count + 2));
	if (!res)
		return (NULL);
	while (i < line_count)
	{
		res[j] = ft_strdup(double_ptr[i]);
		free(double_ptr[i]);
		double_ptr[i] = NULL;
		i++;
		j++;
	}
	res[line_count] = ft_strdup(line);
	res[line_count + 1] = NULL;
	free(double_ptr);
	double_ptr = NULL;
	return (res);
}
// ===========================================================

void fdf_open(t_global *g, int ac, const char *path)
{
	int fd;
	char *buffer;

	if (ac != 2)
		p_exit("ERROR: One argument allowed : map path");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		p_exit("ERROR: Cannot open file");
	while (get_next_line(fd, &buffer))
	{
		if (*buffer != '\0')
			break;
		g->map = fdf_dual_realloc(g->map, buffer);
		free(buffer);
	}
	free(buffer);
	while (get_next_line(fd, &buffer))
	{

		if (*buffer != '\0')
			break;
		g->map = fdf_dual_realloc(g->map, buffer);
		free(buffer);
	}
	free(buffer);
}

// ===========================================================

void	fdf_check_digits_only(t_global *g)
{
	int x;
	int y;

	x = 0;
	while (g->map[x])
	{
		y = 0;
		while (g->map[x][y])
		{
			if (ft_isdigit(g->map[x][y]) == 0 && g->map[x][y] != ' ')
			{
				fdf_free_all(g);
				p_exit("ERROR: Map takes digits only");
			}
			y++;
		}
		x++;
	}
}

void	fdf_check_solid_block(t_global *g)
{
	int i;

	i = 0;
	while (g->map[i] && g->map[i][0] == '\0')
		i++;
	while (g->map[i] && g->map[i][0] != '\0')
		i++;
	while (g->map[i])
	{
		if (g->map[i][0] != '\0')
		{
			fdf_free_all(g);
			p_exit("ERROR: Map must be a block");
		}
		i++;
	}
}

void	fdf_check_line_length(t_global *g)
{
	int i;
	size_t count;

	i = 1;
	fdf_print_map(g);
	count = ft_count_words(g->map[0], ' ');
	while (g->map[i])
	{
		if (count != ft_count_words(g->map[i], ' '))
		{
			fdf_free_all(g);
			p_exit("ERROR: All lines must contain equal number of values");
		}
		i++;
	}
}

void	fdf_map_checks(t_global *g)
{
	fdf_check_digits_only(g);
	fdf_check_solid_block(g);
	fdf_check_line_length(g);
}


// ===========================================================

int main(int ac, char **av)
{
	t_global *g;

	g = fdf_init();
	fdf_open(g, ac, av[1]);
	fdf_map_checks(g);





	fdf_print_map(g);
	fdf_free_all(g);
}

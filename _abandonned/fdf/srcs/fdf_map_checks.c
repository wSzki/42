#include "../includes/fdf.h"

static void	f_p_exit(t_global *g, char *str)
{
	fdf_free_all(g);
	p_exit(str);
}

void	fdf_check_digits_only(t_global *g)
{
	int	x;
	int	y;

	x = -1;
	while (g->tmp_map[++x])
	{
		y = -1;
		while (g->tmp_map[x][++y])
			if (ft_isdigit(g->tmp_map[x][y]) == 0 && g->tmp_map[x][y] != ' ')
				f_p_exit(g, "ERROR: Map takes digits only");
	}
}

void	fdf_check_line_length(t_global *g)
{
	int		i;
	size_t	count;

	i = 0;
	count = ft_count_words(g->tmp_map[0], ' ');
	if (ft_count_words(g->tmp_map[i], ' ') == 0)
		f_p_exit(g, "ERROR: Line contains spaces but no value");
	while (g->tmp_map[++i])
	{
		if (ft_count_words(g->tmp_map[i], ' ') == 0)
			f_p_exit(g, "ERROR: Line contains spaces but no value");
		if (count != ft_count_words(g->tmp_map[i], ' '))
			f_p_exit(g, "ERROR: All lines must contain equal number of values");
	}
	g->x = count;
	g->y = i;
	if (g->x < 2 || g->y < 2)
		f_p_exit(g, "ERROR: Grid must be have at least 2x2 cells");
}

void	fdf_map_checks(t_global *g)
{
	fdf_check_digits_only(g);
	fdf_check_line_length(g);
}

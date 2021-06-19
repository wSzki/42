#include "./includes/fdf.h"
#include "externals/libft/libft.h"


// ===========================================================
void fdf_print_map(t_global *g)
{
	int i = 0;
	while (g->tmp_map[i])
		printf("%s\n", g->tmp_map[i++]);

	i = 0;
	int j;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			printf("%d\n", g->map[i][j]);
			j++;
		}
		i++;
	}

	printf("%s\n", "|---------------------|");
	printf("  X - HORIZONTAL : %d\n", g->x);
	printf("  Y - VERTICAL   : %d\n", g->y);
	printf("%s\n", "|---------------------|");

}
// ===========================================================
t_global *fdf_init(void)
{
	t_global *g;
	g = malloc(sizeof(*g));
	if (!g)
		p_exit("ERROR: t_global *g malloc failed");
	g->tmp_map = malloc(sizeof(char *));
	if (!g->tmp_map)
	{
		free(g);
		p_exit("ERROR: g->tmp_map malloc failed");
	}
	g->tmp_map[0] = NULL;
	g->map = NULL;
	return (g);
}

void	fdf_free_all(t_global *g)
{
	int i;

	i = 0;
	if (g->map)
	{
		while (i < g->y)
			free(g->map[i++]);
	}
	free(g->map);
	i = 0;
	while (g->tmp_map[i])
		free(g->tmp_map[i++]);
	free(g->tmp_map);
	free(g);
}
// ===========================================================


void fdf_init_int_map(t_global *g)
{
	g->map = malloc(sizeof(int **) * (g->y + 1));
	if (!g->map)
	{
		fdf_free_all(g);
		p_exit("ERROR: g->map malloc failed");
	}
	g->map[g->y] = 0;
	int i = 0;
	while (i < g->y)
	{
		g->map[i] = NULL;
		g->map[i] = malloc(sizeof(int *) * (g->x + 1));
		if (!(g->map[i]))
		{
			fdf_free_all(g);
			p_exit("ERROR: g->map[i] malloc failed");
		}
		g->map[i][g->x] = 0;
		i++;
	}
}

void fdf_split_and_convert(t_global *g)
{
	int i;
	int j;
	char **split;

	i = 0;
	while (g->tmp_map[i])
	{
		j = 0;
		split = ft_split(g->tmp_map[i], ' ');
		while (split[j])
		{
			g->map[i][j] = ft_atoi(split[j]);
			j++;
		}
		j = 0;
		while (split[j])
		{
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
}

int main(int ac, char **av)
{
	t_global *g;

	g = fdf_init();
	fdf_open(g, ac, av[1]);
	fdf_map_checks(g);
	fdf_init_int_map(g);
	fdf_split_and_convert(g);




	fdf_print_map(g);
	fdf_free_all(g);
}

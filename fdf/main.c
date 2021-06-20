#include "./includes/fdf.h"
#include "externals/libft/libft.h"
#include <stdio.h>


// ===========================================================
void fdf_print_map(t_global *g)
{
	int i = 0;
	while (g->tmp_map[i])
		printf("%s\n", g->tmp_map[i++]);

	i = 0;
	int j;
	int tmp = 0;
	while (g->map[i])
	{
		j = 0;

		tmp = 0;
		while (tmp < g->x)
		{
			printf("%5d", g->map[i][j]);
			j++;
			tmp++;
		}
		printf("\n");
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



int main(int ac, char **av)
{
	t_global *g;

	g = fdf_init();
	fdf_open(g, ac, av[1]);
	fdf_map_checks(g);
	fdf_init_map(g);

	/////////////////
	fdf_print_map(g);
	fdf_free_all(g);
	/////////////////
}

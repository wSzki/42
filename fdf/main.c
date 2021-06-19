#include "./includes/fdf.h"
#include "externals/libft/libft.h"


// ===========================================================
void fdf_print_map(t_global *g)
{
	int i = 0;
	while (g->tmp_map[i])
		printf("%s\n", g->tmp_map[i++]);


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
	g->map = malloc (sizeof(int **));
	if (!g->map)
	{
		free(g);
		free(g->tmp_map);
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
	i = 0;
	while (g->tmp_map[i])
		free(g->tmp_map[i++]);
	free(g->tmp_map);
	free(g);
}
// ===========================================================


void fdf_convert_map(t_global *g)
{
	free(g->map);
	g->map = NULL;
	g->map = malloc(sizeof(int **) * (g->y));
	if (!g->map)
	{
		fdf_free_all(g);
		p_exit("ERROR: g->map malloc failed");
	}
	*(g->map) = NULL;
	int i = -1;
	while (++i < g->y)
	{
		free(g->map[i]);
		g->map[i] = malloc(sizeof(int *) * (g->x));
		if (!(g->map[i]))
		{
			fdf_free_all(g);
			p_exit("ERROR: g->map[i] malloc failed");
		}
	}
}

int main(int ac, char **av)
{
	t_global *g;

	g = fdf_init();
	fdf_open(g, ac, av[1]);
	fdf_map_checks(g);
	fdf_convert_map(g);





	fdf_print_map(g);
	fdf_free_all(g);
}

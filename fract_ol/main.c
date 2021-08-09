#include "./includes/fractol.h"

static void	fractol_set_additional_colors(t_global *g)
{
	g->color[16] = 0x473c29;
	g->color[17] = 0x32302f;
	g->color[18] = 0xd4be98;
	g->color[19] = 0xddc7a1;
	g->color[20] = 0xea6962;
	g->color[21] = 0xd8a657;
	g->color[22] = 0xA3BE8C;
	g->color[23] = 0xD08770;
	g->color[24] = 0x7C9C90;
	g->color[25] = 0xe78a4e;
	g->color[26] = 0xea6962;
	g->color[27] = 0xa9b665;
	g->color[28] = 0xd8a657;
	g->color[29] = 0x7c6f64;
	g->color[30] = 0x928374;
	g->color[31] = 0xa89984;
}

static void	fractol_set_color(t_global *g)
{
	g->color = malloc(sizeof(g->color) * 64);
	if (!g)
	{
		printf("Error\n%s", "*g malloc failed");
		free(g);
	}
	g->color[0] = 0x191d20;
	g->color[1] = 0x262727;
	g->color[2] = 0x191d20;
	g->color[3] = 0x3c3836;
	g->color[4] = 0x3c3836;
	g->color[5] = 0x504945;
	g->color[6] = 0x1f2428;
	g->color[7] = 0x32302f;
	g->color[8] = 0x504945;
	g->color[9] = 0x32361a;
	g->color[10] = 0xEBCB8B;
	g->color[11] = 0x333e34;
	g->color[12] = 0x3c1f1e;
	g->color[13] = 0x442e2d;
	g->color[14] = 0x0d3138;
	g->color[15] = 0x2e3b3b;
	fractol_set_additional_colors(g);
}

static void	fractol_catch_null(t_global *g, void *ptr)
{
	if (!ptr)
	{
		printf("Error\n\
				malloc failed at address %p", ptr);
		free_all_and_exit(g);
	}
}

static t_global	*fractol_init( char *str)
{
	t_global	*g;

	g = malloc(sizeof(t_global));
	if (!g)
	{
		printf("Error\n %s", "*g malloc failed");
		exit(1);
	}
	g->mlx = NULL;
	g->win = NULL;
	g->img = NULL;
	g->color = NULL;
	fractol_set_color(g);
	g->fractal_type = str[0];
	g->mlx = mlx_init();
	fractol_catch_null(g, g->mlx);
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Fract-ol");
	fractol_catch_null(g, g->win);
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	fractol_catch_null(g, g->img);
	return (g);
}

void	free_all_and_exit(t_global *g)
{
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->color);
	free(g);
	exit(0);
}

static void	fractol_data_init(t_global *g)
{
	if (g->fractal_type == 'm')
	{
		g->origin = -2.1;
		g->end = 1.2;
		g->x_max = 2.8;
		g->y_max = 2.4;
	}
	if (g->fractal_type == 'j')
	{
		g->origin = -1.5;
		g->end = 1.5;
		g->x_max = 3.0;
		g->y_max = 3.0;
	}

}
int	main (int ac, char **av)
{
	t_global	*g;

	fractol_input_check(ac, av);
	g = fractol_init(av[1]);
	fractol_data_init(g);
	fractol_run(g);
	fractol_set_hooks(g);
	mlx_loop(g->mlx);
	free_all_and_exit(g);
}

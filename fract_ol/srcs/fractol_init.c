#include "../includes/fractol.h"

void	fractol_set_color(t_global *g)
{

g->color[0] = 			0x191d20;
g->color[1] = 			0x262727;
g->color[2] = 			0x191d20;
g->color[3] = 			0x3c3836;
g->color[4] = 			0x3c3836;
g->color[5] = 			0x504945;
g->color[6] = 			0x1f2428;
g->color[7] = 			0x32302f;
g->color[8] = 			0x504945;
g->color[9] = 			0x32361a;
g->color[10] = 			0xEBCB8B;
g->color[11] = 			0x333e34;
g->color[12] = 			0x3c1f1e;
g->color[13] = 			0x442e2d;
g->color[14] = 			0x0d3138;
g->color[15] = 			0x2e3b3b;
g->color[16] = 			0x473c29;
g->color[17] = 			0x32302f;
g->color[18] = 			0xd4be98;
g->color[19] = 			0xddc7a1;
g->color[20] = 			0xea6962;
g->color[21] = 			0xd8a657;
g->color[22] = 			0xA3BE8C;
g->color[23] = 			0xD08770;
g->color[24] = 			0x7C9C90;
g->color[25] = 			0xe78a4e;
g->color[26] = 			0xea6962;
g->color[27] = 			0xa9b665;
g->color[28] = 			0xd8a657;
g->color[29] = 			0x7c6f64;
g->color[30] = 			0x928374;
g->color[31] = 			0xa89984;
g->color[32] = 			0x000000;
}


t_global *fractol_init(t_global *g, char *type)
{
	g = malloc(sizeof(t_global));
	if (!g)
	{
		fractol_putstr("Error\n*g malloc failed");
		exit(1);
	}

	g->color = malloc(sizeof(g->color) * 64);
	if (!g)
	{
		fractol_putstr("Error\n*g malloc failed");
		free(g);
	}
fractol_set_color(g);

	if ('j' == type[0])
		g->fractal_type = 'j';
	if ('m' == type[0])
		g->fractal_type = 'm';
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Fract-ol");
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	return (g);
}

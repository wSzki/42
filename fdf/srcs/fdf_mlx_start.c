
#include "../includes/fdf.h"

////////////////////////////////////////////
//****************************************//
void fdf_vector_print_data(t_global *g)
{

	printf("x0 %d\n", g->x0);
	printf("y0 %d\n", g->y0);
	printf("x1 %d\n", g->x1);
	printf("y1 %d\n", g->y1);
	printf("magnitude %f\n", g->magnitude);
	printf("radian %f\n",g->radian);
	printf("degrees %d\n", g->degrees);
	printf("color %d\n", g->color);

	printf("%d\n", g->x_res);
	printf("%d\n", g->y_res);
}

void fdf_test_circle(t_global *g, unsigned int color)
{
	int i;

	i = 0;
	fdf_vector_reset(g);
	g->x0 = g->x_res / 2;
	g->y0 = g->y_res / 2;
	fdf_vector_generate(g, g->x0, g->y0, 150);
	fdf_vector_color(g, color);
	while (i < 360)
	{
		fdf_vector_rotate(g, i++);
		fdf_vector_draw(g);
	}
}

void fdf_test_shell(t_global *g)
{
	fdf_vector_reset(g);
	int x = -1;
	g->y0 = g->y_res / 2;
	g->x0 = g->x_res / 2;
	while (++x < 360)
	{
		fdf_vector_generate(g, g->x0, g->y0, x / 2);
		fdf_vector_rotate(g, x);
		fdf_vector_draw(g);
	}
}

void fdf_fill_background(t_global *g, unsigned int color)
{
	int i = 0;
	(void)color;
	fdf_vector_reset(g);
	while (i < g->y_res)
	{
		fdf_vector_generate(g, 0, i, g->x_res);
		fdf_vector_color(g, color);
		fdf_vector_draw(g);
		i++;
	}
}

//****************************************//
////////////////////////////////////////////
void fdf_h_1(t_global *g, int cell_length)
{


	fdf_vector_generate(g, g->x0, g->y0, cell_length / 2);
	fdf_vector_rotate(g, 17);
	fdf_vector_color(g, 0x00fabd2f);
	fdf_vector_draw(g);
}
void	fdf_mlx_start(t_global *g)
{

	printf("%d\n", g->x);
	printf("%d\n", g->y);
	fdf_print_map(g);
	///////////////////////////////////////////
	g->x_res = 1000;
	g->y_res = 563;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->x_res, g->y_res, "window");
	g->img = mlx_new_image(g->mlx, g->x_res, g->y_res);
	/*data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);*/
	///////////////////////////////////////////
	/*fdf_fill_background(g, 0x00191d20);*/
	/*fdf_test_circle(g, 0x00fabd2f);*/
	/*fdf_test_shell(g);*/


	int cell_length;

	cell_length = (g->x_res - 100) / g->x / 3;

	printf("cell length %d\n", cell_length);

	int i;
	/*int xa;*/
	/*int ya;*/

	i = 0;

	fdf_vector_reset(g);
	g->x0 = 50;
	g->y0 = 50;
	while (i < g->x)
	{

		if (g->map[0][i] == 1)
		{
			fdf_vector_generate(g, g->x0, g->y0, cell_length / 2);
			fdf_vector_rotate(g, 17);
			fdf_vector_color(g, 0x00fabd2f);
			fdf_vector_generate(g, g->x1, g->y1, cell_length);
			fdf_vector_rotate(g, 270);
			fdf_vector_color(g, 0x00fabd2f);
			fdf_vector_draw(g);


			fdf_vector_generate(g, g->x0, g->y0, cell_length);
			fdf_vector_color(g, 0x00ffffff);
			fdf_vector_rotate(g, 17);
			g->x0 = g->x1;
			g->y0 = g->y1;
		}
		/*fdf_vector_generate(g, g->x0, g->y0, cell_length / 2);*/
		/*fdf_vector_rotate(g, 17);*/
		/*fdf_vector_color(g, 0x0fabd2f);*/
		/*fdf_vector_draw(g);*/
		/*[>xa = g->x1;<]*/
		/*[>ya = g->y1;<]*/
		/*[>fdf_vector_generate(g, xa, ya, cell_length);<]*/
		/*[>[>fdf_vector_rotate(g, 235);<]<]*/
		/*[>fdf_vector_draw(g);<]*/

		/*[>[>fdf_vector_generate(g, g->x0, g->y0, cell_length / 2);<]<]*/
		/*[>[>g->x0 = g->x1;<]<]*/
		/*[>[>g->y0 = g->y1;<]<]*/


		/*}*/

		// if 0 draw line
		if (g->map[0][i] == 0)
		{
			fdf_vector_generate(g, g->x0, g->y0, cell_length);
			fdf_vector_rotate(g, 17);
			fdf_vector_draw(g);
			fdf_vector_color(g, 0x00ffffff);
			g->x0 = g->x1;
			g->y0 = g->y1;
		}
		i++;
}










///////////////////////////////////////////
mlx_put_image_to_window(g->mlx, g->win, g->img, g->x_res, g->y_res);
mlx_loop(g->mlx);
///////////////////////////////////////////
// FREE -------------------------------
mlx_destroy_image(g->mlx, g->img);
mlx_destroy_window(g->mlx, g->win);
free(g->mlx);
fdf_print_map(g);
return ;
///////////////////////////////////////////
}

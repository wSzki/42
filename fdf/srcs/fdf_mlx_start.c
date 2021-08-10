
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
	fdf_vector_generate(g, 0, 0, 150);
	fdf_vector_color(g, color);
	while (i < 360)
	{
		fdf_vector_generate(g, 0, 0, 150);
		fdf_vector_color(g, color);
		fdf_vector_rotate(g, i);
		fdf_vector_draw(g);
		i+=10;
	}
}

void fdf_test_shell(t_global *g)
{
	fdf_vector_reset(g);
	int x = -1;
	while (++x < 360)
	{
		fdf_vector_generate(g, 0, 0, x / 2);
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

void fdf_test_center(t_global *g)
{
	int i = 0;
	int hek = 0x00fabd2f;
	while (i < 90)
	{
		fdf_vector_generate(g, -500, -500, 2000);
		fdf_vector_color(g, hek);

		hek += 0x00fa;
		fdf_vector_rotate(g, i);
		fdf_vector_draw(g);
		i += 3;
	}
	fdf_vector_generate(g, -499  -1, -499-1, 1000);
	fdf_vector_rotate(g, 90);
	fdf_vector_draw(g);
	fdf_vector_generate(g, 500, -499, 1000);
	fdf_vector_rotate(g, 90);
	fdf_vector_draw(g);
	fdf_vector_generate(g, 0, 0, 50);
	fdf_vector_rotate(g, 0);
	fdf_vector_draw(g);
	fdf_vector_generate(g, 0, 0, 50);
	fdf_vector_rotate(g, 90);
	fdf_vector_draw(g);
	fdf_vector_generate(g, 0, 0, 50);
	fdf_vector_rotate(g, 180);
	fdf_vector_draw(g);
	fdf_vector_generate(g, 0, 0, 50);
	fdf_vector_rotate(g, 270);
	fdf_vector_draw(g);

	fdf_vector_generate(g, -500, -400, 1000);
	fdf_vector_rotate(g, 0);
	fdf_vector_draw(g);

	fdf_vector_generate(g, -500, 400, 1000);
	fdf_vector_rotate(g, 0);
	fdf_vector_draw(g);

	fdf_vector_generate(g, -400, -500, 1000);
	fdf_vector_rotate(g, 90);
	fdf_vector_draw(g);
	fdf_vector_generate(g, 400, -500, 1000);
	fdf_vector_rotate(g, 90);
	fdf_vector_draw(g);
	fdf_vector_generate(g, -500, -500, 2000);
	fdf_vector_rotate(g, 45);
	fdf_vector_draw(g);

	/*fdf_vector_reset(g);*/
	/*g->x0 = 0;*/
	/*g->y0 = 0;*/
	/*g->x1 = 100;*/
	/*g->y1 = 256;*/
	/*fdf_vector_draw(g);*/


}

//****************************************//
////////////////////////////////////////////
//


void fdf_h_1(t_global *g, int cell_length)
{


	fdf_vector_generate(g, g->x0, g->y0, cell_length / 2);
	fdf_vector_rotate(g, 17);
	fdf_vector_color(g, 0x00fabd2f);
	fdf_vector_draw(g);
}


void	fdf_draw_x_axis(t_global *g, int x)
{
	int i;
	int cell_length;
	int tmp_x;
	int tmp_y;
	cell_length = (g->x_res - 100) / g->x / 3;

	printf("cell length %d\n", cell_length);

	i = 0;

	fdf_vector_reset(g);
	g->x0 = 0;
	g->y0 = 0;
	while (i < g->x)
	{
		if (g->map[x][i] == 1)
		{
			printf("%s\n", "----- PING -----");
			tmp_x = g->x0;
			tmp_y = g->y0;
			fdf_vector_generate(g, g->x0, g->y0, cell_length);
			fdf_vector_rotate(g, 17);
			fdf_vector_color(g, 0x00fabd2f);
			fdf_vector_generate(g, g->x1, g->y1, cell_length);
			fdf_vector_rotate(g, 270);
			fdf_vector_color(g, 0x00fabd2f);
			fdf_vector_draw(g);


			fdf_vector_generate(g, tmp_x, tmp_y, cell_length);
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
			printf("%s\n", "----- PONG -----");
			fdf_vector_generate(g, i, 0, 100);
			fdf_vector_rotate(g, 30);
			fdf_vector_draw(g);
			fdf_vector_color(g, 0x00ffffff);
			g->x0 = g->x1;
			g->y0 = g->y1;
		}
		i+=10;
}
}

/*void fdf_process_point(t_global *g)*/
/*{*/
	/*int x0;*/
	/*int y0;*/

	/*x0 = g->x0;*/
	/*y0 = g->y0;*/

	/*if (g->x[])*/



/*}*/

void	fdf_mlx_start(t_global *g)
{

	/*printf("%d\n", g->x);*/
	/*printf("%d\n", g->y);*/
	fdf_print_map(g);
	///////////////////////////////////////////
	g->x_res = 1000;
	g->y_res = 1000;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->x_res, g->y_res, "window");
	g->img = mlx_new_image(g->mlx, g->x_res, g->y_res);
	/*data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);*/
	///////////////////////////////////////////
	/*fdf_fill_background(g, 0x00191d20);*/
	fdf_test_circle(g, 0x00fabd2f);
	fdf_test_shell(g);
	fdf_test_center(g);
	///////////////////////////////////////////
	//
	//


	/*printf("X LENGTH %d\n", 800 / g->x);*/
	/*printf("Y LENGTH %d\n", 800 / g->y);*/
	/*int wire_length = 800 / g->x;*/
	/*int i = -1;*/
	/*int tmp_x0 = -400;*/
	/*int tmp_y0 = 0;*/

	/*while (++i < g->x)*/
	/*{*/
		/*if (g->map[0][i + 1] == 0)*/
		/*{*/
			/*fdf_vector_generate(g, tmp_x0, tmp_y0, wire_length);*/
			/*fdf_vector_rotate(g, 0);*/
			/*tmp_x0 = g->x1;*/
			/*tmp_y0 = g->y1;*/
			/*fdf_vector_draw(g);*/
		/*}*/
		/*else*/
		/*{*/
			/*[>fdf_process_point(g);<]*/
			/*fdf_vector_draw(g);*/
		/*}*/
	/*}*/

	mlx_put_image_to_window(g->mlx, g->win, g->img, g->x_res, g->y_res);
	mlx_loop(g->mlx);
	///////////////////////////////////////////
	// FREE -------------------------------
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_window(g->mlx, g->win);
	/*fdf_print_map(g);*/
	return ;
	///////////////////////////////////////////
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:52:03 by wszurkow          #+#    #+#             */
/*   Updated: 2021/04/08 13:54:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int key_hook(int keycode, t_global *g )
{
	(void)keycode;
	static int i;
	/*mlx_destroy_image(g->mlx, g->data->img);*/
	/*mlx_destroy_image(g->mlx, g->minimp->img);*/
	init_image(g, g->data);
	int x;
	int y;

	x = 0;
	y = 0;

	while (x < 100 - 1)
	{
		y = 0;
		while (y < 100 - 1)
		{
			my_mlx_pixel_put(g->data,  x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	my_mlx_pixel_put(g->data,  i + 100 , 200, 0xFFFF00FF);
	/*mlx_put_image_to_window(g->mlx, g->win, g->data->img, 0, 0);*/
	mlx_put_image_to_window(g->mlx, g->win, g->minimap->img, 0, 0);
	mlx_put_image_to_window(g->mlx, g->win, g->data->img, 0, 0);
	i++;

	printf("%d\n", i);
	return 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:53:07 by wszurkow          #+#    #+#             */
/*   Updated: 2021/04/08 13:54:37 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	/*char    *dst;*/

	// dst is the adress of the pixel to colorize
	// int offset = (y * line_length + x * (bits_per_pixel / 8));

	char *dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


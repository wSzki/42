/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_entrypoint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:55:57 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/12 15:16:00 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"



void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	/*char    *dst;*/


	// dst is the adress of the pixel to colorize
	// int offset = (y * line_length + x * (bits_per_pixel / 8));

	char *dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


// GNL ------------------------------ //

char *ft_realloc(char *line, int *i)
{
	int l = 0;
	char *str;

	if (!(str = malloc(*i * 2)))
		return (NULL);
	*i *= 2;
	while (line && line[l])
	{
		str[l] = line[l];
		l++;
	}
	while(l < *i)
	{
		str[l] = 0;
		l++;
	}
	free(line);
	return(str);
}

int get_next_line(char **line, int fd)
{
	int r = 1;
	int i = -1;
	int malloc_size = 50;

	if (!line)
		return(-1);
	*line = NULL;
	if (!(*line = ft_realloc(*line, &malloc_size)))
		return (-1);
	while ((r = read(fd, &(*line)[++i], 1)))
	{
		if ((*line)[i] == 10)
			break ;
		if (i == malloc_size - 2)
			if (!(*line = ft_realloc(*line, &malloc_size)))
				return (-1);
	}
	(*line)[i] = 0;
	if (i > 0)
		return (i);
	return (r);
}

// ------------------------------------- //

/*
   void	ft_put_square(t_data *img, int x, int y, int x_offset, int y_offset)
   {
   int i;
   int j;
   int border_size;

   border_size = 1;
   i = x_offset + border_size;
   j = y_offset + border_size;
   x = x + x_offset;
   y = y + y_offset;
   while (++i < x - border_size)
   {
   j = y_offset + border_size;
   while (++j < y - border_size)
   my_mlx_pixel_put(img, i ,j, 0x00191d20);
   }
   }
   */

void	ft_put_square(t_data *img, int square_size, int x_offset, int y_offset, char c)
{
	int x;
	int y;
	int i;
	int j;
	int border_size;

	x_offset *= square_size;
	y_offset *= square_size;
	x = square_size;
	y = square_size;
	border_size = 1;
	i = x_offset + border_size;
	j = y_offset + border_size;
	x = x + x_offset;
	y = y + y_offset;
	while (++i < x - border_size)
	{
		j = y_offset + border_size;
		while (++j < y - border_size)
		{
			if (c == '1')
				my_mlx_pixel_put(img, i ,j, 0x00191d20);
		}
	}
}



void cub3d_entrypoint()
{
	int fd;
	char **line;
	int max_chars;
	int number_chars;
	int number_lines;
	int TEMP;
	int r;
	t_window window;
	t_map map;

	line = malloc(sizeof (char *));
	fd = open("./map_only.cub", O_RDONLY);

	r = 0;
	max_chars = 0;
	number_chars = 0;
	number_lines = 0;
	TEMP = 0;

	while (((r = number_chars = get_next_line(line, fd)) > 0))
	{

		number_chars = ft_strlen(*line);
		if (max_chars < number_chars)
			max_chars = number_chars;
		number_lines++;
		printf("line -> %s\n", *line);
	}
	close(fd);
	free(line);
	line = malloc(sizeof (char *));
	fd = open("./map_only.cub", O_RDONLY);

	map.number_columns = max_chars;
	map.number_rows = number_lines;
	map.cell_count = max_chars * number_lines;

	printf("%d\n", max_chars);
	printf("%d\n", number_lines);
	printf("%d\n", map.cell_count);


	if (map.number_columns >= map.number_rows)
		TEMP = map.number_columns;
	else
		TEMP = map.number_rows;


	window.x = 300;
	window.y = 400;
	TEMP = window.x / TEMP;
	printf("border cell dimension %d\n", TEMP);


}

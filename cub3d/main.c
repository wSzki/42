/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:10 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/16 02:56:53 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "libft/libft.h"


void print_input_data(t_global *g)
{
	printf(" ------------ %d\n",g->window->x_resolution);
	printf(" ------------ %d\n",g->window->y_resolution);
	printf(" ------------ %s\n",g->map_textures->north_texture_path);
	printf(" ------------ %s\n",g->map_textures->south_texture_path);
	printf(" ------------ %s\n",g->map_textures->west_texture_path);
	printf(" ------------ %s\n",g->map_textures->east_texture_path);
	printf(" ------------ %s\n",g->map_textures->sprite_texture_path);
	printf(" ------------ %s\n",g->map_textures->floor_color);
	printf(" ------------ %s\n",g->map_textures->ceiling_color);
}

int detect_map_line(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	if (*line == '\0')
		return (0);
	while (line[i])
	{
		if (is_in_charset(line[i], " 012NSEW") == 0)
			return (0);
		i++;
	}
	return (1);
}

int	parse_intput(t_global *g)
{

	int fd;
	char *line;

	g = malloc(sizeof(t_global));
	g->window = malloc(sizeof(t_window));
	g->map_textures = malloc(sizeof(t_map_textures));
	init_struct(g);
	fd = open("./assets/map.cub", O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((get_next_line(&line, fd) > 0))
	{
		if (detect_map_line(line))
		{
			/*g->map-> = line;*/
			break;
		}
		parse_line_resolution(line, g);
		parse_line_paths(line, g);
		printf("--> %s\n", line);
	}

	printf("%s\n", " --------------- PRINT ----------------");
	printf("--> %s\n", line);
	while ((get_next_line(&line, fd) > 0))
	{
		printf("--> %s\n", line);
	}
	close(fd);
	print_input_data(g);
	return 0;
}

int main()
{
	// Location of current MLX instance
	void *mlx;
	t_window window;
	t_data img;
	void *win_ptr;


	t_global *g;

	g = malloc(sizeof(t_global));
	if (!g)
		return (-1);


	parse_intput(g);

	window.x_resolution = 300;
	window.y_resolution = 400;

	// INIT MLX INSTANCE
	mlx = mlx_init();

	// POINT TO WINDOW
	win_ptr = mlx_new_window(mlx, window.x_resolution , window.y_resolution, "name");

	// CREATE NEW IMAGE
	img.img = mlx_new_image(mlx, window.x_resolution , window.y_resolution);

	// POPULATE IMAGE
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// SEND IMAGE TO WINDOW
	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);

	// WINDOW STAY OPEN
	mlx_loop(mlx);

	return (0);
}

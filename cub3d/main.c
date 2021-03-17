/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:10 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/17 18:32:39 by wszurkow         ###   ########.fr       */
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
	printf("error------- %d\n",g->error);
	printf("valid parameters - %d\n",g->valid_parameter_count);
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


char **dual_realloc(char **map_data, char *line)
{
	(void)line;
	int i;
	int j;
	char **res;
	int line_count;

	i = 0;
	j = 0;
	line_count = number_of_args(map_data);
	res = malloc(sizeof(char *) * (line_count + 2));
	if (!res)
		return NULL;
	while (map_data[i])
	{
		res[j] = ft_strdup(map_data[i]);
		free(map_data[i]);
		i++;
		j++;
	}
	res[line_count] = ft_strdup(line);
	res[line_count + 1] = NULL;
	free(map_data);

	return (res);
}



int	parse_input(t_global *g)
{

	int fd;
	int arg_count;
	char *line;
	char **line_split;
	char **map_data;

	int i = 0;


	g = malloc(sizeof(t_global));
	g->window = malloc(sizeof(t_window));
	g->map_textures = malloc(sizeof(t_map_textures));
	map_data = malloc(sizeof(char *));
	*map_data = NULL;
	init_struct(g);
	fd = open("./assets/map.cub", O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((get_next_line(&line, fd) > 0))
	{
		arg_count = 0;
		if (detect_map_line(line))
		{
			map_data = dual_realloc(map_data, line);
			while ((get_next_line(&line, fd) > 0))
				map_data = dual_realloc(map_data, line);
			printf("%s\n", " --------------- PRINT MAP----------------");
			while (map_data[i])
			{
				printf("map -> %s\n", map_data[i]);
				i++;;
			}
			break;
		}
		line_split = ft_split(line, ' ');
		arg_count = number_of_args(line_split);
		if (arg_count == 1 || arg_count > 3)
		{
			g->error++;
			break;
		}
		if (arg_count == 3)
			parse_line_resolution(line_split, g);
		if (arg_count == 2)
			parse_line_paths(line_split, g);
		printf("--> %s\n", line);
		free(line_split);
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


	parse_input(g);

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

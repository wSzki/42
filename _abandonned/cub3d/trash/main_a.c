/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:10 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/13 20:22:10 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "libft/libft.h"

void	init_input_data(t_input_data *input_data)
{
	input_data->x_resolution = 0;
	input_data->y_resolution = 0;

	input_data->north_texture_path = "";
	input_data->south_texture_path = "";
	input_data->east_texture_path = "";
	input_data->west_texture_path = "";

	input_data->floor_color = "";
	input_data->ceiling_color = "";

}

void print_input_data(t_input_data *input_data)
{
	printf(" ------------ %d\n", input_data->x_resolution);
	printf(" ------------ %d\n", input_data->y_resolution);

	printf(" ------------ %s\n", input_data->north_texture_path);
	printf(" ------------ %s\n", input_data->south_texture_path);
	printf(" ------------ %s\n", input_data->west_texture_path);
	printf(" ------------ %s\n", input_data->east_texture_path);

	printf(" ------------ %s\n", input_data->sprite_texture_path);

	printf(" ------------ %s\n", input_data->floor_color);
	printf(" ------------ %s\n", input_data->ceiling_color);
}

int	ft_is_number(char *str)
{
	if (!str)
		return (0);
	while (str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int detect_map_start(char *line)
{
	int i;

	i = 0;

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

void	parse_line_resolution(char *line, t_input_data *input_data)
{
	char **line_split;


	line_split = ft_split(line, ' ');

	if (!line_split)
		return ;
	line_split = ft_split(line, ' ');
	if (ft_strcmp(line_split[0], "R") == 0)
	{
		if (input_data->x_resolution || input_data->y_resolution)
		{
			input_data->x_resolution = -1;
			input_data->y_resolution = -1;
			return ;
		}
		if (!(ft_is_number(line_split[1]) && ft_is_number(line_split[2]) && line_split[3] == NULL))
			return ;
		input_data->x_resolution = ft_atoi(line_split[1]);
		input_data->x_resolution = ft_atoi(line_split[2]);
	}
}


void	parse_line_paths(char *line, t_input_data *input_data)
{
	char **line_split;

	line_split = malloc(sizeof(char *));
	if (!line_split)
		return ;
	line_split = ft_split(line, ' ');

	if (!(line_split[1] && line_split[2] == NULL))
		return ;
	if (ft_strcmp(line_split[0], "NO") == 0)
		input_data->north_texture_path = ft_strdup(line_split[1]);
	if (ft_strcmp(line_split[0], "SO") == 0)
		input_data->south_texture_path = ft_strdup(line_split[1]);
	if (ft_strcmp(line_split[0], "WE") == 0)
		input_data->west_texture_path = ft_strdup(line_split[1]);
	if (ft_strcmp(line_split[0], "EA") == 0)
		input_data->east_texture_path = ft_strdup(line_split[1]);
	if (ft_strcmp(line_split[0], "S") == 0)
		input_data->sprite_texture_path = ft_strdup(line_split[1]);
	if (ft_strcmp(line_split[0], "F") == 0)
		input_data->floor_color = ft_strdup(line_split[1]);
	if (ft_strcmp(line_split[0], "C") == 0)
		input_data->ceiling_color = ft_strdup(line_split[1]);

	free(line_split);
}

/*void	parse_line(char *line, t_input_data *intput_data)*/
/*{*/



/*}*/

int	parse_intput(t_input_data *input_data)
{

	int fd;
	/*char *buffer;*/
	/*int r;*/
	/*char **split_data;*/
	/*char **s;*/

	// READ FILE AND STORE INTO BUFFER
	/*buffer = malloc(sizeof(char) * 2048 + 1);*/
	fd = open("./assets/map.cub", O_RDONLY);
	if (fd < 0)
		return (-1);
	/*r = read(fd, buffer, 2048 + 1);*/
	/*buffer[r] = 0;*/


	/*int res;*/
	char **line;

	line = malloc(sizeof(char*));
	while ((get_next_line(line, fd) > 0))
	{
		parse_line_resolution(*line, input_data);
		/*res = detect_map_start(*line);*/
		/*if (res == 1)*/
			/*break;*/
		/*printf("%d ", res);*/
		printf("--> %s\n", *line);
	}

	/*while ((get_next_line(line, fd) > 0))*/
	/*{*/
		/*res= detect_map_start(*line);*/
		/*printf("%d ", res);*/
		/*printf("--> %s\n", *line);*/
	/*}*/


	close(fd);




/*

	// SPLIT AT EVERY \n
	split_data = malloc(sizeof(char *));
	if (!split_data)
		return (-1);
	split_data = ft_split(buffer, '\n');



	init_input_data(input_data);
	s = malloc(sizeof(char *));
	s = ft_split(split_data[0], ' ');
	if (ft_strcmp(s[0], "R") == 0)
	{
		input_data->x_resolution = ft_atoi(s[1]);
		input_data->y_resolution = ft_atoi(s[2]);
	}
	s = ft_split(split_data[1], ' ');
	if (ft_strcmp(s[0], "NO") == 0)
		input_data->north_texture_path = ft_strdup(s[1]);
	s = ft_split(split_data[2], ' ');
	if (ft_strcmp(s[0], "SO") == 0)
		input_data->south_texture_path = ft_strdup(s[1]);
	s = ft_split(split_data[3], ' ');
	if (ft_strcmp(s[0], "WE") == 0)
		input_data->west_texture_path = ft_strdup(s[1]);
	s = ft_split(split_data[4], ' ');
	if (ft_strcmp(s[0], "EA") == 0)
		input_data->east_texture_path = ft_strdup(s[1]);
	s = ft_split(split_data[5], ' ');
	if (ft_strcmp(s[0], "S") == 0)
		input_data->sprite_texture_path = ft_strdup(s[1]);
	s = ft_split(split_data[6], ' ');
	if (ft_strcmp(s[0], "F") == 0)
		input_data->floor_color = ft_strdup(s[1]);
	s = ft_split(split_data[7], ' ');
	if (ft_strcmp(s[0], "C") == 0)
		input_data->ceiling_color = ft_strdup(s[1]);
*/

	/*int j = 0;*/

	/*while(split_data[8 + j])*/
	/*{*/
		/*printf("!!!!!!!!!!! %s\n", (split_data)[8 + j]);*/
		/*j++;*/
	/*}*/

	/*printf("%d\n", j);*/
	/*free(s);*/

	print_input_data(input_data);
	/*ft_putstr(buffer);*/
	return 0;
}













int main()
{
	// Location of current MLX instance
	void *mlx;
	t_window window;
	t_data img;
	void *win_ptr;


	t_input_data *input_data;

	input_data = malloc(sizeof(t_input_data));
	if (!input_data)
		return (-1);


	parse_intput(input_data);




	window.x = 300;
	window.y = 400;

	// INIT MLX INSTANCE
	mlx = mlx_init();

	// POINT TO WINDOW
	win_ptr = mlx_new_window(mlx, window.x , window.y, "name");

	// CREATE NEW IMAGE
	img.img = mlx_new_image(mlx, window.x , window.y);

	// POPULATE IMAGE
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// SEND IMAGE TO WINDOW
	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);

	// WINDOW STAY OPEN
	mlx_loop(mlx);

	return (0);
}

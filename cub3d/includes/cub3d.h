/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:42:55 by wszurkow          #+#    #+#             */
/*   Updated: 2021/04/08 20:27:01 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"
#include "../libft/libft.h"


///////////////////////////

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

typedef struct s_paint
{
	int x_offset;
	int y_offset;
	int color;
}				t_paint;

///////////////////////////

typedef struct s_map
{
	char **map_data;
	char **map_cells;
	int number_rows;
	int number_columns;
}				t_map;

typedef struct s_img
{
	t_data *map;
	t_data *player;
	int x_player_pos;
	int y_player_pos;
}	t_img;

typedef struct s_window
{
	int x_resolution;
	int y_resolution;
}			t_window;

typedef struct s_map_textures
{
	char *north_texture_path;
	char *south_texture_path;
	char *east_texture_path;
	char *west_texture_path;
	char *sprite_texture_path;
	int floor_color;
	int ceiling_color;
}				t_map_textures;

typedef struct s_global
{
	char **error;
	int valid_parameter_count;

	char **map_data;
	t_window *window;

	void		*mlx;
	void 		*win;
	t_paint *paint;
	t_data *data;
	t_data *minimap;
	t_data *buffer;
	t_data *player;

	t_map *map;
	t_map_textures *map_textures;
}				t_global;

void	cub3d_entrypoint(void);
int get_next_line(char **line, int fd);

//DISPLAY
void	mlx_entrypoint(t_global *g);
void 	init_mlx_struct(t_global *g);
void	init_mlx(t_global *g);
void	init_image(t_global *g, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 	key_hook(int keycode, t_global *g);

// MEMORY
int		init_global_struct(t_global *g);
void	free_everything(t_global *g);

// UTILS
int		is_in_charset(char c, char *charset);
int		ft_is_number(char *str);
int		number_of_args(char **line);
char 	**dual_realloc(char **double_ptr, char *line);
int		detect_map_line(char *line);
void	append_error(t_global *g, char *id, char *message);
void	show_errors(t_global *g);

// PARSERS
void	parse_input(t_global *g);

// PARAMS
void	parse_line_resolution(char **line, t_global *g);
void	parse_line_paths(char **line, t_global *g);

// MAP
void	parse_map(char *line, int fd, t_global *g);
void	check_borders(t_global *g, int line_count, int largest_line);
void		check_walls(t_global *g, int line_count, int largest_line);


#endif

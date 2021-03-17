
#include "../includes/cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	/*char    *dst;*/


	// dst is the adress of the pixel to colorize
	// int offset = (y * line_length + x * (bits_per_pixel / 8));

	char *dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


// UTILS----------------------------- //

int ft_strlen(char *str)
{
	int i;
	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
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

int get_next_line(char **line, int fd, t_map *map)
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



int main()
{
	int fd;
	char **line;
	int max_chars;
	int number_chars;
	int number_lines;
	int TEMP;
	int chars_in_line;
	t_window window;
	t_map map;

	line = malloc(sizeof (char *));
	fd = open("./map_only.cub", O_RDONLY);

	chars_in_line = 0;
	max_chars = 0;
	number_chars = 0;
	number_lines = 0;
	TEMP = 0;

	while (((chars_in_line = number_chars = get_next_line(line, fd, &map)) > 0))
	{
		if (map.largest_row < chars_in_line)
			map.largest_row = chars_in_line;
		map.number_rows++;
	}

	printf("-- %d\n", map.largest_row);
	printf("-- %d\n", map.number_rows);
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




	window.x = 300;
	window.y = 400;
	TEMP = window.x / TEMP;
	printf("border cell dimension %d\n", TEMP);




	// Location of current MLX instance
	void *mlx;
	t_data img;
	void *win_ptr;

	// INIT MLX INSTANCE
	mlx = mlx_init();

	// POINT TO WINDOW
	win_ptr = mlx_new_window(mlx, window.x , window.y, "name");

	// CREATE NEW IMAGE
	img.img = mlx_new_image(mlx, window.x , window.y);

	// POPULATE IMAGE
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int inc;
	inc = 0;

	int i = 0;
	int n = 0;
	while (get_next_line(line, fd, &map) > 0)
	{
		printf("line -> |%s|\n", *line);
		inc = 0;
		while ((*line)[inc] != '\0')
		{
			ft_put_square(&img, TEMP, n, inc, (*line)[inc]);
			inc++;
		}
		n++;
	}

	/*
	   ft_put_square(&img , 50 , 50, 0, 50);
	   ft_put_square(&img , 50 , 50, 0, 150);
	   ft_put_square(&img , 50 , 50, 0, 100);
	   ft_put_square(&img , 50 , 50, 0, 0);
	   */

	// SEND IMAGE TO WINDOW
	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);

	// WINDOW STAY OPEN
	mlx_loop(mlx);
}


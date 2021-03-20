/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:43:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/20 21:20:12 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	check_borders(t_global *g, int line_count, int largest_line)
{
	int i;
	int j;
	int flag;
	char **map;

	flag = 0;
	map = g->map_data;
	i = -1;
	while (map[0][++i])
		if (map[0][i] != ' ' && map[0][i] != '1')
			flag = 1;
	i = -1;
	while (map[line_count - 1][++i])
		if (map[line_count - 1][i] != ' ' && map[line_count - 1][i] != '1')
			flag = 1;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
			flag = 1;
	}
	i = -1;
	while (map[++i])
	{
		j = largest_line - 1;
		while (map[i][j] == ' ')
			j--;
		if (map[i][j] != '1')
			flag = 1;
	}
	if (flag)
		append_error(g, "", "Map is not correctly closed at borders\n");
}

void	check_walls(t_global *g, int line_count, int largest_line)
{
	int i;
	int j;
	int flag;
	char **map;

	flag = 0;
	map = g->map_data;
	i = 0;
	while (map[++i] && i < line_count - 1)
	{
		j = 0;
		while (map[i][++j] && j < largest_line - 1)
		{
			if (map[i][j] == ' ')
			{
				if (!((map[i - 1][j] == ' ' || map[i - 1][j] == '1') && \
							(map[i + 1][j] == ' ' || map[i + 1][j] == '1') && \
							(map[i][j - 1] == ' ' || map[i][j - 1] == '1') && \
							(map[i][j + 1] == ' ' || map[i][j + 1] == '1')))
				{
					flag = 1;
				}
			}
		}
	}
	if (flag)
		append_error(g, "", "Invalid map within borders\n");
}

char	*add_spaces(char *str, int largest_line)
{
	int i;
	char *res;

	i = 0;
	res = malloc(sizeof(char *) * largest_line + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (i < largest_line)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}

void	process_map(t_global *g)
{
	int i;
	int largest_line;
	int line_count;
	int len;
	char **map;

	i = 0;
	len = 0;
	largest_line = 0;
	line_count = 0;
	map = g->map_data;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (largest_line < len)
			largest_line = len;
		line_count++;
		i++;
	}
	i = -1;
	while (map[++i])
		map[i] = add_spaces(map[i], largest_line);
	check_borders(g, line_count, largest_line);
	check_walls(g, line_count, largest_line);
}

void	parse_map(char *line, int fd, t_global *g)
{
	g->map_data = dual_realloc(g->map_data, line);
	while ((get_next_line(&line, fd) > 0))
	{
		if (detect_map_line(line) == 0)
		{
			if (*line != '\0')
				append_error(g, "", "Invalid map, line in middle or wrong data\n");
			free(line);
			line = NULL;
			break ;
		}
		g->map_data = dual_realloc(g->map_data, line);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	while ((get_next_line(&line, fd) > 0))
	{
		if (*line != '\0')
		{
			append_error(g, "", "Invalid map, line in middle or wrong data\n");
			free(line);
			line = NULL;
			break ;
		}
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	process_map(g);
}

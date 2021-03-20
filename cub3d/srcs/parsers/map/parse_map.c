/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:43:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/20 22:29:41 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static char	*add_spaces(char *str, int largest_line)
{
	int		i;
	char	*res;

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

static void	process_map(t_global *g)
{
	int		i;
	int		largest_line;
	int		line_count;
	int		len;
	char	**map;

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

static void	fetch_map(t_global *g, char *line, int fd)
{
	while ((get_next_line(&line, fd) > 0))
	{
		if (detect_map_line(line) == 0)
		{
			if (*line != '\0')
				append_error(g, "", "Invalid map, wrong data\n");
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
}

static void	check_remaining_map_data(t_global *g, char *line, int fd)
{
	while ((get_next_line(&line, fd) > 0))
	{
		if (*line != '\0')
		{
			append_error(g, "", "Invalid map, wrong data\n");
			free(line);
			line = NULL;
			break ;
		}
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}

void		parse_map(char *line, int fd, t_global *g)
{
	g->map_data = dual_realloc(g->map_data, line);
	fetch_map(g, line, fd);
	check_remaining_map_data(g, line, fd);
	process_map(g);
}

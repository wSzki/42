/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:08:41 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 16:55:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		get_next_line(int fd, char **line)
{
	int			r;
	char		b[BUFFER_SIZE + 1];
	static char	*s[256];
	char		*tmp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, b, 0) < 0)
		return (-1);
	if (!s[fd] && (!(s[fd] = ft_calloc(1, sizeof(char *)))))
		return (-1);
	while ((find_n(s[fd]) < 0) && (((r = read(fd, b, BUFFER_SIZE)) > 0)))
		s[fd] = ft_gnl_strjoin(s[fd], b, r);
	*line = ft_substr(s[fd], 0, find_n(s[fd]));
	if (find_n(s[fd]) < 0)
	{
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	tmp = s[fd];
	s[fd] = ft_substr(s[fd], find_n(s[fd]) + 1, ft_strlen(s[fd]));
	free(tmp);
	tmp = NULL;
	return (1);
}

#include <stdio.h>
int main()

{
	int fd = open("./test", O_RDONLY);
	char *line;

	int j;

	int i = get_next_line(fd, &line);
	printf("%s%d\n", "i : ", i);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%s%s\n", "line : ", line);
		j++;
	}
	printf("%s%d\n", "i : ", i);
}

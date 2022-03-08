/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_multiple_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:13:09 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 19:39:54 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int	multiple_fd(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("./get_next_line/to_read", O_RDONLY);
	fd2 = open("./get_next_line/to_read2", O_RDONLY);
	get_next_line(fd, &line);
	get_next_line(fd2, &line2);
	close(fd);
	close(fd2);
	if (ft_strcmp(line, "aaaaaaaaaaaaaaaaaaaaaaaaa")
		|| ft_strcmp(line2, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"))
		return (-1);
	return (0);
}

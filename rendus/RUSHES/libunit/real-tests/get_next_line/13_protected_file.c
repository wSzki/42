/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_protected_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:15:37 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 19:42:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl_tests.h"

int	protected_file(void)
{
	int		fd;
	int		ret;
	char	*line;
	t_buf	buf;

	buf.len = 0;
	ft_bzero(buf.buf, BUFFER_SIZE);
	fd = open("./get_next_line/to_read_locked", O_RDONLY);
	ret = get_next_line(fd, &line);
	close(fd);
	if (ret == -1)
		return (0);
	return (-1);
}

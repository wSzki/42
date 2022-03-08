/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_no_nl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:13:09 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 19:40:39 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int	no_nl(void)
{
	int		fd;
	int		ret;
	char	*line;
	t_buf	buf;

	buf.len = 0;
	ft_bzero(buf.buf, BUFFER_SIZE);
	fd = open("./get_next_line/no_nl", O_RDONLY);
	ret = get_next_line(fd, &line);
	buf_write(&buf, fd, line, ft_strlen(line));
	close(fd);
	if (ret != 0 || ft_strcmp(buf.buf, "NO NL"))
		return (-1);
	return (0);
}

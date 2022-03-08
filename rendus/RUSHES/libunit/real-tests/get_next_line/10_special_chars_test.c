/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_special_chars_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:19:16 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 19:41:14 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int	special_char_test(void)
{
	int		fd;
	int		ret;
	char	*line;
	t_buf	buf;

	buf.len = 0;
	ft_bzero(buf.buf, BUFFER_SIZE);
	fd = open("./get_next_line/to_read4", O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		buf_write(&buf, fd, line, ft_strlen(line));
		ret = get_next_line(fd, &line);
	}
	close(fd);
	if (ft_strcmp(buf.buf, "\t\t\t\t;"))
		return (-1);
	return (0);
}

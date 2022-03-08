/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:37:57 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 17:21:02 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	free_list(t_unit_test *list)
{
	t_unit_test	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	exit_error(char *str, t_unit_test *list)
{
	t_buf	buffer;

	buffer.len = 0;
	buf_write(&buffer, 2, str, ft_strlen(str));
	write(2, buffer.buf, buffer.len);
	free_list(list);
	exit(1);
}

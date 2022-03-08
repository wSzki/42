/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 10:31:25 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 11:06:55 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	while (count > 0)
	{
		if (*tmp != (unsigned char)ch)
			tmp++;
		else
			return (tmp);
		count--;
	}
	return (NULL);
}

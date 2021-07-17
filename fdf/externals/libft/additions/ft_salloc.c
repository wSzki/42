
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_salloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:14:22 by wszurkow          #+#    #+#             */
/*   Updated: 2020/12/07 16:04:32 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	*ft_salloc(size_t type_size, size_t size, void (free_all)(void *), void *g)
{
	void	*res;

	if (!(res = (void *)malloc(type_size * size)))
	{
		perror("Error");
		(free_all)(g);
	}
	ft_bzero(res, type_size * size);
	return (res);
}

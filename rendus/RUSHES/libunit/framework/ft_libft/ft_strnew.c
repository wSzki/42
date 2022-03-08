/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:37:55 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 10:59:47 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (0);
	i = 0;
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

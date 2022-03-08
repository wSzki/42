/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:04:05 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 11:31:04 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (0);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start] && i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
	}
	res[i] = '\0';
	return (res);
}

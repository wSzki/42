/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:54:13 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/08 23:01:09 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	*ft_strjoin_test_func(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (0);
	if (s1 && s2)
	{
		while (s1[i])
			res[j++] = s1[i++];
		i = 0;
		while (s2[i])
			res[j++] = s2[i++];
		res[j] = '\0';
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:16:56 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 21:28:07 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n_s1;
	size_t	n_s2;
	size_t	i;

	if (!s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	n_s1 = gnl_strlen(s1);
	n_s2 = gnl_strlen(s2);
	i = 0;
	str = (char *)malloc(n_s1 + n_s2 + 1);
	if (!str)
		return (NULL);
	str[n_s1 + n_s2] = '\0';
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	return (str);
}

char	*gnl_strdup(const char *s)
{
	char	*str;
	size_t	n;

	n = gnl_strlen(s);
	if (!s)
		return (NULL);
	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	gnl_memmove(str, s, n + 1);
	return (str);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*tmp2;

	tmp = dest;
	tmp2 = src;
	while (n--)
		*tmp++ = *tmp2++;
	return (dest);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		gnl_memcpy(dest, src, n);
	else
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

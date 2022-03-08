/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:40:14 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 21:27:15 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

long	chrindex(char *str, char c)
{
	int	i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

void	ft_str_realloc(char **str, char *new)
{
	free(*str);
	*str = new;
}

int	search_rest(t_listfd *fd_rest, char **line, char *readstr)
{
	long	i;

	i = chrindex(fd_rest->rest, '\n');
	if (i != -1)
	{
		*line = gnl_substr(fd_rest->rest, 0, i);
		ft_str_realloc(&(fd_rest->rest), gnl_strdup(fd_rest->rest + i + 1));
		i = 1;
		if (!*line || !(fd_rest->rest))
			i = -2;
		free(readstr);
		readstr = NULL;
	}
	return (i);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = gnl_strlen(s) - start;
	if (s_len >= len)
		s_len = len;
	str = (char *)malloc(s_len + 1);
	if (!str)
		return (NULL);
	while (*s && start--)
		s++;
	while (*s && len--)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}

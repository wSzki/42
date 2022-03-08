/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:41:52 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 21:47:53 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 128

typedef struct s_listfd
{
	int				fd;
	char			*rest;
	struct s_listfd	*next;
}				t_listfd;
int				get_next_line(int fd, char **line);
int				ft_readfile(char **readstr, t_listfd *f, char **line, int fd);
long			chrindex(char *str, char c);
void			ft_free(t_listfd *fd_rest, t_listfd **fds, char *readstr);
void			ft_str_realloc(char **str, char *new);
t_listfd		*search_fd(t_listfd **fds, int fd);
int				search_rest(t_listfd *fd_rest, char **line, char *readstr);
char			*gnl_substr(char const *s, unsigned int start, size_t len);
char			*gnl_strjoin(char const *s1, char const *s2);
char			*gnl_strdup(const char *s);
size_t			gnl_strlen(const char *s);
void			*gnl_memmove(void *dest, const void *src, size_t n);
#endif

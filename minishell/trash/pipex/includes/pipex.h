/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:05:22 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/08 14:11:12 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <stdarg.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>



typedef struct s_global
{
	char	**paths;
	char	*file1;
	int		fd[2];
	char	*file2;
	char	**cmd1;
	char	**cmd2;
}	t_global;

size_t			ft_strlen(const char *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *s1, const char *s2);
void			check_commands(t_global *g);
int				p_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *str, char c);
char			*p_strjoin(char const *s1, char const *s2);
void			p_parse_args(t_global *g, char **av, char **env);
#endif

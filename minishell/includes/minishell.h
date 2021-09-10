/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:22:55 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/10 13:19:59 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <stdarg.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_global
{
	char *path;

}	t_global;


// UTILS
char	**ft_split(char const *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void ms_exec(char *cmd_str, char **env);
size_t		ft_strlen(const char *str);


// PARSING

// PIPEX
int	pipex(int ac, char **av, char **env);
void	call_child(char **av, int *fd, char **env);
void	call_parent(char **av, int *fd, char **env);
char	*find_absolute_path(char *cmd);
void	error();





#endif

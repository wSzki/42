/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:22:55 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/14 18:30:20 by wszurkow         ###   ########.fr       */
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
void execute(char *cmd_str, char **env);
size_t		ft_strlen(const char *str);
void	ft_putstr(const char *str);
int		ft_strcmp(char *s1, char *s2);
char *extract_string(char *str, int len);




// PARSING
char **split_at_operators(char *cmd_str);



// PIPEX
int	pipex(int ac, char **av, char **env);
void	call_child(char **av, int *fd, char **env);
void	call_parent(char **av, int *fd, char **env);
char	*find_absolute_path(char *cmd);
void	error();

// BUILTINS
int	pwd(char **cmd_tab);
int	echo(char **cmd_tab);
int	cd(char **cmd_tab);
void catch_exit(char **cmd_tab, int status);





#endif

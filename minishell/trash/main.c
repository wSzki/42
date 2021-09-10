/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:45:52 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/08 23:11:14 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/minishell.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <stdarg.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

static char		**ft_free(char **tab, int index)
{
	while (index >= 0)
	{
		free((void *)tab[index]);
		index--;
	}
	free(tab);
	return (NULL);
}

static int		count_words(char const *str, char charset)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] != charset)
			i++;
		words++;
		while (str[i] && str[i] == charset)
			i++;
	}
	return (words);
}

static char		**count_letters(char const *str, char charset, char **tab)
{
	int i;
	int index;
	int letters;

	i = 0;
	index = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] && str[i] != charset)
		{
			letters++;
			i++;
		}
		if (!(tab[index] = malloc(sizeof(char) * (letters))))
			return (ft_free(tab, index));
		tab[index][letters] = 0;
		index++;
		while (str[i] && str[i] == charset)
			i++;
	}
	return (tab);
}

static char		**split_copy(char const *str, char charset, char **tab)
{
	int i;
	int index;
	int letters;

	i = 0;
	index = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] && str[i] != charset)
			tab[index][letters++] = str[i++];
		index++;
		while (str[i] && str[i] == charset)
			i++;
	}
	return (tab);
}

char			**ft_split(char const *str, char c)
{
	char	**tab;
	int		words;

	if (!str)
		return (NULL);
	while (*str && *str == c)
		str++;
	words = count_words(str, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	tab[words] = 0;
	tab = count_letters(str, c, tab);
	tab = split_copy(str, c, tab);
	return (tab);
}
size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		p_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char    *ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlen(s1);
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
char    *ft_strcpy(char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
char	*p_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(str = (char *)malloc(sizeof(char) * (len1 + len2)
						+ 1)))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}

char *final_path(char *cmd)
{
	char *str;
	char **all_paths;
	char *tmp_path;
	char *valid_path;
	int	i;

	i = 0;
	str = getenv("PATH");

	all_paths = ft_split(str, ':');

	while (all_paths[i])
	{
		tmp_path = p_strjoin(all_paths[i], "/");
		valid_path = p_strjoin(tmp_path, cmd);

		if (access(valid_path, F_OK) != -1)
		{
			free(tmp_path);
			return (valid_path);
		}
		free(tmp_path);
		tmp_path= NULL;
		free(valid_path);
		valid_path= NULL;
		i++;
	}
	exit (1); // TODO error management
}
void call_child(char **av, int *fd, char **env)
{
	int fdin;
	char **cmd;

	cmd = ft_split(av[2], ' ');
	fdin = open(av[1], O_RDONLY);
	if (fdin == -1)
		exit (1); //TODO error management
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
	close (fd[0]);
	execve(final_path(cmd[0]),  cmd, env);
}

void call_parent(char **av, int *fd, char **env)
{
	int fdout;
	char **cmd;

	cmd = ft_split(av[3], ' ');
	fdout = open(av[4], (O_WRONLY | O_TRUNC | O_CREAT), 0777);
	if (fdout == -1)
		exit (1); //TODO error management
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close (fd[1]);
	execve(final_path(cmd[0]),  cmd, env);



}
int main(int ac, char **av, char **env)
{
	int fd[2];
	pid_t pid;
	//	char *tmp[3];

	if (ac != 5)
		exit(1);
	/*	p_parse_args(g, av, env);
		check_commands(g);
		*/
	pipe(fd);
	pid = fork();
	if (pid == -1)
		exit (1); // TODO error management
	if (pid == 0)
		call_child(av, fd, env);
	else
	{
		waitpid(0, NULL, 0);
		call_parent(av,fd, env);
	}
	return (0);
}

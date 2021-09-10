/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:16:08 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/08 16:40:37 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

char	*full_path(char *path, char **env)
{
	int i;
	char **paths;
	
	i = 0;
	while (env[i])
	{
		if (p_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_split(&env[i][5], ':');
		i++;
	}
	if (paths == NULL)
		exit (1);//TODO add error management
}

void call_child(char **av, int *fd, char **env)
{
	int fdin;
	char **cmd;

	cmd = ft_split(av[2], ' ');
	fdin = open(av[1], O_RDONLY);
	if (fdin == -1)
		exit (1); //TODO error management
	dup2(fdin, STDIN_FILENO);
	dup2(fd[0], STDOUT_FILENO);
	close (fd[1]);
	execve(full_path(av[2], env), cmd, env);
}

void call_parent(t_global *g, char **av, int *fd)
{		
	int fdout;

	fdout = open(av[4], (O_WRONLY | O_TRUNC | O_CREAT), 0777);
	if (fdout == -1)
		exit (1); //TODO error management
	dup2(fdout, STDOUT_FILENO);
	dup2(g->fd[1], STDIN_FILENO);
	close (fd[0]);

	execve(g->path, g->cmd, g->env);


}


int main(int ac, char **av, char **env)
{
	int fd[2];
	t_global *g;
	pid_t pid;
	//	char *tmp[3];

	g = NULL;
	if (ac != 5)
		exit(1);
	g = malloc(sizeof(*g));
	if (!(g))
		return (1);
	/*	p_parse_args(g, av, env);
		check_commands(g);
		*/
	pipe(g->fd);
	pid = fork();
	if (pid == -1)
		exit (1); // TODO error management
	if (pid == 0)
		call_child(g, av, fd);
	else
		call_parent(g, av,fd);
	return (0);
}



































































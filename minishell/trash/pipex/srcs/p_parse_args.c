/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:20:18 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/08 16:39:05 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void p_parse_path(t_global *g, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (p_strncmp(env[i], "PATH=", 5) == 0)
			g->paths = ft_split(&env[i][5], ':');
		i++;
	}
	if (g->paths == NULL)
		exit (1);//TODO add error management

}
static void	fill_struct(t_global *g, char **av)
{
	g->paths = NULL;
	g->cmd1 = NULL;
	g->cmd2 = NULL;
	g->fd[0] = -1;
	g->fd[1] = -1;
	g->file1 = av[1];
	g->file2 = av[4];
	g->cmd1 = ft_split(av[2], ' ');
	if (g->cmd1 == NULL)
		exit(1); // TODO error management
	g->cmd2 = ft_split(av[3], ' ');
	if (g->cmd2 == NULL)
		exit(1); // TODO error management
}

static void	check_files(t_global *g)
{
	g->fd[0] = open(g->file1, O_RDONLY);
	if (g->fd[0] == -1)
		exit(1); // TODO add error management
	//TODO change flags for read/write
	g->fd[1] = open(g->file2, O_RDONLY);
	if(g->fd[1] == -1)
		exit(1);
}

void	p_parse_args(t_global *g, char **av, char **env)
{
	fill_struct(g, av);
	check_files(g);
	p_parse_path(g, env);
	printf("file 1 =%s\n", g->file1);
	printf("file 2 =%s\n", g->file2);
	printf("fd 1 =%i\n", g->fd[0]);
	printf("fd 2 =%i\n", g->fd[1]);
}

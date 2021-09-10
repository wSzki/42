/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:41:50 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/10 13:18:38 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pipex(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		exit(1);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		exit (1); // TODO error management
	if (pid == 0)
	{
		call_child(av, fd, env);
	}
	else
	{
		/*waitpid(pid, NULL, 0);*/
		call_parent(av, fd, env);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}

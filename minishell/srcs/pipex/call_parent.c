/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:43:30 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/10 13:14:51 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	call_parent(char **av, int *fd, char **env)
{
	int		fdout;
	char	**cmd;

	cmd = ft_split(av[3], ' ');
	fdout = open(av[4], (O_WRONLY | O_TRUNC | O_CREAT), 0777);
	if (fdout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close (fd[1]);
	execve(find_absolute_path(cmd[0]), cmd, env);
}

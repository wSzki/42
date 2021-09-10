/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:42:27 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/10 13:14:39 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	call_child(char **av, int *fd, char **env)
{
	int		fdin;
	char	**cmd;

	cmd = ft_split(av[2], ' ');
	fdin = open(av[1], O_RDONLY, 0777);
	if (fdin == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
	close (fd[0]);
	execve(find_absolute_path(cmd[0]), cmd, env);
	free(cmd);
}

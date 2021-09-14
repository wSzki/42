/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:19:39 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/14 17:42:06 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	void cd_to_tilde(void)
{
	chdir(getenv("HOME"));
}

static void	cd_with_absolute_path(char **cmd_tab)
{
	chdir(getenv("HOME"));
	chdir(cmd_tab[1]);
}

static void	cd_with_relative__path(char **cmd_tab)
{
	chdir(cmd_tab[1]);
}
int cd(char **cmd_tab)
{

	if (!cmd_tab)
		return (-1);

	if (ft_strcmp(cmd_tab[0], "cd") == 0)
	{
		if(!cmd_tab[1])
		{
			cd_to_tilde();
			return (1);
		}
		else 
		{
			if (cmd_tab[1][0] == '/')
				cd_with_absolute_path(cmd_tab);
			else
				cd_with_relative__path(cmd_tab);
			return (1);
		}
	}
	return (0);
}

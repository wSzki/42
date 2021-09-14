/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:21:38 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/14 18:56:16 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define IS_BUILTIN 1
#define IS_NOT_BUILTIN 0
#define ERROR -1
#define NO_ERROR_FOUND 0

static int	catch_pwd_error(char **cmd_tab)
{
	if (cmd_tab[1] == NULL)
		return (0);
	ft_putstr("minishell: pwd: ");
	write(1, &cmd_tab[1][0], 1);
	write(1, &cmd_tab[1][1], 1);
	ft_putstr(": invalid option\n");
	ft_putstr("pwd: usage: pwd [NO ARGUMENTS]\n");
	return (1);
}

static void	print_cwd(void)
{
	ft_putstr(getcwd(0, 0));
	write(1, "\n", 1);
}

int	pwd(char **cmd_tab)
{
	if (!cmd_tab)
		return (ERROR);
	if (ft_strcmp(cmd_tab[0], "pwd") == 0)
	{
		if (catch_pwd_error(cmd_tab) == NO_ERROR_FOUND)
		{
		print_cwd();
		}
		return (IS_BUILTIN);
	}
	return (IS_NOT_BUILTIN);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:53:09 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/11 00:04:53 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO
// exit must close the parent as well as the current process by calling its PID
// must fix all potential leaks before
// is g necessery?


void	catch_exit(char **cmd_tab, int status)
{
	if (!cmd_tab)
		return ;
	if (ft_strcmp(cmd_tab[0], "exit") == 0)
	{
		exit(status);
	}
}

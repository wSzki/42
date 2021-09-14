/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:53:49 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/14 19:07:04 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*static void	echo_with_nl(char **cmd_tab)*/
/*{*/
	/*ft_putstr(cmd_tab[1]);*/
	/*ft_putstr("\n");*/
/*}*/
/*static void	echo_without_nl(char **cmd_tab)*/
/*{*/
	/*if (!cmd_tab[2])*/
	/*{*/
		/*ft_putstr("\n");*/
	/*}*/
	/*else*/
		/*ft_putstr(cmd_tab[2]);*/
/*}*/

int	echo(char **cmd_tab)
{
	(void)cmd_tab;
	/*if (!cmd_tab)*/
		/*return (-1);*/

	/*if (ft_strcmp(cmd_tab[0], "echo") == 0)*/
	/*{*/
		/*if (cmd_tab[1][0] == '-' && cmd_tab[1][1] == 'n')*/
		/*{*/
			/*echo_without_nl(cmd_tab);*/
			/*return (1);*/
		/*}*/
		/*else*/
		/*{*/
			/*echo_with_nl(cmd_tab);*/
			/*return (1);*/
		/*}*/
	/*}*/
	return (0);
}

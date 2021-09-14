/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 04:43:25 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/11 04:48:14 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void expand(char **cmd_tab)
{
	int i;
	int j;


	while (cmd_tab[i])
	{
		while (cmd_tab[i][j])


	}




}





void	input_parsing(char *line, char **env)
{
	char **initial_split;

	initial_split = ft_split(line, ' ');
	expand(initial_split);







	free(initial_split);










}

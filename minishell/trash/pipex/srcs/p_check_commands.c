/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:01:24 by adlancel          #+#    #+#             */
/*   Updated: 2021/09/07 17:24:50 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	check_commands1(t_global *g)
{
	int i;
	int flag;
	char *tmp_path;
	char *current_path;

	i = 0;
	flag = 0;
	while (g->paths[i])
	{
		tmp_path = p_strjoin(g->paths[i], "/");
		current_path = p_strjoin(tmp_path, g->cmd1[0]);
		if (access(current_path, F_OK) != -1)
		{
			flag = 1;
			break;
		}
		free (tmp_path);
		tmp_path = NULL;
		free(current_path);
		current_path= NULL;
		i++;

	}
	if (!flag)
	{
		free (tmp_path);
		free(current_path);
		exit(1);//TODO error management;
	}
	g->cmd1[0] = p_strjoin("", current_path);
	free (tmp_path);
	free (current_path);
}


static void	check_commands2(t_global *g)
{
	int i;
	int flag;
	char *tmp_path;
	char *current_path;

	i = 0;
	flag = 0;
	while (g->paths[i])
	{
		tmp_path = p_strjoin(g->paths[i], "/");
		current_path = p_strjoin(tmp_path, g->cmd2[0]);
		if (access(current_path, F_OK) != -1)
		{
			flag = 1;
			break;
		}
		free (tmp_path);
		tmp_path = NULL;
		free(current_path);
		current_path= NULL;
		i++;

	}
	if (!flag)
	{
		free (tmp_path);
		free(current_path);
		exit(1);//TODO error management;
	}
	g->cmd2[0] = p_strjoin("", current_path);
	free (tmp_path);
	free (current_path);
}

void	check_commands(t_global *g)
{
	check_commands1(g);
	check_commands2(g);
}

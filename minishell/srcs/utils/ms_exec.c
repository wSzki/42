/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:02:33 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/10 14:44:55 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void ms_exec_from_path(char *cmd_str, char **env)
{
	int i;
	char **cmd_tab; // NOTE : cmd_tab must end with NULL
	char *absolute_path;

	i = -1;
	cmd_tab = ft_split(cmd_str, ' ');
	absolute_path = find_absolute_path(cmd_tab[0]);
	if (execve(absolute_path, cmd_tab, env) == -1)
	{
		free(absolute_path);
		while (cmd_tab[++i])
			free(cmd_tab[i]);
		free(cmd_tab);
		perror("Error");
		exit (1);
		// TODO error management
	}
	free(absolute_path);
	while (cmd_tab[++i])
		free(cmd_tab[i]);
	free(cmd_tab);
}

static void ms_exec_from_cwd(char *cmd_str, char **env)
{
	int i;
	char **cmd_tab; // will contain cmd + all flags
	char *absolute_path; // will contain path of the command


	i = -1;
	cmd_str = cmd_str + 1; // remove "." from "./cmd_str"
	cmd_tab = ft_split(cmd_str + 1, ' '); //  remove "/"

	absolute_path = getcwd(NULL, 0);
	absolute_path = ft_strjoin(absolute_path, cmd_tab[0]); // joining cwd with cmd
	if (execve(absolute_path, cmd_tab , env) == -1)
	{
		free(absolute_path);
		while (cmd_tab[++i])
			free(cmd_tab[i]);
		free(cmd_tab);
		perror("Error");
		exit (1);
		// TODO error management
	}
	while (cmd_tab[++i])
		free(cmd_tab[i]);
	free(absolute_path);
	free(cmd_tab);
}

void ms_exec(char *cmd_str, char **env)
{
	// THIS FUNCTION NEEDS CMD_STR WHICH HAS BEEN ALREADY PARSED must contain [exec][-flags...]

	// if executable is in cwd
	if (ft_strncmp(cmd_str, "./", 2) == 0)
		ms_exec_from_cwd(cmd_str, env);
	// if not, search all paths and try to execute
	else
		ms_exec_from_path(cmd_str, env);
}

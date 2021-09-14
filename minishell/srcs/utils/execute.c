/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:02:33 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/14 19:08:52 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define ERROR 1
#define OK 0
#define NOT_BUILTIN 0

static int catch_builtin(char *cmd_str)
{
	int i;
	int is_builtin;
	char **cmd_tab;

	i = 0;
	is_builtin = 0;
	cmd_tab = ft_split(cmd_str, ' ');
	catch_exit(cmd_tab, 1);
	is_builtin += pwd(cmd_tab);//TODO env settings
	is_builtin += cd(cmd_tab);
	is_builtin += echo(cmd_tab);
	/*is_builtin = export(cmd_tab);*/
	/*is_builtin = unset(cmd_tab);*/
	/*is_builtin = env(cmd_tab);*/
	while (cmd_tab[++i])
		free(cmd_tab[i]);
	free(cmd_tab);
	return (is_builtin);
}

static int exec_from_cwd(char *cmd_str, char **env)
{
	int i;
	char **cmd_tab; // will contain cmd + all flags
	char *absolute_path; // will contain path of the command


	i = -1;
	cmd_str = cmd_str + 1; // remove "." from "./cmd_str"
	cmd_tab = ft_split(cmd_str, ' ');
	absolute_path = getcwd(NULL, 0);
	absolute_path = ft_strjoin(absolute_path, cmd_tab[0]); // joining cwd with cmd
	if (execve(absolute_path, cmd_tab , env) == -1)
	{
		free(absolute_path);
		while (cmd_tab[++i])
			free(cmd_tab[i]);
		free(cmd_tab);
		perror("Error");
		return (ERROR);
		// TODO error management
	}
	while (cmd_tab[++i])
		free(cmd_tab[i]);
	free(absolute_path);
	free(cmd_tab);
	return (OK);
}

static int exec_from_path(char *cmd_str, char **env)
{
	int i;
	char **cmd_tab; // NOTE : cmd_tab must end with NULL
	char *absolute_path;

	i = -1;
	cmd_tab = ft_split(cmd_str, ' ');
	absolute_path = find_absolute_path(cmd_tab[0]);
	if (absolute_path == NULL || execve(absolute_path, cmd_tab, env) == -1)
	{
		free(absolute_path);
		while (cmd_tab[++i])
			free(cmd_tab[i]);
		free(cmd_tab);
		perror("Error");
		return (ERROR);
		// TODO error management
	}
	free(absolute_path);
	while (cmd_tab[++i])
		free(cmd_tab[i]);
	free(cmd_tab);
	return (OK);
}


void execute(char *cmd_str, char **env)
{
	// THIS FUNCTION NEEDS CMD_STR WHICH HAS BEEN ALREADY PARSED must contain [exec][-flags...]
	if (catch_builtin(cmd_str) == NOT_BUILTIN)
	{
		if (ft_strncmp(cmd_str, "./", 2) == 0) // if executable is in cwd
			exec_from_cwd(cmd_str, env);
		else // if not, search all paths and try to execute
			exec_from_path(cmd_str, env);
	}
}

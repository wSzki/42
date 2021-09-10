/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:53:24 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/09 17:21:32 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include <unistd.h>

static void ms_exec_from_path(char *cmd_str, char **env)
{
	char **cmd_tab;
	char *absolute_path;

	absolute_path = find_absolute_path(cmd_str);
	cmd_tab = ft_split(cmd_str, ' ');
	if (execve(absolute_path, cmd_tab , env) == -1)
	{
		perror("Error");
		// TODO error management
	}
	free(cmd_tab);
}

static void ms_exec_from_cwd(char *cmd_str, char **env)
{
	char **cmd_tab; // will contain cmd + all flags
	char *absolute_path; // will contain path of the command

	cmd_str = cmd_str + 1; // remove "." from ./cmd_str
	cmd_tab = ft_split(cmd_str, ' ');

	absolute_path = getcwd(NULL, 0);
	absolute_path = ft_strjoin(absolute_path, cmd_tab[0]); // joining cwd with cmd
	if (execve(absolute_path, cmd_tab , env) == -1)
	{
		perror("Error");
		// TODO error management
	}
	free(cmd_tab);
}

void ms_exec(char *cmd_str, char **env)
{
	// THIS FUNCTION NEEDS CMD_STR WHICH HAS BEEN ALREADY PARSED must contain [exec][-flags...]

	// if executable is in cwd
	if (strncmp(cmd_str, "./", 2) == 0)
		ms_exec_from_cwd(cmd_str, env);
	else
		ms_exec_from_path(cmd_str, env);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	char *line;
	pid_t pid;

	/*pipex(ac, av, env);*/
	while (1)
	{
		line = readline("Prompt > ");
		pid = fork();
		waitpid(0, NULL, 0);
		if (pid == 0)
			ms_exec(line , env);
	}
	return (0);
}

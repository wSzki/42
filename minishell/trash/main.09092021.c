/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:53:24 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/09 16:42:45 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include <string.h>



/*static void ms_exec_from_path(char *cmd_str, char **env)*/
/*{*/
	/*char **cmd;*/
	/*char *absolute_path;*/

	/*absolute_path = find_absolute_path(cmd_str);*/
	/*cmd = ft_split(cmd_str, ' ');*/

/*}*/


/*static void ms_exec_from_cwd(char *cmd_str, char **env)*/
/*{*/
	/*char **cmd_tab;*/
	/*char *cmd;*/
	/*char *cmd_flags;*/
	/*char *absolute_path;*/
	/*cmd_str = cmd_str + 2;*/
	/*cmd_tab = ft_split(cmd_str, ' ');*/
	/*absolute_path = getcwd(NULL, 0);*/
	/*absolute_paht = ft_strjoin(absolute_path, cmd_str[])*/
/*}*/



/*void ms_exec(char *cmd_str, char **env)*/
/*{*/
	/*// if executable is in cwd*/
	/*if (strncmp(cmd_str, "./", 2) == 0)*/
	/*{*/


	/*}*/



/*}*/









void execute(char *line, char **env)
{
	(void)line;

	char **cmd;
	char *absolute_path;

	absolute_path = find_absolute_path(line);
	cmd = ft_split(line, ' ');
	if (!absolute_path)
	{
		absolute_path = getcwd(NULL, 0);
		printf("%s%s\n", "", absolute_path);
		if ((execve(absolute_path, cmd, env)) == -1)
			error();
		printf("%s%s\n", "", "");
	}
	execve(absolute_path, cmd , env);

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
			execute(line , env);
	}
	return (0);
}

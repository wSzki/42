/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:53:24 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/14 19:07:34 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"


/*static char *strip_whitespaces(char *str)*/
/*{*/
	/*char *tmp;*/




/*}*/


int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *line;
	pid_t pid;
	/*pipex(ac, av, env);*/


	/*char *cmd_str = "|hello '|\"|||' >> yes ||>>>>>>|\"|'|||\" no | 'he'llo | wuu |";*/
	/*char *cmd_str = "|hello | one | two |three|";*/
	char *cmd_str = " bonjour | file.txt";
	///////////////////////////////////////////
	char **cmd = split_at_operators(cmd_str);
	/*int i;*/

	/*i = 0;*/
	/*while (cmd[i])*/
	/*{*/
		/*if (i % 0)*/
		/*{*/
			/*strip_whitespaces(cmd[i]);*/

		/*}*/
		/*i++;*/
	/*}*/



	free(cmd);
	//////////////////////////////////////////


	while (1)
	{
		line = readline("Prompt > ");

		pid = fork();
		waitpid(0, NULL, 0);
		if (pid == 0)
			execute(line , env);
		free(line);
		line = NULL;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:53:24 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/10 14:45:32 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

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
		free(line);
		line = NULL;
	}
	return (0);
}







#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

#define ERROR -1
#define ERR_SYS 1
#define ERR_EXEC 2
#define ERR_CD 3
#define ERR_CHDIR 4


void puterr(char *str)
{
	write(2, str, sizeof(str));
}


void error(char **cmd, int err_code)
{
	if (err_code == ERR_SYS)
		puterr("error: fatal\n");
	free(cmd);
	exit(1);
}

char **cue(int ac, char **av, int *i)
{
	int j = *i;
	char **cmd;

	while (j < ac && strcmp(av[j], ";") != 0)
		j++;
	if (j == *i)
		return (NULL);
	cmd = malloc(sizeof(char *) * j + 1);
	if (cmd == NULL)
		error(cmd, ERR_SYS);
	j = 0;
	while (*i < ac && strcmp(av[*i], ";") != 0)
	{
		cmd[j] = av[*i];
		j++;
		*i += 1;
	}
	cmd[j] = NULL;
	*i += 1;
	return (cmd);
}


char **find_next_pipe(char **cmd)
{
	int i = 0;

	while (cmd[i])
	{
		if (strcmp(cmd[i], "|") == 0)
			return (&cmd[i + 1]);
		i++;
	}
	return (NULL);
}

void cd(char **cmd)
{
	int j = 0;

	while (cmd[j])
		j++;
	if (j != 2)
		error(cmd, ERR_CD);
	if (chdir(cmd[1]) == ERROR)
		error(cmd, ERR_CHDIR);
}

void execute_single_command(char **cmd, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		if (execve(cmd[0], cmd, env) == ERROR)
			error(cmd, ERR_EXEC);
	waitpid(0, 0, 0);
}


void child(char **cmd, char **env, int *fd, int fd_in)
{
	int i = 0;
	dup2(fd_in, STDIN_FILENO); /////////////////////////////////
	if (find_next_pipe(cmd))//////////////////////////////////
		dup2(fd[1], STDOUT_FILENO);////////////////////////////////
	close(fd_in);////////////////////////////////////////////////
	close(fd[0]);//////////////////////////////////////////////
	close(fd[1]);/////////////////////////////////////////////
	while (cmd[i] && strcmp(cmd[i], "|") != 0)
		i++;
	cmd[i] = NULL;
	if (execve(cmd[0], cmd, env) == ERROR)
		printf("error\n");
	exit(0);
}

void pipeline(char **cmd, char **env)
{
	int fd_in;
	int fd[2];
	int n;
	pid_t pid;

	n = 0;
	fd_in = dup(STDIN_FILENO); //////////////////////////////
	while (cmd)//////////////////////////////////////
	{/////////////////////////////////////////////////
		pipe(fd); /////////////////////////////////
		pid = fork(); /////////////////////////////
		if (pid == 0)/////////////////////////////////
			child(cmd, env, fd, fd_in);///////////////
		else////////////////////////////////////////
		{///////////////////////////////////////////
			dup2(fd[0], fd_in); //////////////////////
			close(fd[0]); //////////////////////////
			close(fd[1]); ///////////////////////////
			n++;///////////////////////////////////
			cmd = find_next_pipe(cmd);/////////////
		}//////////////////////////////////////////
	}//////////////////////////////////////////////
	close(fd_in);/////////////////////////////////
	while (n--)///////////////////////////////////
		waitpid(0,0,0);///////////////////////////
}

void execute(char **cmd, char **env)
{
	if (strcmp("cd", cmd[0]) == 0) 			// if cd
		cd(cmd);
	else if ((find_next_pipe(cmd)) == NULL)	// if no pipe
		execute_single_command(cmd, env);
	else
		pipeline(cmd, env); 				// if pipe
}

int main(int ac, char **av, char **env)
{
	int i = 1;
	char **cmd;

	cmd = NULL;
	while (i < ac)
	{
		cmd = cue(ac, av, &i); // extract to next ;
		if (cmd)
			execute(cmd, env);
		else
			i++;
		free(cmd);
		cmd = NULL;
	}
	return (0);
}



#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>


void	pwd(char **cmd_tab)
{
	int i;
	char *pwd;

	pwd = getcwd(0, 0);
	while (pwd[i])
	{
		write(1, &pwd[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	pwd();
	return (0);
}

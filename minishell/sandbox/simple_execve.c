#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>



int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *cmd[3] = {"ls", "-la", NULL};
	int i = 0;

	i =	execve("/bin/ls", cmd, env);
	printf("%s%s\n", "", cmd[0]);
	printf("%s%d\n", "", i);

	return (0);
}

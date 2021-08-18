#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle(int sig)
{
	printf("%s\n", "handler works");

}
int main(int ac, char **av)
{
	int pid = fork();

	if (pid == -1)
		return 1;
	// CHILD
	if (pid == 0)
	{
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	// PARENT
	else
	{
		struct sigaction sa;
		/*sa.sa_flags = SA_RESTART;*/
		sa.sa_handler = &handle;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);

		int x;
		sleep(1);
		printf("%s\n", "hi");
		pause();
	}
}

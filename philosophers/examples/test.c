

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <stdarg.h>
#include <fcntl.h>

pthread_mutex_t lock;
int mails = 0;

void	*routine()
{
	int i;
	/*pthread_mutex_lock(&lock);*/
	/*printf("%s\n", "---- [1] ----");*/
	/*sleep(3);*/
	/*printf("%s\n", "---- [2] ----");*/
	/*pthread_mutex_unlock(&lock);*/
	pthread_mutex_lock(&lock);
	while (i++ < 100000000)
		mails++;
	pthread_mutex_unlock(&lock);
	return (NULL);
}


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t t1;
	pthread_t t2;

	if (pthread_mutex_init(&lock, NULL) != 0)
		return 1;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_join(t1, NULL) != 0)
		return 1;
	if (pthread_join(t2, NULL) != 0)
		return 1;
	pthread_mutex_destroy(&lock);
	printf("%s%d\n", "", mails);
	return (0);
}

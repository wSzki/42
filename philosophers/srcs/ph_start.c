/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 08:08:27 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/03 13:27:29 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*routine(void *argument)
{
	/*int *arg;*/
	t_global *g;

	g = (t_global *)argument;

	pthread_mutex_lock(&(g->lock)); ////////// LOCK

	printf("%s%d", "philo: ", g->i);
	g->i += 1;

	usleep(g->t_sleep);
	/*sleep(1);*/

	printf("%s\n", " is dead");

	pthread_mutex_unlock(&(g->lock)); //////////// UNLOCK

	return (NULL);
}

int	ph_start(t_global *g)
{
	int i;
	pthread_t *philo_thread;

	// init thread list
	philo_thread = malloc(sizeof(*philo_thread) * g->n_philo);
	if (!(philo_thread))
		return (0);
	// create thread list
	i = 0;
	g->i = 0;
	while (i < g->n_philo)
	{
		if (pthread_create(&philo_thread[i], NULL, &routine, g) != 0)
			return 1;
		if (pthread_join(philo_thread[i], NULL) != 0)
			return 1;
		i++;
	}

	 /*join all threads*/
	/*i = 0;*/
	/*while (i < g->n_philo)*/
	/*{*/
		/*if (pthread_join(philo_thread[i], NULL) != 0)*/
			/*return 1;*/
		/*i++;*/
	/*}*/
	return (0);


}

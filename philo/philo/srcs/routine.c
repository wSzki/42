/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:20:35 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/13 06:59:10 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	eat(t_data *d, t_philo *p)
{
	pthread_mutex_lock(&(d->forks[p->left_fork]));
	if (d->somebody_died || all_full(d))
		return ;
	putmsg(d, p, LEFT_FORK);
	pthread_mutex_lock(&(d->forks[p->right_fork]));
	if (d->somebody_died || all_full(d))
		return ;
	putmsg(d, p, RIGHT_FORK);
	putmsg(d, p, EATING);
	p->last_meal = timestamp();
	p->meals_eaten += 1;
	usleep(d->t_eat * 1000);
	pthread_mutex_unlock(&(d->forks[p->right_fork]));
	pthread_mutex_unlock(&(d->forks[p->left_fork]));
}

static void	nap(t_data *d, t_philo *p)
{
	putmsg(d, p, SLEEPING);
	usleep(d->t_sleep * 1000);
}

static void	think(t_data *d, t_philo *p)
{
	putmsg(d, p, THINKING);
}

void	*routine(void *ptr)
{
	t_philo	*p;
	t_data	*d;

	p = (t_philo *)ptr;
	d = p->d;
	while (1)
	{
		if (d->somebody_died == YES || all_full(d) == YES)
			break ;
		eat(d, p);
		if (d->somebody_died == YES || all_full(d) == YES)
			break ;
		nap(d, p);
		if (d->somebody_died == YES || all_full(d) == YES)
			break ;
		think(d, p);
		if (d->somebody_died == YES || all_full(d) == YES)
			break ;
		usleep(1);
	}
	return (NULL);
}

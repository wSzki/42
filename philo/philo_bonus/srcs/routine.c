/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:20:35 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/14 21:49:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	eat(t_data *d, t_philo *p)
{
	if (sem_wait(d->forks) == ERROR)
		error(d, SEM_ERROR);
	if (d->somebody_died || all_full(d))
		return ;
	putmsg(d, p, LEFT_FORK);
	if (sem_wait(d->forks) == ERROR)
		error(d, SEM_ERROR);
	if (d->somebody_died || all_full(d))
		return ;
	putmsg(d, p, RIGHT_FORK);
	putmsg(d, p, EATING);
	p->last_meal = timestamp();
	p->meals_eaten += 1;
	usleep(d->t_eat * 1000);
	if (sem_post(d->forks) == ERROR)
		error(d, SEM_ERROR);
	if (sem_post(d->forks) == ERROR)
		error(d, SEM_ERROR);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:26:08 by wszurkow          #+#    #+#             */
/*   Updated: 2021/11/13 05:46:03 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	monitoring(t_data *d, t_philo *p)
{
	int			i;
	long long	time;

	i = 0;
	time = 0;
	if (all_full(d))
		return (0);
	if (d->p[i].last_meal == 0)
		d->p[i].last_meal = timestamp();
	time = timestamp() - d->p[i].last_meal;
	if (time > p->d->t_die)
	{
		putmsg(d, &d->p[i], DEATH);
		p->d->somebody_died = YES;
		return (0);
	}
	if (++i == d->nb_philos)
		i = 0;
	usleep(1);
	return (1);
}

void	*monitor_death(void *ptr)
{
	t_philo		*p;
	t_data		*d;

	p = (t_philo *)ptr;
	d = p->d;
	while (1)
		if (monitoring(d, p) == 0)
			break ;
	return (NULL);
}

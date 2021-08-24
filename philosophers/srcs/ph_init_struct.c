/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:22:06 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/24 17:50:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static long	ph_timestamp(void)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return (timestamp.tv_sec * 1000000 + timestamp.tv_usec);
}

static void	ph_process_arguments(t_global *g, int ac, char **av)
{
	g->n_philo = ph_atoi_overflow(g, av[1]);
	g->t_die = ph_atoi_overflow(g, av[2]);
	g->t_eat = ph_atoi_overflow(g, av[3]);
	g->t_sleep = ph_atoi_overflow(g, av[4]);
	g->n_meals_to_eat = 0;
	if (ac == 6)
		g->n_meals_to_eat = ph_atoi_overflow(g, av[5]);
	g->n_deaths = 0;
	g->n_satiated = 0;
}

static void	ph_create_philosophers(t_global *g)
{
	int	i;

	i = 0;
	g->p = ph_malloc(g, sizeof(t_philosopher) * g->n_philo);
	while (i < g->n_philo)
	{
		g->p[i].id = i + 1;
		g->p[i].t_last_meal = ph_timestamp();
		g->p[i].left_fork_id = 0;
		g->p[i].right_fork_id = 0;
		g->p[i].meals_eaten = 0;
		i++;
	}
}

void	ph_init_struct(t_global *g, int ac, char **av)
{
	ph_process_arguments(g, ac, av);
	ph_create_philosophers(g);
}

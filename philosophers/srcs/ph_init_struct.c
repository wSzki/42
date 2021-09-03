/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:22:06 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/03 13:32:29 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_free_everything_exit(t_global *g, int errno)
{
	int	i;

	i = -1;
	if (errno == ERROR)
		ph_putstr(2, "Error\n");
	pthread_mutex_destroy(&g->lock);
	if (g->forks)
		while (++i < g->n_philo)
			pthread_mutex_destroy(&g->forks[i]);
	free(g->p);
	free(g->forks);
	free(g);
	exit(errno);
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
	g->p = ph_malloc(g, sizeof(*g->p) * g->n_philo);
	while (i < g->n_philo)
	{
		g->p[i].t_last_meal = ph_timestamp();
		g->p[i].left_fork_id = i;
		g->p[i].id = i + 1;
		g->p[i].right_fork_id = i + 2;
		g->p[i].meals_eaten = 0;
		i++;
	}
}

static void	ph_mutex_init(t_global *g)
{
	int	i;

	i = 0;
	g->forks = ph_malloc(g, sizeof(*g->forks) * g->n_philo);
	if (pthread_mutex_init(&g->lock, NULL) != 0)
		ph_free_everything_exit(g, ERROR);
	while (i < g->n_philo)
	{
		if (pthread_mutex_init(&(g->forks[i]), NULL) != 0)
			ph_free_everything_exit(g, ERROR);
		i++;
	}
}

void	ph_init_struct(t_global *g, int ac, char **av)
{
	g->p = NULL;
	g->forks = NULL;
	ph_process_arguments(g, ac, av);
	ph_create_philosophers(g);
	ph_mutex_init(g);
}

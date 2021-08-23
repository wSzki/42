/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:30:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/23 18:18:24 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

t_global *ph_init_g(void)
{
	t_global *g;

	g = NULL;
	g = malloc(sizeof(*g));
	if (!g)
	{
		ph_putstr(2, "Error\n");
		ph_putstr(2, "malloc failed");
		ph_putstr(2, "\n");
		exit(ERROR);
	}
	return (g);
}

void	ph_init_struct(t_global *g, char **av)
{
	g->n_philo = ph_atoi_overflow(g, av[1]);
	g->t_die = ph_atoi_overflow(g, av[2]);
	g->t_eat = ph_atoi_overflow(g, av[3]);
	g->t_sleep = ph_atoi_overflow(g, av[4]);

}

void	ph_free_everything_exit(void *g, int errno)
{
	free(g);
	exit(errno);
}

int main(int ac, char **av)
{
	t_global *g;

	ph_check_arguments(ac, av);
	g = ph_init_g();
	//////////////////////////////

	ph_init_struct(g, av);









	//////////////////////////////
	ph_free_everything_exit(g, OK);
}

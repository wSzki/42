/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:30:47 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/29 08:12:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "./includes/philo.h"

void	print_struct(t_global *g)
{
	printf("number philo		%d\n",    g->n_philo );
	printf("time to die		%d\n",      g->t_die );
	printf("time to eat		%d\n",      g->t_eat );
	printf("time to sleep		%d\n",    g->t_sleep );
	printf("number meals		%d\n",    g->n_meals_to_eat);
	printf("number deaths		%d\n",   g->n_deaths );
	printf("number satiated		%d\n", g->n_satiated );
}

void	ph_print_philo_data(t_global *g, int id)
{
	id--;
	printf("id %d\n", g->p[id].id);
	printf("t last %ld\n", g->p[id].t_last_meal);
	printf("l fork%d\n", g->p[id].left_fork_id);
	printf("r fork%d\n", g->p[id].right_fork_id);
	printf("meals eatin%d\n", g->p[id].meals_eaten);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////


t_global *ph_malloc_g(void)
{
	t_global *g;

	g = NULL;
	g = malloc(sizeof(*g));
	if (!g)
	{
		ph_putstr(2, "Error\n");
		ph_putstr(2, "malloc failed on *g");
		ph_putstr(2, "\n");
		exit(ERROR);
	}
	return (g);
}


int main(int ac, char **av)
{
	t_global *g;

	ph_check_arguments(ac, av);
	g = ph_malloc_g();
	ph_init_struct(g, ac, av);
	//////////////////////////////
	print_struct(g);
	ph_print_philo_data(g, 1);
	ph_start(g);

	//////////////////////////////
	ph_free_everything_exit(g, OK);
}

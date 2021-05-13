/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:38:31 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/13 18:50:23 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pushswap.h"



int *sub_s(int *tab)
{
	int tmp;

	tmp = 0;
	if (!(tab))
		return (0);
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	return (tab);
}

int sb(int *tab)
{
	tab = sub_s(tab);
	write(1, "sb\n", 3);
	return (1);
}

int sa(int *tab)
{
	tab = sub_s(tab);
	write(1, "sa\n", 3);
	return (1);
}

int ss(int *tab_a, int *tab_b)
{
	tab_a = sub_s(tab_a);
	tab_b = sub_s(tab_b);
	write(1, "ss\n", 3);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////


t_global *init_struct(t_global *g, int ac, char **av)
{
	if (ac < 2)
		print_error_and_exit(g);
	g = malloc(sizeof(t_global));
	if (!g)
		print_error_and_exit(g);
	g->tab_a = malloc(sizeof(int) * ac - 1);
	if (!g->tab_a)
		print_error_and_exit(g);
	g->tab_b = NULL;
	g->tab_a_size = ac - 1;
	g->tab_b_size = 0;
	g->av = &av[1];
	return (g);
}

int		main(int ac, char **av)
{
	t_global *g;

	g = NULL;
	g = init_struct(g, ac, av);



	free_everything(g);
}

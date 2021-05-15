/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:38:31 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/15 16:59:18 by wszurkow         ###   ########.fr       */
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

int pa(t_global *g)
{
	int i;
	int j;
	int *tmp;

	i = 0;
	j = 1;
	tmp = NULL;
	if (!(g->tab_b))
		return (1);
	tmp = malloc(sizeof(int) * g->tab_a_size + 1);
	tmp[0] = g->tab_b[0];
	while (i < g->tab_a_size)
	{
		tmp[j] = g->tab_a[i];
		i++;
		j++;
	}
	free(g->tab_a);
	g->tab_a = tmp;

	return (1);
}

////////////////////////////////////////////////////////////////////////////////


static t_global *init_g(t_global *g)
{
	g = malloc(sizeof(t_global));
	if (!g)
		print_error_and_exit();
	g->a = NULL;
	g->b = NULL;
	return (g);
}

static t_global *init_tab_a_and_b(t_global *g)
{
	g->a = malloc(sizeof(t_tab));
	if (!g->a)
	{
		free(g);
		print_error_and_exit();
	}
	g->b = malloc(sizeof(t_tab));
	if (!g->b)
	{
		free(g->a);
		free(g);
		print_error_and_exit();
	}
	g->a->data = NULL;
	g->b->data = NULL;
	g->a->size = NULL;
	g->b->size = NULL;
	return (g);
}

static t_global *init_tab_a_data(t_global *g, int ac)
{
	g->a->data = malloc(sizeof(int) * ac - 1);
	if (!g->a->data)
		free_everything_and_exit(g);
	g->a->size = malloc(sizeof(int));
	if (!g->a->size)
		free_everything_and_exit(g);
	*g->a->size = ac - 1;
	return (g);
}


static t_global *init_struct(t_global *g, int ac)
{
	g = init_g(g);
	g = init_tab_a_and_b(g);
	g = init_tab_a_data(g, ac);
	return (g);
}

int		main(int ac, char **av)
{
	t_global *g;

	g = NULL;
	if (ac < 2)
		print_error_and_exit();
	g = init_struct(g, ac);
	// =============================== //
	// TODO
	// Parse input arguments with atoi
	//
	// sa swap a
	// sb swap b
	// ss sa + sb
	//
	// pa push b[0] to a[0]
	// pb
	//
	// ra rotate a
	// rb
	// rr ra + rb
	//
	// rra reverse
	// rrb
	// rrr
	// =============================== //
	fill_tab_a(g, ac, av);

	printf("%d\n", g->a->data[0]);
	printf("%d\n", g->a->data[1]);

	// =============================== //
	free_everything(g);
	return (0);
}

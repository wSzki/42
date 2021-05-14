/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:38:31 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/13 21:16:33 by wszurkow         ###   ########.fr       */
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

void	ps_prepend(t_global *g, char tab_id, int value)
{
	int i;
	int j;
	int size;
	int *tmp;

	i = 1;
	j = 0;
	if (tab_id == 'a')
	{
		g->tab_a_size++;
		size = g->tab_a_size;
		tmp = malloc(sizeof(int) * size);
		tmp[0] = value;
		while (j < g->tab_a_size - 1)
			tmp[i++] = g->tab_a[j++];
		free(g->tab_a);
		g->tab_a = tmp;
	}

}
/*
void	ps_append(int *tab, int value)
{


}

void	delete_first(int *tab)
{


}
*/


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

///////////////////////////////////////////////////////////////////////////////////////////////////


/*void fill_structure(t_global *g, int ac, char **av)*/
/*{*/

	/*int i;*/

	/*i = 0;*/




/*}*/


void init_struct(t_global *g, int ac, char **av)
{
	g = malloc(sizeof(t_global));
	if (!g)
		print_error_and_exit(g);
	g->tab_a = malloc(sizeof(int) * ac - 1);
	if (!g->tab_a)
	{
		free(g);
		print_error_and_exit(g);
	}
	g->tab_b = NULL;
	g->tab_a_size = ac - 1;
	g->tab_b_size = 0;
	g->av = &av[1];
	if (ac < 2)
		print_error_and_exit(g);
}

int		main(int ac, char **av)
{
	t_global *g;

	g = NULL;
	init_struct(g, ac, av);
	/*fill_structure(g, ac, av);*/
	free_everything(g);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:38:31 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/14 21:27:16 by wszurkow         ###   ########.fr       */
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

void	ps_prepend(t_global *g, t_tab *tab, int value)
{
	int i;
	int j;
	int *res;

	i = 1;
	j = 0;
	tab->size++;
	res = malloc (sizeof(int) * tab->size);
	if (!res)
		free_everything_and_exit(g);
	res[0] = value;
	while (j < tab->size - 1)
		res[i++] = tab->data[j++];
	free(tab->data);
	tab->data = res;
	return ;
}

void	ps_append(t_global *g, t_tab *tab, int value)
   {
	int i;
	int *res;

	i = 0;
	tab->size++;
	res = malloc (sizeof(int) * tab->size);
	if (!res)
		free_everything_and_exit(g);
	while (i < tab->size - 1)
	{
		res[i] = tab->data[i];
		i++;
	}
	res[i] = value;
	free(tab->data);
	tab->data = res;
	return ;
   }

void	ps_delete_first(t_global *g, t_tab *tab)
{
	int i;
	int *res;

	i = 1;
	tab->size--;
	res = malloc (sizeof(int) * tab->size);
	if (!res)
		free_everything_and_exit(g);
	while (i < tab->size)
	{
		res[i] = tab->data[i];
		i++;
	}
	free(tab->data);
	tab->data = res;
	return ;
}

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


static void init_g(t_global *g)
{
	g = malloc(sizeof(t_global));
	if (!g)
		print_error_and_exit();
	g->a = NULL;
	g->b = NULL;
	return ;
}

static void init_tab_a_and_b(t_global *g)
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
		free(g);
		free(g->a);
		print_error_and_exit();
	}
	g->a->data = NULL;
	g->b->data = NULL;
	g->a->size = 0;
	g->b->size = 0;
	return ;
}

static void init_tab_a_data(t_global *g, int ac)
{
	g->a->data = malloc(sizeof(int) * ac - 1);
	if (!g->a->data)
		free_everything_and_exit(g);
	g->a->size = ac -1;
	return ;
}


static void init_struct(t_global *g, int ac)
{
	init_g(g);
	init_tab_a_and_b(g);
	init_tab_a_data(g, ac);
}

int		main(int ac, char **av)
{
	t_global *g;

	if (!av)
		write(1, "hello", 5);
	g = NULL;
	if (ac < 2)
		print_error_and_exit();
	init_struct(g, ac);
	free_everything(g);
	return (0);
}

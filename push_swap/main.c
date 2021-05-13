/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:38:31 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/13 16:13:49 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


typedef struct s_global
{
	int *tab_a;
	int *tab_b;
	int tab_a_size;
	int tab_b_size;
}				t_global;

void	free_everything(t_global *g)
{
	free(g->tab_a);
	free(g->tab_b);
	free(g);
}

static void	print_error_and_exit(t_global *g)
{
	free_everything(g);
	write(2, "Error\n", 6);
	exit(1);
}


////////////////////////////////////////////////////////////////////
//
//
//
static int	ft_count_numbers(int n)
{
	size_t i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str, t_global *g)
{
	long int	atoi;
	int			np;
	int			j;
	int			i;

	i = 0;
	j = 0;
	np = 1;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			np = -np;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && j++ >= 0)
		atoi = atoi * 10 + str[i++] - 48;
	i = ft_count_numbers(atoi);
	if (i == j)
		return (atoi * np);
	if (np < 0)
		return (0);
	print_error_and_exit(g);
	return (-1);
}

//
///////////////////////////////////////////////////////////////////
static int is_not_digit(char c)
{
	if (c < '0' || c > '9')
		return (1);
	return (0);
}

static void check_digits(int ac, char **av, t_global *g)
{
	int i ;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (is_not_digit(av[i][j]))
				print_error_and_exit(g);
			j++;
		}
		i++;
	}
}

static int *fill_tab(int *tab, int ac, char **av, t_global *g)
{
	int i;
	int j;
	int new_number;

	i = 1;
	while (i < ac)
	{
		new_number = ft_atoi(av[i], g);
		j = 1;
		while (j < i)
		{
			if (tab[j] == new_number)
				print_error_and_exit(g);
			j++;
		}
		tab[i] = new_number;
		i++;
	}
	return (tab);
}


///////////////////////////////////////////////////////////////////////////////////////////////////

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
	if (!(g->tab_b))
		return (0);
	tmp = malloc(sizeof(int *) * g->tab_a_size + 1);
	if (!(tmp))
		return (0);
	tmp[0] = g->tab_b[0];
	i = 0;
	j = 1;
	while (i < g->tab_a_size)
	{
		tmp[j] = g->tab_a[i];
		j++;
		i++;
	}
	g->tab_a_size++;
	free(g->tab_a);
	g->tab_a = tmp;

	/////////////////////////////////////////

	free(tmp);
	tmp = malloc(sizeof(int *) * g->tab_b_size - 1);
	if (!(tmp))
		return (0);
	tmp[0] = g->tab_b[1];
	i = 1;
	j = 1;
	while (i < g->tab_b_size)
	{
		tmp[j] = g->tab_a[i];
		j++;
		i++;
	}
	g->tab_a_size++;
	free(g->tab_a);
	g->tab_a = tmp;

	return (1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////


t_global *init_struct(t_global *g, int ac)
{
	if (ac < 2)
		print_error_and_exit(g);
	g = NULL;
	g = malloc(sizeof(t_global));
	if (!g)
		print_error_and_exit(g);
	g->tab_a = malloc(sizeof(int) * ac);
	if (!g->tab_a)
		print_error_and_exit(g);
	g->tab_b = NULL;
	g->tab_a_size = ac;
	g->tab_b_size = 0;
	return (g);
}


void xx(t_global *g)
{
	int i = 0;
	while (i < g->tab_a_size)
	{
		printf("%d\n", g->tab_a[i++]);
	}

	printf("%s\n", "===========================\n");
}

int		main(int ac, char **av)
{
	t_global *g;

	g = init_struct(g, ac);
	xx(g);
	g->tab_a = fill_tab(g->tab_a, ac, av, g);

	xx(g);
	/*pa(g);*/
	/*sa(g->tab_a);*/
	/*xx(g);*/
	free_everything(g);

}

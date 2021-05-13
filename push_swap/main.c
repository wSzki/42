/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:38:31 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/13 14:56:53 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


typedef struct s_g
{
	int *tab_a;
	int *tab_b;
	int tab_a_size;
	int tab_b_size;
}				t_g;


typedef struct s_list
{
	t_g *g;
}				t_list;



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

int			ft_atoi(const char *str)
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
	return (-1);
}

//
//
//
///////////////////////////////////////////////////////////////////
//
static void	print_error_and_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

static int is_not_digit(char c)
{
	if (c < '0' || c > '9')
		return (1);
	return (0);
}

static void check_digits(int ac, char **av)
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
				print_error_and_exit();
			j++;
		}
		i++;
	}
}

static int *fill_tab(int *tab, int ac, char **av)
{
	int i;
	int j;
	int new_number;

	i = 1;
	while (i < ac)
	{
		new_number = ft_atoi(av[i]);
		j = 1;
		while (j < i)
		{
			if (tab[j] == new_number)
				print_error_and_exit();
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


int *ft_int_realloc_a(t_g *g, int action)
{
	if (!(tmp))
		return (0);





}


int pa(t_g *g)
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




int		main(int ac, char **av)
{
	t_g *g;

	g = malloc(sizeof(t_g));
	if (!g)
		return (0);
	g->tab_a_size = ac;
	g->tab_a = NULL;
	g->tab_b = NULL;
	if (ac < 2)
		print_error_and_exit();
	check_digits(ac, av);
	// TODO  Check overflow

	g->tab_a = malloc(sizeof(int) * ac - 1);
	if (!g->tab_a || !g->tab_b)
		return (-1);
	g->tab_a = fill_tab(g->tab_a, ac, av);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:38:31 by wszurkow          #+#    #+#             */
/*   Updated: 2021/05/17 20:08:58 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pushswap.h"


///////////////////////////////////////////////////////////////////////////////////////////////////

void	print_all(t_global *g)
{
	int i;

	i = 0;
	printf("%s\n", "=====================");
	printf("%s\n", "[ TABLE A ]");
	printf("%s\n", "---------------------");
	if (g->a->size)
	{

		printf("Size : %d\n", *g->a->size);
		printf("%s\n", "---------------------");
		while (i < *g->a->size)
		{
			printf("%d\n", g->a->data[i]);
			i++;
		}
	}
	else
		printf("%s\n", "TABLE A EMPTY");
	printf("%s\n", "=====================");

	i = 0;
	printf("%s\n", "=====================");
	printf("%s\n", "[ TABLE B ]");
	printf("%s\n", "---------------------");
	if (g->b->size)
	{
		printf("Size : %d\n", *g->b->size);
		printf("%s\n", "---------------------");
		while (i < *g->b->size)
		{
			printf("%d\n", g->b->data[i]);
			i++;
		}
	}
	else
		printf("%s\n", "TABLE B EMPTY");
	printf("%s\n", "=====================");
}

///////////////////////////////////////////////////////////////////////////////////////////////////

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

static t_global *init_tab_data(t_global *g, int ac)
{
	g->a->data = malloc(sizeof(int) * ac - 1);
	if (!g->a->data)
		free_everything_and_exit(g);
	g->a->size = malloc(sizeof(int));
	if (!g->a->size)
		free_everything_and_exit(g);
	*g->a->size = ac - 1;
	g->b->data = malloc(sizeof(int));
	if (!g->b->data)
		free_everything_and_exit(g);
	g->b->size = malloc(sizeof(int));
	if (!g->b->size)
		free_everything_and_exit(g);
	*g->b->size = 0;
	return (g);
}

static t_global *init_struct(t_global *g, int ac)
{
	g = init_g(g);
	g = init_tab_a_and_b(g);
	g = init_tab_data(g, ac);
	return (g);
}

int		main(int ac, char **av)
{
	t_global *g;

	g = NULL;
	if (ac < 2)
		print_error_and_exit();
	if (ac == 2)
		return (0);
	g = init_struct(g, ac);
	fill_tab_a(g, ac, av);
	sort_main(g);
	/*print_all(g);*/
	free_everything(g);
	return (0);
}

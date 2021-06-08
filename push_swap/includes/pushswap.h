/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:14:13 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/08 17:45:26 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define R 0
#define RR 1
#define A g->a
#define B g->b
#define A_ID 0
#define B_ID 1
#define R_ID 2
#define A_DATA g->a->data
#define B_DATA g->b->data
#define A_SIZE g->a->size
#define B_SIZE g->b->size
#define ABS(x)  ( ( (x) < 0) ? -(x) : (x) )
typedef struct s_tab
{
	int id;
	int *data;
	int size;
}			t_tab;

typedef struct s_global
{
	int *tab_a;
	int *tab_b;

	int tab_a_size;
	int tab_b_size;

	t_tab *a;
	t_tab *b;

	char **av;
}				t_global;


void		print_error_and_exit(void);
void		free_everything_and_exit(t_global *g);
void		free_everything(t_global *g);

int			ps_atoi(const char *str, t_global *g);
void	ps_prepend(t_global *g, t_tab *tab, int value);
void	ps_append(t_global *g, t_tab *tab, int value);
void	ps_delete_first(t_global *g, t_tab *tab);

void	fill_tab_a(t_global *g, int ac, char **av);
void scroll_to(t_global *g, t_tab *tab, int target_value);

int	find_smallest(t_tab *tab);
int	find_largest(t_tab *tab);
void find_median(t_tab *tab, int *median, int min_value, int max_value);
void	quarter_sort(t_global *g, long first_median, long second_median, int offset);
void check_simple_cases(t_global *g);
void sort(t_global *g);
void sort_three(t_global *g, int *tab);
void push_smallest_or_largest(t_global *g);
//
void	sx(t_global *g, int id);
void	px(t_global *g, int id);
void	rx(t_global *g, int id);
void	rrx(t_global *g, int id);

#endif

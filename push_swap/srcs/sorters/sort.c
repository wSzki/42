/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:48:51 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/09 16:02:04 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_all(t_global *g);

static void	normalise_list(t_global *g)
{
	while (A_SIZE % 4 != 0)
	{
		scroll_to(g, A, find_largest(A));
		px(g, B_ID);
	}
}

void	sort(t_global *g, int lowest_sorted)
{
	int		median_a;
	int		median_b;
	int		median_c;
	long	minimum;

	check_simple_cases(g);
	normalise_list(g);
	find_median(A, &median_a, find_smallest(A), find_largest(A));
	find_median(A, &median_b, find_smallest(A), median_a);
	find_median(A, &median_c, median_a, find_largest(A));
	minimum = (long)find_smallest(A) - 1;
	lowest_sorted = quarter_sort(g, median_c, find_largest(A), NO_VALUE);
	lowest_sorted = quarter_sort(g, median_a, median_c, lowest_sorted);
	lowest_sorted = quarter_sort(g, median_b, median_a, lowest_sorted);
	lowest_sorted = quarter_sort(g, minimum, median_b, lowest_sorted);
	scroll_to(g, A, find_smallest(A));
}

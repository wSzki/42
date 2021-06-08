/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:48:51 by wszurkow          #+#    #+#             */
/*   Updated: 2021/06/08 18:01:41 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_all(t_global *g);

static void	normalise_list(t_global *g, int *offset)
{
	while (A_SIZE % 4 != 0)
	{
		scroll_to(g, A, find_smallest(A));
		px(g, B_ID);
		*offset += 1;
	}
}

void	sort(t_global *g)
{
	int offset;
	int median_a;
	int median_b;
	int median_c;
	long minimum;

	check_simple_cases(g);
	offset = 0;
	normalise_list(g, &offset);
	find_median(A, &median_a, find_smallest(A), find_largest(A));
	find_median(A, &median_b, find_smallest(A), median_a);
	find_median(A, &median_c, median_a, find_largest(A));
	if (B_SIZE)
		minimum = find_largest(B);
	else
		minimum = (long)find_smallest(A) - 1;
	quarter_sort(g, minimum, median_b, 0);
	quarter_sort(g, median_c, find_largest(A), offset);
	quarter_sort(g, median_a, median_c, offset);
	quarter_sort(g, median_b, median_a, offset);
	scroll_to(g, A, find_smallest(A));
}

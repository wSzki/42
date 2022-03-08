/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_basic_test_wrong_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:42:53 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 21:28:42 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	basic_test_wrong_pointer(void)
{
	char	*str1;
	char	*str2;
	char	*res;

	str1 = "♡";
	str2 = (char *)1;
	res = ft_strjoin_test_func(str1, str2);
	if (ft_strcmp(res, "♡") != 0)
		return (-1);
	return (0);
}

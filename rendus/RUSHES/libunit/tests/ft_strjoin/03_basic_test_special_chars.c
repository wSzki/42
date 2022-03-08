/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_basic_test_special_chars.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:42:53 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 12:49:50 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	basic_test_special_chars(void)
{
	char	*str1;
	char	*str2;
	char	*res;

	str1 = "\t\n\r\v";
	str2 = "\t\n\r\v";
	res = ft_strjoin_test_func(str1, str2);
	if (ft_strcmp(res, "\t\n\r\v\t\n\r\v") != 0)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:19:16 by ggiquiau          #+#    #+#             */
/*   Updated: 2022/01/09 12:48:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	basic_test_hello_world(void)
{
	char	*str1;
	char	*str2;
	char	*res;

	str1 = "hello ";
	str2 = "world";
	res = ft_strjoin_test_func(str1, str2);
	if (ft_strcmp(res, "hello world") != 0)
		return (-1);
	return (0);
}

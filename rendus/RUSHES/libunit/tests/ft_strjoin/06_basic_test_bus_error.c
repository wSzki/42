/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_basic_test_bus_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:41:19 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 21:28:23 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

/* Enable Alignment Checking on x86_64 */
/* From Wikipedia page on bus errors */

int	basic_test_bus_error(void)
{
	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:36:44 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/13 20:37:35 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

t_curse *get_curse(void)
{
	static t_curse curse;
	return (&curse);
}

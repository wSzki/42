/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:15:51 by wszurkow          #+#    #+#             */
/*   Updated: 2021/03/20 21:16:20 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	append_error(t_global *g, char *id, char *message)
{
	char *res;

	res = ft_strjoin(id, message);
	g->error = dual_realloc(g->error, res);
	free(res);
	res = NULL;
}


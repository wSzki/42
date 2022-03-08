/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:08:39 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/09 11:02:45 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*child;

	child = (t_list *)malloc(sizeof(*child));
	if (child == NULL)
		return (NULL);
	child->content = content;
	child->next = NULL;
	return (child);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_whitespaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:39:45 by wszurkow          #+#    #+#             */
/*   Updated: 2021/09/14 01:39:53 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char *ignore_whitespaces(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (
				str[i] == ' ' ||
				str[i] == '\t' ||
				str[i] == '\n' ||
				str[i] == '\r' ||
				str[i] == '\v'))
		i++;
	return (&str[i]);
}


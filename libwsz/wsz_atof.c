/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wsz_atof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:15:03 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/16 18:24:11 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	wsz_ignore_whitespaces(char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		*i += 1;
}

static float	wsz_atof_process_sign(char *str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			*i += 1;
			return (-1);
		}
		*i += 1;
	}
	return (1);
}

static float	wsz_atof_process_whole(char *str, int *i)
{
	int	atof;

	atof = 0;
	while (str[*i] == '0')
		*i += 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		atof = atof * 10 + str[*i] - 48;
		*i += 1;
	}
	return ((float)atof);
}

static float	wsz_atof_process_decimal(char *str, int *i, float atof)
{
	float	decimal_multiplier;

	decimal_multiplier = 1;
	if (str[*i] == '.')
	{
		*i += 1;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			decimal_multiplier *= 0.1;
			atof = atof + (decimal_multiplier * (str[*i] - 48));
			*i += 1;
		}
	}
	return (atof);
}

float	wsz_atof(char *str)
{
	int		i;
	float	sign;
	float	atof;

	i = 0;
	sign = 1;
	atof = 0;
	wsz_ignore_whitespaces(str, &i);
	sign = wsz_atof_process_sign(str, &i);
	atof = wsz_atof_process_whole(str, &i);
	atof = wsz_atof_process_decimal(str, &i, atof);
	return (sign * atof);
}

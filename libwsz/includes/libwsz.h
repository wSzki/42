/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libwsz.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:22:07 by wszurkow          #+#    #+#             */
/*   Updated: 2021/08/17 02:53:53 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBWSZ_H
# define LIBWSZ_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


float	wsz_atof(char *str);
int		wsz_atoi_overflow(const char *str, void *g, void (*free_and_exit)(void *));

size_t	wsz_count_lines(void **tab);
int		wsz_count_numbers(int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfindT.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:10:21 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/15 18:02:34 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_H__
# define __EASYFIND_H__

# include <iostream>
# include <vector> // std::vector
# include <algorithm> // std::find
# include <exception>

template <typename T>
int easyfind(T t, int i)
{
	typename T::iterator iter = std::find(t.begin(), t.end(), i); // returns an iterator address
	if (iter == t.end()) // t.end() points to the element after last element in container
		throw std::exception();
	return (*iter);
}

#endif

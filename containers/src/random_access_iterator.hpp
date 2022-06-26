/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterators.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:43:37 by wszurkow          #+#    #+#             */
/*   Updated: 2022/06/16 16:44:05 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  RANDOM_ACCESS_ITERATOR_HPP
#define  RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template <typename T>
		class random_access_iterator
		{
			public :
		typedef T* pointer;


				random_access_iterator() : _ptr(NULL) {};


			protected:
				pointer _ptr;

			private :
		};

};
#endif

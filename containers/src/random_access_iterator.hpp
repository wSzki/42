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

				typedef random_access_iterator<int> iter;

				random_access_iterator   ():       _ptr(NULL) {};
				random_access_iterator   (T* ptr): _ptr(ptr)  {};
				~random_access_iterator  ()                   {};


			protected:
				T* _ptr;

			private :
		};

};
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:41:53 by wszurkow          #+#    #+#             */
/*   Updated: 2022/06/10 16:01:45 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft
{

	/* ====================================================== */
	/* --------------------- ITERATORS ---------------------- */
	/* ====================================================== */
	// https://en.cppreference.com/w/cpp/iterator/iterator_tags

	// Iterator tags, used to define which type of iterator is used.
	// Not sure how to use it, a method (not sure which one)
	// returns one of the following empty structs

	struct input_iterator_tag{ };
	struct forward_iterator_tag : public input_iterator_tag{ };
	struct bidirectional_iterator_tag : public forward_iterator_tag{ };
	struct random_access_iterator_tag : public bidirectional_iterator_tag{ };

	// https://cplusplus.com/reference/iterator/iterator/
	// This is a base class template that can be used to derive iterator classes from it.
	// It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
	//
	// This base class only provides some member types, which in fact are not required to be present in any iterator type
	// (iterator types have no specific member requirements), but they might be useful,
	// since they define the members needed for the default iterator_traits class template to generate
	// the appropriate instantiation automatically (and such instantiation is required to be valid for all iterator types).

	template <
		class Category,
		class T,
		class Distance  = ptrdiff_t,
		class Pointer   = T*,
		class Reference = T& >
		struct iterator {
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
		};

	/* ====================================================== */
	/* ------------------ ITERATOR_TRAITS ------------------- */
	/* ====================================================== */
	// https://code.woboq.org/linux/include/c++/8.2.1/bits/stl_iterator_base_types.h.html
	// https://devdocs.io/cpp/iterator/iterator_traits

	template<typename T>
		struct iterator_traits
		{
			typedef typename T::difference_type   difference_type;
			typedef typename T::value_type        value_type;
			typedef typename T::pointer           pointer;
			typedef typename T::reference         reference;
			typedef typename T::iterator_category iterator_category;
		};

	// Pointers specialization
	template<typename T>
		struct iterator_traits<T*>
		{
			typedef T                          value_type;
			typedef ptrdiff_t                  difference_type;
			typedef T*                         pointer;
			typedef T&                         reference;
			typedef random_access_iterator_tag iterator_category;
		};

	// Const pointers specialization
	template<typename T>
		struct iterator_traits<const T*>
		{
			typedef T                          value_type;
			typedef ptrdiff_t                  difference_type;
			typedef const                      T* pointer;
			typedef const                      T& reference;
			typedef random_access_iterator_tag iterator_category;
		};
}
#endif

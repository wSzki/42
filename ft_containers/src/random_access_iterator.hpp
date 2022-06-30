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
#include <cstddef>

namespace ft
{
	template <typename T>
		class random_access_iterator
		{
			public:
				// #################
				// ORIGINAL TYPEDEFS
				// #################

				//typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
				//typedef typename ft::iterator_traits<T>::value_type        value_type;
				//typedef typename ft::iterator_traits<T>::difference_type   difference_type;
				//typedef typename ft::iterator_traits<T>::pointer           pointer;
				//typedef typename ft::iterator_traits<T>::reference         reference;

				// TODO is above what is supposed to be ?
				// TODO is below useful?

				typedef T              value_type;
				typedef T*             pointer;
				typedef T&             reference;
				typedef std::ptrdiff_t difference_type;
				typedef const T*       const_pointer;
				typedef const T&       const_reference;

				typedef std::random_access_iterator_tag iterator_category;

			protected:
				pointer _ptr;

			public:
				// ###################
				// ADDITIONAL TYPEDEFS
				// ###################
				typedef random_access_iterator RAI;

				// ######################
				// CONSTRUCTOR DESTRUCTOR
				// ######################
				random_access_iterator   ()               : _ptr(NULL)     {void();}; // Default constructor
				random_access_iterator   (T* ptr)         : _ptr(ptr)      {void();}; // Constructor
				random_access_iterator   (RAI const &lhs) : _ptr(lhs._ptr) {void();}; // Shallow copy
				~random_access_iterator  ()                                {void();}; // Destructor

				// #########
				// OVERLOADS
				// #########
				random_access_iterator   &operator = (RAI const &lhs) { if (this != &lhs) _ptr = lhs._ptr; return (*this);}

				//// Pointers
				reference operator *  (void)       {return (*_ptr);}; // TODO why return reference and not pointer
				pointer   operator -> (void)       {return ( _ptr);};
				reference operator *  (void) const {return (*_ptr);};
				pointer   operator -> (void) const {return ( _ptr);};

				//// Comparaison
				bool  operator == (RAI const &rhs) {return (_ptr == rhs._ptr);};
				bool  operator != (RAI const &rhs) {return (_ptr != rhs._ptr);};
				bool  operator <  (RAI const &rhs) {return (_ptr <  rhs._ptr);};
				bool  operator >  (RAI const &rhs) {return (_ptr >  rhs._ptr);};
				bool  operator <= (RAI const &rhs) {return (_ptr <= rhs._ptr);};
				bool  operator >= (RAI const &rhs) {return (_ptr >= rhs._ptr);};

				//// Increment, decrement
				RAI   operator ++ (int              ) {_ptr++;    return (*this);}; // TODO post increment what is it - triggered by (int)?
				RAI & operator ++ (void             ) {_ptr++;    return (*this);}; // TODO does it work without creating deep copy? {random_access_iterator}
				RAI   operator -- (int              ) {_ptr++;    return (*this);};
				RAI & operator -- (void             ) {_ptr++;    return (*this);};
				RAI   operator +  (difference_type n) {           return (RAI(_ptr + n));}; // TODO ok without dep copy? (RAI<T>(ptr + n)) TODO ok without const? why const?
				RAI   operator -  (difference_type n) {           return (RAI(_ptr - n));}; // TODO ok without dep copy? (RAI<T>(ptr + n)) TODO ok without const? why const?
				RAI & operator += (difference_type n) {_ptr += n; return (*this);};
				RAI & operator -= (difference_type n) {_ptr -= n; return (*this);};

				//// Misc
				reference       operator [] (difference_type n) {return *(_ptr + n);}; // TODO why ptrdiff?
				difference_type operator -  (RAI const &rhs)   {return (_ptr - rhs._ptr);};
		};
};
#endif

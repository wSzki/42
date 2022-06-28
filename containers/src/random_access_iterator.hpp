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
			public :

				// #################
				// ORIGINAL TYPEDEFS
				// #################
				typedef std::ptrdiff_t difference_type;
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef const T* const_pointer;
				typedef const T& const_reference;
				typedef std::random_access_iterator_tag iterator_category;

				// ###################
				// ADDITIONAL TYPEDEFS
				// ###################
				typedef random_access_iterator RAI;

				// ######################
				// CONSTRUCTOR DESTRUCTOR
				// ######################
				random_access_iterator   ()               : _ptr(NULL)     {}; // Default constructor
				random_access_iterator   (T* ptr)         : _ptr(ptr)      {}; // Constructor
				random_access_iterator   (RAI const &lhs) : _ptr(lhs._ptr) {}; // Shallow copy
				~random_access_iterator  ()                                {}; // Destructor

				// #########
				// OVERLOADS
				// #########
				random_access_iterator   &operator = (RAI const &lhs) { if (this != &lhs) _ptr = lhs._ptr; return (*this);}

				//// Pointers
				T& operator       *  ()       {return (*_ptr);}; // TODO why return reference and not pointer
				T* operator       -> ()       {return ( _ptr);};
				const T& operator *  () const {return (*_ptr);};
				const T* operator -> () const {return ( _ptr);};

				//// Comparaison
				bool  operator == (RAI const &rhs)   {return (_ptr == rhs._ptr);};
				bool  operator != (RAI const &rhs)   {return (_ptr != rhs._ptr);};
				bool  operator <  (RAI const &rhs)   {return (_ptr <  rhs._ptr);};
				bool  operator >  (RAI const &rhs)   {return (_ptr >  rhs._ptr);};
				bool  operator <= (RAI const &rhs)   {return (_ptr <= rhs._ptr);};
				bool  operator >= (RAI const &rhs)   {return (_ptr >= rhs._ptr);};

				//// Increment, decrement
				RAI   operator ++ (int )             {_ptr++;    return (*this);}; // TODO post increment what is it - triggered by (int)?
				RAI & operator ++ (void)             {_ptr++;    return (*this);}; // TODO does it work without creating deep copy? {random_access_iterator}
				RAI   operator -- (int )             {_ptr++;    return (*this);};
				RAI & operator -- (void)             {_ptr++;    return (*this);};
				RAI   operator +  (std::ptrdiff_t n) {_ptr += n; return (*this);}; // TODO ok without dep copy? (RAI<T>(ptr + n)) TODO ok without const? why const?
				RAI   operator -  (std::ptrdiff_t n) {_ptr -= n; return (*this);}; // TODO ok without dep copy? (RAI<T>(ptr + n)) TODO ok without const? why const?
				RAI & operator += (std::ptrdiff_t n) {_ptr += n; return (*this);};
				RAI & operator -= (std::ptrdiff_t n) {_ptr -= n; return (*this);};

				//// Misc
				T   &          operator [] (std::ptrdiff_t n) {return *(_ptr + n);}; // TODO why ptrdiff?
				std::ptrdiff_t operator -  (RAI const &rhs)   {return (_ptr - rhs._ptr);};




			protected:
				T* _ptr;

			private :
		};

};
#endif

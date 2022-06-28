/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:23:13 by wszurkow          #+#    #+#             */
/*   Updated: 2022/06/14 15:13:28 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cctype>
#include <cstddef>
#include <iostream>
#include <iterator>

#include "random_access_iterator.hpp"

/*
 ** https://devdocs.io/cpp/container/vector
 ** https://m.cplusplus.com/reference/vector/vector/?kw=vector
 */

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
		class vector {

			public:


				// TYPEDEFS
				typedef T                                            value_type;
				typedef Allocator                                    allocator_type;

				typedef ft::random_access_iterator<value_type>       iterator;
				typedef ft::random_access_iterator<value_type> const const_iterator;



				typedef std::reverse_iterator     <iterator>         reverse_iterator;
				typedef std::reverse_iterator     <const_iterator>   const_reverse_iterator;

				// ALLOCATOR DATA
				typedef typename allocator_type::size_type       size_type;
				typedef typename allocator_type::difference_type difference_type;

				typedef typename allocator_type::pointer         pointer;
				typedef typename allocator_type::const_pointer   const_pointer;

				typedef typename allocator_type::reference       reference;
				typedef typename allocator_type::const_reference const_reference;

				// MEMBER FUNCTIONS





				//vector(const allocator_type &alloc = allocator_type()) :
				//_array(NULL),
				//_alloc(alloc),
				//_size(0),
				//_capacity(0)
				//{
				//std::cout << "Constructor 1 called" << std::endl;
				//}


				//	DEFAULT CONSTRUCTOR
				vector (void) :
					//vector (void):
					_array(NULL),
					_alloc(std::allocator<T>()),
					_size(0),
					_capacity(0)
			{
				std::cout << "Default constructor called" << std::endl;
			}

				// CONSTRUCTOR
				vector (size_t n, T const &val) : // T const &val is a function style cast, == const value_type &val = value_type()
					_array(NULL),
					_alloc(std::allocator<T>()),
					_size(n),
					_capacity(n)
			{
				_array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_array + i, val);
				std::cout << "Constructor called" << std::endl;
			}

				// DESTRUCTOR
				~vector()
				{
					if (_capacity > 0)
						_alloc.deallocate(_array, _capacity);
					_capacity = 0;
				}




				// ITERATORS
				iterator               begin        ()       { return iterator(_array); };
				iterator               end          ()       { return iterator(_array + _size); };

				reverse_iterator       rbegin       ()       { return reverse_iterator(end());            };
				reverse_iterator       rend         ()       { return reverse_iterator(begin());          };
				const_iterator         begin        () const { return iterator(Allocator::begin(), this); };
				const_iterator         end          () const { return iterator(Allocator::end(),   this); };
				const_reverse_iterator rbegin       () const { return const_reverse_iterator(end());      };
				const_reverse_iterator rend         () const { return const_reverse_iterator(begin());    };

				// CAPACITY
				size_type              size       () const {return (_size);};
				size_type              capacity   () const {return (_capacity);};
				size_type              max_size   () const {return (_alloc.max_size());};
				bool                   empty      () const {return (_size == 0);};

				void                   resize     (size_type n, value_type val = value_type());
				void                   reserve    (size_type n);

				// ELEMENT ACCESS
				reference              operator[] (size_type n);
				reference              at         (size_type n);
				reference              front      ();
				reference              back       ();
				const_reference        operator[] (size_type n) const;
				const_reference        at         (size_type n) const;
				const_reference        front      ()            const;
				const_reference        back       ()            const;

				// MODIFIERS
				void           push_back          (const value_type& val);
				void           pop_back           ();
				iterator       erase              (iterator position);
				iterator       erase              (iterator first, iterator last);
				void           swap               (vector&  x);
				void           clear              ();
				// -- Insert
				iterator insert (iterator position, const value_type& val);              // Single element
				void     insert (iterator position, size_type n, const value_type& val); // Fill elements
				template <class InputIterator>                                           // Range
					void insert (iterator position, InputIterator first, InputIterator last);
				// -- Assign
				void assign     (size_type n, const value_type& val); // Fill elements
				template <class InputIterator>                    // Range of elements
					void assign (InputIterator first, InputIterator last);

				// ALLOCATOR
				allocator_type get_allocator() const;


				// NON MEMBER FUNCTION OVERLOADS
				// TODO ? template <class value_type, class Alloc>
				// TODO ?	void swap (vector<value_type, Alloc>& x, vector<value_type ,Alloc>& y);

				// TEMPLATE SPECIALIZATIONS
				//TODO ? vector<bool> Vector of bool (class template specialization )


			protected:
				T*             _array;
				allocator_type _alloc;
				size_type      _size;
				size_type      _capacity;


			private:


		};

}
#endif


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
				typedef ft::random_access_iterator<value_type const> const_iterator;



				typedef std::reverse_iterator     <iterator>         reverse_iterator;
				typedef std::reverse_iterator     <const_iterator>   const_reverse_iterator;

				// ALLOCATOR DATA
				typedef typename allocator_type::size_type       size_type;
				typedef typename allocator_type::difference_type difference_type;

				typedef typename allocator_type::pointer         pointer;
				typedef typename allocator_type::const_pointer   const_pointer;

				typedef typename allocator_type::reference       reference;
				typedef typename allocator_type::const_reference const_reference;


			protected:
				T*             _array;
				allocator_type _alloc;
				size_type      _size;
				size_type      _capacity;

				void realloc (size_type n)
				{
					pointer   _array_new = _alloc.allocate(n);
					size_type _size_new  = -1;

					while (++_size_new < _size)
						_alloc.construct(_array_new + _size_new, _array[_size_new]);
					this->~vector();
					_array    = _array_new;
					_size     = _size_new;
					_capacity = n;

				}


			public :
				// MEMBER FUNCTIONS





				//vector(const allocator_type &alloc = allocator_type()) :
				//_array(NULL),
				//_alloc(alloc),
				//_size(0),
				//_capacity(0)
				//{
				//std::cout << "Constructor 1 called" << std::endl;
				//}

				//explicit vector (const allocator_type &alloc = allocator_type()) : _alloc(alloc), _array(NULL), _size(0), _capacity(0) {}

				vector (const vector &x) : _array(NULL), _alloc(x._alloc),_size(x._size), _capacity(x._size)
			{
				_array = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_array + i, x._array[i]);
			}



				//	DEFAULT CONSTRUCTOR
				vector (void) :
					//vector (void):
					_array(NULL),
					_alloc(std::allocator<T>()),
					_size(0),
					_capacity(0)
			{
				//std::cout << "Default constructor called" << std::endl;
			}

				// CONSTRUCTOR
				vector (size_t n, T const &val = value_type(), const allocator_type &alloc = allocator_type() ) : // T const &val is a function style cast, == const value_type &val = value_type()
					_array(NULL),
					_alloc(alloc),
					_size(n),
					_capacity(n)
			{
				_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_array + i, val);
				//std::cout << "Constructor called" << std::endl;
			}

				// DESTRUCTOR
				~vector()
				{
					clear();
					if (_capacity > 0)
						_alloc.deallocate(_array, _capacity);
					_capacity = 0;
					//std::cout << "Destructor called" << std::endl;
				}

				// ITERATORS
				iterator               begin        (void)       { return iterator(_array);         };
				iterator               end          (void)       { return iterator(_array + _size); };
				const_iterator         begin        (void) const { return const_iterator(_array);         };
				const_iterator         end          (void) const { return const_iterator(_array + _size); };

				//reverse_iterator       rbegin       (void)       { return reverse_iterator(end());            };
				//reverse_iterator       rend         (void)       { return reverse_iterator(begin());          };
				//const_reverse_iterator rbegin       (void) const { return const_reverse_iterator(end());      };
				//const_reverse_iterator rend         (void) const { return const_reverse_iterator(begin());    };

				// CAPACITY
				size_type              size       (void) const { return (_size);                       };
				size_type              capacity   (void) const { return (_capacity);                   };
				size_type              max_size   (void) const { return (_alloc.max_size());           };
				bool                   empty      (void) const { return (_size <= 0);                  };

				void                   pop_back   (void)       { _alloc.destroy(_array + (_size - 1)); _size ? _size-- : _size = 0; };
				void                   clear      (void)       { while (empty() == false) pop_back();                               };

				void                   resize     (size_type n, value_type val = value_type())
				{
					if (_size >= n)
						while (_size > n)
							pop_back();
					else
					{
						if (n > (_capacity))
						{
							T* tmp  = _array;

							size_type old = _capacity;


							_alloc.allocate(n);
							size_type i = 0;
							size_type counter = 0;
							for (; i < size(); i++, counter++)
								_alloc.construct(_array + counter, tmp[counter]);
							_alloc.deallocate(tmp, old);

						}
						//(n > (_capacity * 2)) ? realloc(n) : realloc(_capacity * 2);
						while (_size > n)
							push_back(val);
					}

				}


				void reserve(size_type n)
				{
					if (n > max_size())
						throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
					if (n > _capacity)
						realloc(n);
				}


				//void                   reserve    (size_type n);

				// ELEMENT ACCESS
				//reference              operator[] (size_type n);
				reference              at         (size_type n)       { if (n >= _size) throw std::out_of_range("Error: at:: out of range"); return *(_array + n);  };
				const_reference              at         (size_type n) const       { if (n >= _size) throw std::out_of_range("Error: at:: out of range"); return *(_array + n);  };

				reference       operator[] (size_type n)       { return *(_array + n);};
				const_reference operator[] (size_type n) const { return *(_array + n);};

				reference              front      (void)       { return (*(_array));             };
				reference              back       (void)       { return (*(_array + _size - 1)); };
				const_reference        front      (void) const { return (*(_array));             };
				const_reference        back       (void) const { return (*(_array + _size - 1)); };
				//const_reference        operator[] (size_type n) const;
				//const_reference        at         (size_type n) const;

				// MODIFIERS
				void                   push_back  (const value_type& val);
				//iterator               erase      (iterator position);
				//iterator               erase      (iterator first, iterator last);
				//void                   swap       (vector&  x);

				// -- Insert
				iterator insert (iterator position, const value_type& val);              // Single element
				void     insert (iterator position, size_type n, const value_type& val); // Fill elements
				template <class InputIterator>                                           // Range
					void insert (iterator position, InputIterator first, InputIterator last);
				// -- Assign
				void assign     (size_type n, const value_type& val) // Fill elements
					;
				//{
				//// {
				//if (n > _capacity)
				//{
				//this->~vector();
				//this->_size = 0;
				//this->_capacity = n;
				//this->_array = _alloc.allocate(_capacity);
				//while (_size < n)
				//_alloc.construct(_array + _size++, val);
				//}
				//else
				//{
				//clear();
				//while (_size < n)
				//_alloc.construct(_array + _size++, val);
				//}
				//}



				template <class InputIterator>                    // Range of elements
					void assign (InputIterator first, InputIterator last);

				// ALLOCATOR
				allocator_type get_allocator() const;

				// NON MEMBER FUNCTION OVERLOADS
				// TODO ? template <class value_type, class Alloc>
				// TODO ?	void swap (vector<value_type, Alloc>& x, vector<value_type ,Alloc>& y);

				// TEMPLATE SPECIALIZATIONS
				//TODO ? vector<bool> Vector of bool (class template specialization )




			private:


		};

		}
#endif


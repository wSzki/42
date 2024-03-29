/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:48:47 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/20 19:10:28 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <functional> //std::less
#include <utility> //std::pair
#include <memory> //std::allocator

//#include "iterator.hpp"
#include "utils/tree.hpp"
#include "utils/pair.hpp"
#include "utils/bidirectional_iterator.hpp"

// TODO ? https://en.cppreference.com/w/cpp/container/map/value_compare

namespace ft
{
	/* ====================================================================== */
	/* -------------------------------- MAP --------------------------------- */
	/* ====================================================================== */
	template <
		class Key,                                             \
		class T,                                               \
		class Compare = std::less<Key>,                        \
		class Alloc = std::allocator<ft::pair<const Key, T> > \
		>
		class map {
			public :
				/* -------------------- STD DEFINITIIONS -------------------- */
				typedef          Key                                                  key_type;
				typedef          T                                                    mapped_type;
				typedef          ft::pair<key_type, mapped_type>               const value_type; // TODO constify?

				typedef          Compare                                              key_compare;

				typedef          Alloc                                                allocator_type;
				typedef typename Alloc::reference                                     reference;
				typedef typename Alloc::pointer                                       pointer;
				typedef typename Alloc::const_reference                               const_reference;
				typedef typename Alloc::const_pointer                                 const_pointer;

				typedef          std::ptrdiff_t                                       difference_type;
				typedef          std::size_t                                          size_type;

				/* ...................................... */
				/* ............... CUSTOM ............... */
				/* ...................................... */
				typedef Key                  key_t;
				typedef T                    data_t;

				typedef node      <Key, T>   node_t;
				typedef node_t * nodePtr;
				typedef tree      <Key, T>   tree_t;
				typedef ft::pair  <Key, T>   pair_t; // == std::pair<const key_type, mapped_type>

				typedef bidirectional_iterator <node_t>           iterator;
				typedef bidirectional_iterator <const node_t>     const_iterator;
				//typedef ft::reverse_iterator   <iterator>       reverse_iterator;
				//typedef ft::reverse_iterator   <const_iterator> const_reverse_iterator;


			protected :
				key_compare    _comp;
				allocator_type _alloc;
				tree_t         _tree;


			public:

				/* ========================================================== */
				/* ---------------------- CONSTRUCTOR ----------------------- */
				/* ========================================================== */
				/* ------------------ DEFAULT CONSTRUCTOR ------------------- */
				explicit map ( \
						const key_compare    & comp  = key_compare(),   \
						const allocator_type & alloc = allocator_type() \
						) :
					_comp(comp),
					_alloc(alloc),
					_tree() {};

				/* ------------------- RANGE CONSTRUCTOR -------------------- */
				template <class InputIterator>
					map ( \
							InputIterator first, \
							InputIterator last, \
							const key_compare& comp     = key_compare(), \
							const allocator_type& alloc = allocator_type() \
						) :
						_comp(comp),
						_alloc(alloc),
						_tree() { insert(first, last); };

				/* -------------------- COPY CONSTRUCTOR -------------------- */
				map (const map& to_copy) : _comp(to_copy._comp), _alloc(to_copy._alloc), _tree() {
					insert(to_copy.begin(), to_copy.end());
				}

				/* ----------------------- DESTRUCTOR ----------------------- */
				~map(void){};

				/* ----------------------- OVERLOAD = ----------------------- */
				map& operator =( const map& other ) {
					if (this == &other)
						return (*this);
					_alloc = other._alloc;
					_comp = other._comp;
					if (other.size() > 0)
						insert(other.begin(), other.end());
					return (*this);
				};

				/* ========================================================== */
				/* ----------------------- ITERATORS ------------------------ */
				/* ========================================================== */

				iterator               begin  () { iterator it(_tree.getMin()); return (it); }
				iterator               end    () { iterator it(_tree.getMax()); return (it); }

				// TODO
				//reverse_iterator               rbegin () { return (reverse_iterator(_tree.getMax())); }
				//reverse_iterator       rend   ();

				const_iterator               begin  () const { return (const_iterator(_tree.getMin())); }
				const_iterator               end    () const { return (const_iterator(_tree.getMax())); }

				//TODO
				//const_reverse_iterator rbegin () const;
				//const_reverse_iterator rend   () const;

				/* ========================================================== */
				/* ------------------------ CAPACITY ------------------------ */
				/* ========================================================== */

				//Checks if the container has no elements, i.e. whether begin() == end().
				bool empty() const {return _tree.empty();};

				//Returns the number of elements in the container, i.e. std::distance(begin(), end()).
				size_type size() const {return _tree.size();};

				//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
				size_type max_size() const {return _tree.max_size();};

				/* ========================================================== */
				/* ----------------------- MODIFIERS ------------------------ */
				/* ========================================================== */

				//Erases all elements from the container. After this call, size() returns zero. Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterator remains valid.
				void clear() {_tree.clear(); }

				//Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
				//All iterators and references remain valid. The past-the-end iterator is invalidated.
				void swap( map& m ) {_tree.swap(m._tree);}

				//Returns the function object that compares the keys, which is a copy of this container's constructor argument comp.
				key_compare key_comp() const {return (_comp);}

				//https://en.cppreference.com/w/cpp/container/map/insert
				ft::pair<iterator, bool> insert( const value_type& pair )
				{
					nodePtr tmp_node = _tree.insert(pair.first, pair.second);
					bool success = tmp_node != NULL ? true : false;
					iterator it(tmp_node);
					return (ft::make_pair(it, success));
				}

				iterator insert (iterator position, const value_type& pair)
				{
					(void)position;
					nodePtr node = _tree.find_key(pair.first);
					if (node == _tree.get_node_end())
						node = _tree.insert(pair.first, pair.second);
					iterator it(node);
					return (it);
				}


				template< class InputIt > void insert( InputIt it_pair, InputIt end )
				{
					while (it_pair != end)
					{
						_tree.insert(it_pair->first, it_pair->second);
						it_pair++;
					}
				}

				/* ========================================================== */
				/* -------------------------- TODO -------------------------- */
				/* ========================================================== */

				//Removes specified elements from the container.
				//https://en.cppreference.com/w/cpp/container/map/erase
				iterator erase( iterator pos );
				size_type erase( const Key& key );


				/* ========================================================== */
				/* ----------------------- OBSERVERS ------------------------ */
				/* ========================================================== */

				//Returns a function object that compares objects of type std::map::const value_type (key-value pairs) by using key_comp to compare the first components of the pairs.
				//value_compare value_comp() const;

				/* ========================================================== */
				/* ------------------------- LOOKUP ------------------------- */
				/* ========================================================== */

				//Returns the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container does not allow duplicates.
				size_type count( const Key& key ) const { return _tree.find_key(key) != _tree.get_node_end() ? 1 : 0; }

				//) Finds an element with key equivalent to key.
				iterator       find( const Key& key ) { return iterator(_tree.find_key(key));  }
				const_iterator find( const Key& key ) const { return iterator(_tree.find_key(key));  }

				//Returns a range containing all elements with the given key in the container. The range is defined by two iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
				std::pair<iterator,iterator>             equal_range( const Key& key );
				std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

				// Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
				iterator lower_bound( const Key& key );
				const_iterator lower_bound( const Key& key ) const;

				//Returns an iterator pointing to the first element that is greater than key.
				iterator upper_bound( const Key& key );
				const_iterator upper_bound( const Key& key ) const;

				/* ========================================================== */
				/* --------------------- ELEMENT ACCESS --------------------- */
				/* ========================================================== */

				// Returns a reference to the mapped value of the element with key equivalent to key. If no such element exists, an exception of type std::out_of_range is thrown.
				T& at( const Key& key );
				const T& at( const Key& key ) const;

				// Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.
				T& operator[]( const Key& key )
				{
					nodePtr node = _tree.find_key(key);
					if (node != _tree.get_node_end()) return (node->second);
					else                              node = _tree.insert(key, 0); return node->second;
				}



		};

#define KTCA template< class Key, class T, class Compare, class Alloc >
#define _MAP  const ft::map  <Key,       T,       Compare,       Alloc >

	KTCA bool operator == ( _MAP & lhs, _MAP & rhs );
	KTCA bool operator != ( _MAP & lhs, _MAP & rhs );
	KTCA bool operator <  ( _MAP & lhs, _MAP & rhs );
	KTCA bool operator <= ( _MAP & lhs, _MAP & rhs );
	KTCA bool operator >  ( _MAP & lhs, _MAP & rhs );
	KTCA bool operator >= ( _MAP & lhs, _MAP & rhs );

	KTCA void swap(_MAP & lhs, _MAP & rhs );
}

#endif

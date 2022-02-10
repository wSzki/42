/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayT.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:41:48 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/10 20:59:37 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H__
#define __ARRAY_H__
#include "colors.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <exception>

template <typename T>
class Array
{
	public:

		Array  (void);
		Array  (unsigned int);
		~Array (void);
		Array  (Array const &obj);

		unsigned int size (void) const;

		Array & operator =  (Array    const &obj);
		T     & operator [] (unsigned int   index);

	private:
		T *_array;
		unsigned int _size;

	protected:

};

// DEFAULT
template <typename T>
Array<T>::Array (void) :
	_array (new T[0]),
	_size  (0)
{
	std::cout << GREEN "[Array] Default constructor called\n" << _R;
}

template <typename T>
Array<T>::Array (unsigned int size) :
	_array (new T[size]),
	_size  (size)
{
	std::cout << GREEN "[Array] Constructor called\n" << _R;
}

// COPY
template <typename T>
Array<T>::Array(Array const &obj) :
	_array (new T[obj._size]),
	_size  (obj._size)
{
	std::cout << GREEN "[Array] Copy constructor called\n" << _R;
	for (unsigned int i = 0; i < obj._size; i++)
		this->_array[i] = obj._array[i];
}

// OVERLOADS
	template <typename T>
Array<T> &Array<T>::operator = (Array const &obj)
{
	std::cout << GREEN "[Array] Assignation operator called" << _R << std::endl;
	if (this == &obj)
		return (*this);
	delete [] this->_array;
	this->_array = new T[obj.size()];
	this->_size= obj.size();
	for (unsigned int i = 0; i < obj._size; i++)
		this->_array[i] = obj._array[i];
	return (*this);
}

	template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::exception();
	return this->_array[index];
}

// METHODS
	template<typename T>
unsigned int Array<T>::size (void) const
{
	return (this->_size);
}

// DESTRUCTOR
	template <typename T>
Array<T>::~Array (void)
{
	std::cout << RED << "[Array] Destructor Called\n" <<  _R;
	delete [] this->_array; // TODO
}


#endif

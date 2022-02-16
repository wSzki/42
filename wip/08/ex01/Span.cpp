/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:05:57 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/16 03:05:10 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// CONSTRUCTORS
Span::Span  (unsigned int n) : max_len(n)
{
}

Span::Span  (Span const &obj) : max_len(obj.max_len)
{
	for (size_t i = 0; i < obj.max_len; i++)
		this->vector_int.push_back(obj.vector_int[i]);
	this->max_len = obj.max_len;
}

// OVERLOADS

Span &Span::operator = (Span const &obj)
{
	if (this == &obj)
		return *this;
	*this = Span(obj);
	return *this;
}

// METHODS
void Span::addNumber(int n)
{
	if (vector_int.size() + 1 > this->max_len)
		throw Span::fullException();
	this->vector_int.push_back(n);
}

size_t Span::longestSpan  (void) const
{
	int min = 0;
	int max = 0;
	std::vector<int> vector_int;

	vector_int = this->vector_int;
	if (vector_int.size() <= 1)
		throw Span::insufficientException();
	min = *min_element(vector_int.begin(), vector_int.end());
	max = *max_element(vector_int.begin(), vector_int.end());
	return max - min;
}

size_t Span::shortestSpan (void) const
{
	std::vector<int> vector_tmp(this->vector_int);

	if (vector_tmp.size() <= 1)
		throw Span::insufficientException();
	std::sort(vector_tmp.begin(), vector_tmp.end());
	vector_tmp.erase(std::unique(vector_tmp.begin(), vector_tmp.end()), vector_tmp.end());
	return (vector_tmp[1] - vector_tmp[0] - 1); // subject odes not make sense
}

void Span::fill_range(std::vector<int>::iterator b, std::vector<int>::iterator e, int max)
{
	while (b++ != e)
		*b = rand() % max;
}

void Span::fill(size_t n_elements, size_t max)
{
	int r;

	for (size_t i = 0; i < n_elements; i++)
	{
		r = (rand() % max) - max / 2;
		this->addNumber(r);
		std::cout << "Added number : " << r << std::endl;
	}
}

// EXCEPTIONS
const char *Span::fullException::what() const throw()
{
	return ("Vector is full");
}

const char *Span::insufficientException::what() const throw()
{
	return ("More than 1 element needed to find range");
}


// DESTRUCTOR
Span::~Span () {}

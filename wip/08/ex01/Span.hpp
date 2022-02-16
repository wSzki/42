/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:04:34 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/16 03:02:10 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
# define __SPAN_H__

# include <exception>
# include <iostream>
# include <cctype>
# include <vector>
# include <algorithm>

class Span
{
	public:

		Span  (unsigned int n);
		Span  (Span const &obj);
		~Span (void);

		Span &operator = (Span const &obj);
		//Span *operator [] (unsigned int index);

		void addNumber    (int n);
		size_t shortestSpan (void) const;
		size_t longestSpan  (void) const;

		void fill (size_t nbr, size_t max);
		void fill_range(std::vector<int>::iterator b, std::vector<int>::iterator e, int max);

        class fullException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

        class insufficientException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };




	private:
		Span  (void);
		std::vector<int> vector_int;
		size_t max_len;

	protected:

};


#endif

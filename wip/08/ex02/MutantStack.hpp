/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:11:15 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/17 16:19:57 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_H__
# define __MUTANTSTACK_H__
# include <iostream>
# include <cctype>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack  (void) {};
		~MutantStack (void) {};

		MutantStack  (MutantStack const &obj);
		MutantStack &operator = (MutantStack const &obj);

		typename std::stack<T>::container_type get_c(void) {return this->c;}

		typedef typename std::stack<T>::container_type::iterator I;
		I begin() {return this->c.begin();};
		I end()   {return this->c.end  ();};
		//typename std::stack<T>::container_type::iterator begin() {return this->c.begin();};
		//typename std::stack<T>::container_type::iterator end()   {return this->c.end  ();};

	private:

	protected:

};

#endif

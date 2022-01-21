/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:18:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/19 01:30:01 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__
#include <iostream>
#include <cctype>

class Bureaucrat
{
	public:

		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat (Bureaucrat const &obj);

		Bureaucrat &operator = (Bureaucrat const &obj);

		std::string getName  (void) const;
		int         getGrade (void) const;

		void promote (void);
		void demote  (void);

	private:
		std::string const name;
		int grade;

	protected:

};

std::ostream &operator << (std::ostream &os, const Bureaucrat &b);

#endif

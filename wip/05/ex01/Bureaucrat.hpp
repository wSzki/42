/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:18:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/22 15:01:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__
#include <exception>
#include <iostream>
#include <cctype>
#include <stdexcept>

class Bureaucrat;
#include "Form.hpp"
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

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		void promote (void);
		void demote  (void);
		void signForm(Form &form);

	private:
		std::string const name;
		int grade;

	protected:

};

std::ostream &operator << (std::ostream &os, const Bureaucrat &b);

#endif

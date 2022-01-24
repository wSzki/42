/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:51:03 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/24 22:59:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
#define __FORM_H__
#include <iostream>
#include <cctype>
#include <exception>

class Form;
#include "Bureaucrat.hpp"
class Form
{

	public:
	Form (void);
	Form(Form const &obj);
	~Form (void);
	Form(std::string name, int requiredGradeToExec, int requiredGradeToSign);
	Form &operator = (Form const &obj);
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char * what (void) const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char * what (void) const throw();
	};

	std::string getName                (void) const;
	bool        getSignedStatus        (void) const;
	int         getRequiredGradeToSign (void) const;
	int         getRequiredGradeToExec (void) const;

	void beSigned(Bureaucrat &guy);

	private:
	std::string name;
	bool signedStatus;
	int const requiredGradeToSign;
	int const requiredGradeToExec;

};


std::ostream & operator << (std::ostream &o, Form &obj);

#endif

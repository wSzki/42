/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:51:03 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/21 20:59:41 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
#define __FORM_H__
#include <iostream>
#include <cctype>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	class GradeTooLowException : public std::exception
	{
		virtual const char * what (void) throw();
	};

	public:
	Form (void);
	Form(Form const &obj);
	~Form (void);
	Form(std::string name, int requiredGradeToExec, int requiredGradeToSign);
	Form &operator = (Form const &obj);

	std::string getName                (void) const;
	bool        getSignedStatus        (void) const;
	int         getRequiredGradeToSign (void) const;
	int         getRequiredGradeToExec (void) const;

	void beSigned(Bureaucrat guy);

	private:
	std::string name;
	bool signedStatus;
	int const requiredGradeToExec;
	int const requiredGradeToSign;

};

#endif

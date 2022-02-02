/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:05:09 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/31 01:43:13 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
#define __INTERN_H__
#include <iostream>
#include <cctype>

#include "Form.hpp"

class Intern
{
	public:

	Intern  (void);
	~Intern (void);
	Intern  (Intern const &obj);

	Intern & operator = (Intern const &obj);
	Form * makeForm(std::string form_name, std::string target);

	class UnknownFormException : public std::exception
	{
		public:
		virtual const char * what() const throw();
	};

	private:
	std::string knowm_forms[3];
	Form * (*createForm[3])(std::string target);

	protected:

};


#endif

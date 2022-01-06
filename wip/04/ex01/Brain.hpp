/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:24:36 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/06 14:00:12 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
#define __BRAIN_H__
#include <iostream>
#include <cctype>

class Brain
{
	public:

		Brain(void);
		~Brain(void);
		Brain (Brain const &obj);

		Brain &operator = (Brain const &obj);
		std::string const getIdea(int) const;
		void setIdea(std::string str, int i);

	private:
		std::string ideas[100];

	protected:

};

#endif

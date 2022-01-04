/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:24:36 by wszurkow          #+#    #+#             */
/*   Updated: 2022/01/03 20:27:45 by wszurkow         ###   ########.fr       */
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
		std::string ideas[100];

	private:

	protected:

};

#endif

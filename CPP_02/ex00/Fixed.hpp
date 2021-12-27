/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:59:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/23 17:38:44 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__
#include <cctype>
#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		// TODO An assignation operator overload.

		Fixed &operator=(Fixed const &objectToCopy);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int rawBits;
		static int const fractionalBits = 8;

};

#endif

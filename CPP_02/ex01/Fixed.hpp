/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:59:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/27 14:50:44 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__
#include <cctype>
#include <iostream>
#include <cmath>

class          Fixed
{
	public:
		Fixed  (void);
		Fixed  (int   const n);
		Fixed  (float const n);
		Fixed  (Fixed const &src);
		~Fixed (void);

		Fixed &operator=(Fixed const &objectToCopy);

		int   getRawBits        (void) const;
		void  setRawBits        (int   const raw);
		float toFloat           (void) const;
		int   toInt             (void) const;

	private:
		int rawBits;
		static int const fractionalBits = 8;

};

std::ostream & operator<<(std::ostream &output, Fixed const &src);

#endif

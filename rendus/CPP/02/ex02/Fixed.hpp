/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:59:01 by wszurkow          #+#    #+#             */
/*   Updated: 2021/12/28 14:27:36 by wsz              ###   ########.fr       */
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
		~Fixed (void);
		Fixed  (int   const n);
		Fixed  (float const n);
		Fixed  (Fixed const &src);

		Fixed &operator =  (Fixed const &rhs);

		bool operator >  (Fixed const &rhs)	const;
		bool operator <  (Fixed const &rhs)	const;
		bool operator >= (Fixed const &rhs)	const;
		bool operator <= (Fixed const &rhs)	const;
		bool operator == (Fixed const &rhs)	const;
		bool operator != (Fixed const &rhs)	const;

		Fixed operator * (Fixed const &rhs);
		Fixed operator + (Fixed const &rhs);
		Fixed operator - (Fixed const &rhs);
		Fixed operator / (Fixed const &rhs);

		Fixed operator ++ (void);
		Fixed operator ++ (int);
		Fixed operator -- (void);
		Fixed operator -- (int);

		int   getRawBits        (void) const;
		void  setRawBits        (int   const raw);
		float toFloat           (void) const;
		int   toInt             (void) const;

		static Fixed &min(Fixed &lhs, Fixed &rhs);
		static Fixed &max(Fixed &lhs, Fixed &rhs);

		static Fixed const &min(Fixed const &lhs, Fixed const &rhs);
		static Fixed const &max(Fixed const &lhs, Fixed const &rhs);

	private:

		int rawBits;
		static int const fractionalBits = 8;

};

std::ostream &operator << (std::ostream &output, Fixed const &src);

Fixed &min(Fixed &lhs, Fixed &rhs);
Fixed &max(Fixed &lhs, Fixed &rhs);

Fixed const &min(Fixed const &lhs, Fixed const &rhs);
Fixed const &max(Fixed const &lhs, Fixed const &rhs);

#endif

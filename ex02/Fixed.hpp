/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:37:02 by marvin            #+#    #+#             */
/*   Updated: 2026/06/30 17:37:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	value;
		static const int fp = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator>(const Fixed& f)const;
		bool	operator<(const Fixed& f)const;
		bool	operator>=(const Fixed& f)const;
		bool	operator<=(const Fixed& f)const;
		bool	operator==(const Fixed& f)const;
		bool	operator!=(const Fixed& f)const;

		Fixed	operator+(const Fixed& f)const;
		Fixed	operator-(const Fixed& f)const;
		Fixed	operator*(const Fixed& f)const;
		Fixed	operator/(const Fixed& f)const;

		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed&	operator++();
		Fixed&	operator--();

		static const Fixed& min(const Fixed& f1, const Fixed& f2);
		static Fixed& min( Fixed& f1, Fixed& f2);
		static Fixed& max( Fixed& f1, Fixed& f2);
		static const Fixed& max(const Fixed& f1, const Fixed& f2);


};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
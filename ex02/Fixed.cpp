/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:36:47 by marvin            #+#    #+#             */
/*   Updated: 2026/06/30 17:36:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int i)
{
	value = i << fp;
}

Fixed::Fixed(const float f)
{
	value = roundf(f * (1 << fp));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& f):value(f.value)
{
}

Fixed& Fixed::operator=(const Fixed& f)
{
	if (this != &f)
	{
		value = f.value;
	}
	return *this;
}

int		Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(const int raw)
{
	value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)(value) / (1 << fp));
}

int	Fixed::toInt( void ) const
{
	return value >> fp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed& f)const
{
	if (this->value > f.value)
		return true;
	return false;
}
bool	Fixed::operator<(const Fixed& f)const
{
	if (this->value < f.value)
		return true;
	return false;
}
bool	Fixed::operator>=(const Fixed& f)const
{
	if (this->value >= f.value)
		return true;
	return false;
}
bool	Fixed::operator<=(const Fixed& f)const
{
	if (this->value <= f.value)
		return true;
	return false;
}
bool	Fixed::operator==(const Fixed& f)const
{
	if (this->value == f.value)
		return true;
	return false;
}
bool	Fixed::operator!=(const Fixed& f)const
{
	if (this->value != f.value)
		return true;
	return false;
}
Fixed	Fixed::operator+(const Fixed& f)const
{
	Fixed temp;
	temp.value = this->value + f.value;
	return temp;
}
Fixed	Fixed::operator-(const Fixed& f)const
{
	Fixed temp;
	temp.value = this->value - f.value;
	return temp;
}
Fixed	Fixed::operator*(const Fixed& f)const
{
	Fixed temp;
	temp.value = (this->value * f.value) / (1 << fp);
	return temp;
}
Fixed	Fixed::operator/(const Fixed& f)const
{
	Fixed temp;
	temp.value = (this->value * (1 << fp)) / f.value;
	return temp;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value++;
	return temp;
}
Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value--;
	return temp;
}
Fixed&	Fixed::operator++()
{
	this->value++;
	return *this;
}
Fixed&	Fixed::operator--()
{
	this->value--;
	return *this;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if(f1.value > f2.value)
		return f2;
	return f1;
}
const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if(f1.value > f2.value)
		return f1;
	return f2;
}
Fixed& Fixed::min( Fixed& f1, Fixed& f2)
{
	if(f1.value > f2.value)
		return f2;
	return f1;
}
Fixed& Fixed::max( Fixed& f1, Fixed& f2)
{
	if(f1.value > f2.value)
		return f1;
	return f2;
}

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

class Fixed
{
	private:
		int	value;
		static const int fb = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
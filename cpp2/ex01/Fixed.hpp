/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:00:17 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/11 12:39:04 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int	_fixed_point;
		static const int _fract_bit = 8;
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();

		// Copy Constructor
		Fixed(const Fixed& copy);

		// Copy overload assignements
		Fixed& operator= (const Fixed& fixed);
		Fixed& operator<< (const Fixed& fixed);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream & operator << (std::ostream &out, const Fixed &c);

#endif

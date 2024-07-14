/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:00:17 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/14 14:06:06 by alexafer         ###   ########.fr       */
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
		

		Fixed  operator+ (const Fixed& fixed) const;
		Fixed  operator- (const Fixed& fixed) const;
		Fixed  operator* (const Fixed& fixed) const;
		Fixed  operator/ (const Fixed& fixed) const;
		
		bool   operator> (const Fixed& fixed) const;
		bool   operator< (const Fixed& fixed) const;
		bool   operator>= (const Fixed& fixed) const;
		bool   operator<= (const Fixed& fixed) const;
		bool   operator== (const Fixed& fixed) const;
		bool   operator!= (const Fixed& fixed) const;

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
	
		static Fixed&	min(Fixed& one, Fixed& two);	
		static const Fixed&	min(const Fixed& one, const Fixed& two);	
		static Fixed&	max(Fixed& one, Fixed& two);	
		static const Fixed&	max(const Fixed& one, const Fixed& two);	
		float	toFloat(void) const;
		int		toInt(void) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream & operator << (std::ostream &out, const Fixed &c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:00:17 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/11 12:49:29 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	this->_fixed_point = val << this->_fract_bit;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
	this->_fixed_point = roundf(val * (1 << this->_fract_bit));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());
	return (*this);
}

std::ostream& operator<< (std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return (out);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_point >> this->_fract_bit);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point / (float)(1 << this->_fract_bit));
}

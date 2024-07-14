/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:00:17 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/14 14:04:23 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->setRawBits(0);
}

Fixed::Fixed(const int val)
{
	this->_fixed_point = val << this->_fract_bit;
}

Fixed::Fixed(const float val)
{
	this->_fixed_point = roundf(val * (1 << this->_fract_bit));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed Fixed::operator+ (const Fixed& fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator- (const Fixed& fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator* (const Fixed& fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/ (const Fixed& fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

bool Fixed::operator> (const Fixed& fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator< (const Fixed& fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>= (const Fixed& fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<= (const Fixed& fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator== (const Fixed& fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!= (const Fixed& fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed& Fixed::operator++ (void)
{
	++this->_fixed_point;
	return (*this);
}

Fixed& Fixed::operator-- (void)
{
	--this->_fixed_point;
	return (*this);
}


Fixed Fixed::operator++ (int)
{
	Fixed fix(*this);
	fix._fixed_point = this->_fixed_point++;
	return (fix);
}

Fixed Fixed::operator-- (int)
{
	Fixed fix(*this);
	fix._fixed_point = this->_fixed_point--;
	return (fix);
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

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
	if (one.getRawBits() > two.getRawBits())
		return (two);
	return (one);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one.getRawBits() > two.getRawBits())
		return (two);
	return (one);
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
	if (one.getRawBits() > two.getRawBits())
		return (one);
	return (two);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one.getRawBits() > two.getRawBits())
		return (one);
	return (two);
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

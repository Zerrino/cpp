/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:42:41 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/27 15:49:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N)
	: _N(N), _I(0)
{
}

void	Span::addNumber(int number)
{
	if (this->_I++ < this->_N)
		this->_numbers.push_back(number);
	else
		throw std::length_error("no place left");
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}

int		Span::shortestSpan()
{
	std::vector<int>::iterator n;
	int	val;
	int	min;

	std::sort(this->_numbers.begin(), this->_numbers.end());

	min = *(this->_numbers.end() - 1);
	for (std::vector<int>::iterator i = this->_numbers.begin(); (i + 1) != this->_numbers.end(); ++i)
	{
		n = i + 1;
		val = *n - *i;
		if (val < min)
			min = val;
	}
	return (min);
}

int		Span::longestSpan()
{
	int	max;
	int	min;

	std::sort(this->_numbers.begin(), this->_numbers.end());

	min = *(this->_numbers.begin());
	max = *(this->_numbers.end() - 1);
	return (max - min);
}


Span::~Span()
{
}

Span::Span(const Span& cp)
	: _N(cp._N), _I(cp._N), _numbers(cp._numbers)
{
	*this = cp;
}

Span& Span::operator= (const Span& cp)
{
	if (this != &cp)
	{
		this->_N = cp._N;
		this->_I = cp._I;
		this->_numbers = cp._numbers;
	}
	return (*this);
}

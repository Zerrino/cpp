/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:48:01 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 02:12:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& cp)
{
	*this = cp;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}


void ScalarConverter::fromChar(const std::string &literal)
{
}

void ScalarConverter::fromInt(const std::string &literal)
{

}

void ScalarConverter::fromDouble(const std::string &literal)
{

}

void ScalarConverter::fromFloat(const std::string &literal)
{

}

void ScalarConverter::fromLiteral(const std::string &literal)
{

}

int	ScalarConverter::detectType(const std::string &literal)
{
	if (!literal.length())
		return TYPE_UNKNOWN;
	if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
		return TYPE_LITERAL;
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return TYPE_CHAR;
	{
		char	*endPtr = 0;
		long	longValue;

		errno = 0;
		longValue = std::strtol(literal.c_str(), &endPtr, 10);
		if (errno == 0 && *endPtr == '\0' && longValue >= INT_MAX && longValue <= longValue)
			return TYPE_INT;
	}
	if (literal.find('f') != std::string::npos)
	{
		char	*endPtr = 0;
		float	floatValue;

		errno = 0;
		floatValue = std::strtof(literal.c_str(), &endPtr);
		if (errno == 0 && *endPtr == 'f' && *(endPtr + 1) == '\0')
			return TYPE_FLOAT;
	}
	{
		char	*endPtr = 0;
		double	doubleValue;

		errno = 0;
		doubleValue = std::strtod(literal.c_str(), &endPtr);
		if (errno == 0 && *endPtr == '\0')
			return TYPE_DOUBLE;
	}

	return TYPE_UNKNOWN;
}


void ScalarConverter::converter(const std::string &literal)
{
	ScalarConverter conv;
	int	type;

	type = conv.detectType(literal);

	std::cout << type << std::endl;

	switch (type)
	{
	case TYPE_CHAR:
		conv.fromChar(literal);
		break;
	case TYPE_INT:
		conv.fromInt(literal);
		break;
	case TYPE_FLOAT:
		conv.fromFloat(literal);
		break;
	case TYPE_DOUBLE:
		conv.fromDouble(literal);
		break;
	case TYPE_LITERAL:
		conv.fromLiteral(literal);
		break;
	default:
		std::cout << "Conversion impossible" << std::endl;
		break;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:48:01 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 16:15:12 by marvin           ###   ########.fr       */
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
	char	value = literal[0];

	if (std::isprint(static_cast<unsigned char>(value)))
		std::cout << "char: '" << value << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::fromInt(const std::string &literal)
{
	long	intValue = std::strtol(literal.c_str(), NULL, 10);

	if (intValue >= CHAR_MIN && intValue <= CHAR_MAX)
	{
		char charValue = intValue;
		if (std::isprint(static_cast<unsigned char>(charValue)))
			std::cout << "char: '" << charValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
}

void ScalarConverter::fromDouble(const std::string &literal)
{
	double	doubleValue = std::strtod(literal.c_str(), NULL);
	float	floatValue = static_cast<float>(doubleValue);
	double	douP;
	float	floP;

	if (doubleValue >= CHAR_MIN && doubleValue <= CHAR_MAX)
	{
		char charValue = static_cast<int>(doubleValue);
		if (std::isprint(static_cast<unsigned char>(charValue)))
			std::cout << "char: '" << charValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;

	if (std::modf(floatValue, &floP))
		std::cout << "float: " << floatValue << "f" << std::endl;
	else
		std::cout << "float: " << floatValue << ".0f" << std::endl;
	if (std::modf(doubleValue, &douP))
		std::cout << "double: " << (doubleValue) << std::endl;
	else
		std::cout << "double: " << (doubleValue) << ".0" << std::endl;
}

void ScalarConverter::fromFloat(const std::string &literal)
{
	float	floatValue = std::strtof(literal.c_str(), NULL);;
	double	doubleValue = std::strtod(literal.c_str(), NULL);
	double	douP;
	float	floP;

	if (floatValue >= CHAR_MIN && floatValue <= CHAR_MAX)
	{
		char charValue = static_cast<int>(floatValue);
		if (std::isprint(static_cast<unsigned char>(charValue)))
			std::cout << "char: '" << charValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
	if (std::modf(floatValue, &floP))
		std::cout << "float: " << floatValue << "f" << std::endl;
	else
		std::cout << "float: " << floatValue << ".0f" << std::endl;
	if (std::modf(doubleValue, &douP))
		std::cout << "double: " << (doubleValue) << std::endl;
	else
		std::cout << "double: " << (doubleValue) << ".0" << std::endl;
}

void ScalarConverter::fromLiteral(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "float: +inff" << std::endl;
	else if (literal == "-inf" || literal == "-inff")
		std::cout << "float: -inff" << std::endl;

	if (literal == "nan" || literal == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "double: +inf" << std::endl;
	else if (literal == "-inf" || literal == "-inff")
		std::cout << "double: -inf" << std::endl;
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
		char	*ptr = 0;
		long	longValue;

		errno = 0;
		longValue = std::strtol(literal.c_str(), &ptr, 10);
		if (errno == 0 && *ptr == '\0' && longValue <= INT_MAX && longValue >= INT_MIN)
			return TYPE_INT;
	}
	if (literal.find('f') != std::string::npos)
	{
		char	*ptr = 0;
		float	floatValue;

		errno = 0;
		floatValue = std::strtof(literal.c_str(), &ptr);
		if (errno == 0 && *ptr == 'f' && *(ptr + 1) == '\0')
			return TYPE_FLOAT;
	}
	{
		char	*ptr = 0;
		double	doubleValue;

		errno = 0;
		doubleValue = std::strtod(literal.c_str(), &ptr);
		if (errno == 0 && *ptr == '\0')
			return TYPE_DOUBLE;
	}

	return TYPE_UNKNOWN;
}


void ScalarConverter::converter(const std::string &literal)
{
	ScalarConverter conv;
	int	type;

	type = conv.detectType(literal);
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:48:01 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 12:09:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <cctype>
# include <cerrno>
# include <climits>
# include <float.h>

# define TYPE_CHAR 0
# define TYPE_INT 1
# define TYPE_FLOAT 2
# define TYPE_DOUBLE 3
# define TYPE_LITERAL 4
# define TYPE_UNKNOWN -1


class	ScalarConverter
{
	private:
		char	_char;
		int		_int;
		float	_float;
		double	_double;
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &cp);
		ScalarConverter& operator= (const ScalarConverter &cp);

		int		detectType(const std::string &literal);
		static void converter(const std::string &literal);
		void	fromChar(const std::string &literal);
		void	fromInt(const std::string &literal);
		void	fromFloat(const std::string &literal);
		void	fromDouble(const std::string &literal);
		void	fromLiteral(const std::string &literal);

};

#endif

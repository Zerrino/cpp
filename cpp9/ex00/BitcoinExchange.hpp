/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:36:59 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/07 16:15:52 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# define TYPE_UNKNOW 0
# define TYPE_INT 1
# define TYPE_FLOAT 2
# define TYPE_DOUBLE 3
struct Date
{
	int	year;
	int	month;
	int	day;
};


class	BitcoinExchange
{
	private:
		std::string	_data_path;
		std::string	_data_inpu;
		std::string	_file_path;
		std::string	_file_inpu;
		std::map<int, double> _map_inpu;
		std::map<int, double> _map_data;
		int		_key;
		double	_val;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cp);
		BitcoinExchange& operator= (const BitcoinExchange &cp);

		void	execute(void);
		void	verifyFormat(void);
		void	verifyFormatData(void);
		void	trimSpace(std::string &str);
		void	verifyDate(Date date, std::string date_str);
		void	BitcoinPath(std::string data_inpu);
		void	extractBoth(std::string both_str);
		void	extractBothData(std::string both_str);
		int		extractDate(std::string date);
		double	extractValue(std::string value_str);
		bool	isDigit(std::string& str);
		int		detectType(const std::string &literal);
		std::string	returnFile(std::string path);
};

#endif

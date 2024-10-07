/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:36:59 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/07 16:43:45 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	: _data_path("./data.csv")
{
}

void BitcoinExchange::BitcoinPath(std::string data_inpu)
{
	this->_data_inpu = data_inpu;
	std::cout << "data_input : " << _data_inpu << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cp)
{
	*this = cp;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}

std::string	BitcoinExchange::returnFile(std::string path)
{
	std::ifstream	file(path);
	std::string		error;
	std::string		val;
	std::string		text;

	error = path + " cannot be opened";
	if (!file.is_open())
		throw std::domain_error(error);
	text = "";
	while (std::getline(file, val, '\0'))
	{
		text.insert(text.length(), val);
	}
	return (text);
}

void	BitcoinExchange::verifyFormat(void)
{
	std::ifstream	file(this->_data_inpu);
	std::string		val;
	std::string		vax;
	int				i;

	i = 0;
	while (std::getline(file, val, '\n'))
	{
		if (i == 0 && val != "date | value")
			throw std::logic_error("format error");

		if (i)
		{
			try
			{
				this->extractBoth(val);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		i++;
	}
	if (i == 0)
		throw std::logic_error("format error");
}

void	BitcoinExchange::verifyFormatData(void)
{
	std::ifstream	file(this->_data_path);
	std::string		val;
	std::string		vax;
	int				i;

	i = 0;
	while (std::getline(file, val, '\n'))
	{
		if (i == 0 && val != "date,exchange_rate")
			throw std::logic_error("format error");

		if (i)
		{
			try
			{
				this->extractBothData(val);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		i++;
	}
	if (i == 0)
		throw std::logic_error("format error");
}

// January 1, 1970

void		BitcoinExchange::extractBothData(std::string both_str)
{
	//int	finded;
	std::string	date;
	std::string	value;
	int			key;
	double		val;

	//finded = both_str.find('|');
	if (both_str.find(',') == std::string::npos)
		throw std::out_of_range("format error");

	date = both_str;
	date.resize(both_str.find(','));
	value.insert(0, both_str, both_str.find(',') + 1);

	this->trimSpace(date);
	this->trimSpace(value);
	key = this->extractDate(date);
	val = this->extractValue(value);
	this->_map_data[key] = val;
}

void		BitcoinExchange::extractBoth(std::string both_str)
{
	double		finded;
	std::map<int, double>::iterator it;
	std::string	date;
	std::string	value;

	//finded = both_str.find('|');
	if (both_str.find('|') == std::string::npos)
		throw std::out_of_range("format error");

	date = both_str;
	date.resize(both_str.find('|'));
	value.insert(0, both_str, both_str.find('|') + 1);

	this->trimSpace(date);
	this->trimSpace(value);
	this->_key = this->extractDate(date);
	this->_val = this->extractValue(value);
	if (this->_val < 0 || this->_val > 1000)
		throw std::out_of_range("value error: =>'" + value + "'");
	this->_map_inpu[this->_key] = this->_val;


	it = this->_map_data.lower_bound(this->_key);
	if (it != this->_map_data.begin() && (it == this->_map_data.end() || it->first > this->_key))
		--it;
	if (it == this->_map_data.begin())
		throw std::out_of_range("error: bitcoin didnt exist in => " + date);
	finded = (*(it)).second;
	std::cout << date << " => " << value <<  " = " << (finded * this->_val) << std::endl;
}

double		BitcoinExchange::extractValue(std::string value_str)
{
	double	val;
	int	type;

	type = this->detectType(value_str);
	switch (type)
	{
	case TYPE_UNKNOW:
		throw std::out_of_range("value error: unknow type =>'" + value_str + "'");
		break;
	case TYPE_INT:
		val = static_cast<double>(std::strtol(value_str.c_str(), NULL, 10));
		break;
	case TYPE_FLOAT:
		val = std::strtod(value_str.c_str(), NULL);
		break;
	case TYPE_DOUBLE:
		val = std::strtod(value_str.c_str(), NULL);
		break;
	default:
		throw std::out_of_range("value error: =>'" + value_str + "'");
		break;
	}
	return (val);
}

void	BitcoinExchange::trimSpace(std::string &str)
{
	std::string new_str;

	while (*(str.end() - 1) == ' ' && (str.end() - 1 != str.begin()))
	{
		str.resize(str.length() - 1);
	}
	while (*(str.begin()) == ' ' && (str.end() != str.begin()))
	{
		str.erase(0, 1);
	}
	new_str = str;
	str = new_str;
}

bool		BitcoinExchange::isDigit(std::string& str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return (!str.empty());
}

void		BitcoinExchange::verifyDate(Date date, std::string date_str)
{
	int day_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (date.year < 1 || date.year > 100000)
		throw std::out_of_range("date error: year =>'" + date_str + "'");
	if (date.month < 1 || date.month > 12)
		throw std::out_of_range("date error: month =>'" + date_str + "'");
	if (date.month == 2 && ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)))
		day_month[2] = 29;
	if (date.day < 1 || date.day > day_month[date.month])
		throw std::out_of_range("date error: day =>'" + date_str + "'");
}

int		BitcoinExchange::extractDate(std::string date_str)
{
	Date		date;
	std::string	year;
	std::string	month;
	std::string	day;
	std::size_t	pos;

	year = date_str;
	pos = date_str.find("-");
	if (pos == std::string::npos)
		throw std::out_of_range("date error: y-m-d format =>'" + date_str + "'");
	year.resize(date_str.find("-"));
	month.insert(0, date_str, date_str.find('-') + 1);
	pos = month.find("-");
	if (pos == std::string::npos)
		throw std::out_of_range("date error: y-m-d format =>'" + date_str + "'");
	day.insert(0, month, month.find('-') + 1);
	month.resize(month.find("-"));
	if (*(day.end() - 1) == ' ')
		day.resize(day.length() - 1);
	if (year.empty() || month.empty() || day.empty())
		throw std::out_of_range("date error: is empty =>'" + date_str + "'");
	if (!this->isDigit(year) || !this->isDigit(month) || !this->isDigit(day))
		throw std::out_of_range("date error: is numeric =>'" + date_str + "'");
	date.year = std::atoi(year.c_str());
	date.month = std::atoi(month.c_str());
	date.day = std::atoi(day.c_str());
	this->verifyDate(date, date_str);
	return (date.year * 10000 + date.month * 100 + date.day);
}

int	BitcoinExchange::detectType(const std::string &literal)
{
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

		errno = 0;
		std::strtof(literal.c_str(), &ptr);
		if (errno == 0 && *ptr == 'f' && *(ptr + 1) == '\0')
			return TYPE_FLOAT;
	}
	{
		char	*ptr = 0;

		errno = 0;
		std::strtod(literal.c_str(), &ptr);
		if (errno == 0 && *ptr == '\0')
			return TYPE_DOUBLE;
	}
	return TYPE_UNKNOW;
}

void	BitcoinExchange::execute(void)
{
	this->_file_inpu = returnFile(this->_data_inpu);
	this->_file_path = returnFile(this->_data_path);
	this->verifyFormatData();
	this->verifyFormat();
}
